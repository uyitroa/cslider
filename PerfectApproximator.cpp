//
// Created by yuitora . on 01/08/2020.
//

#define pi 3.14159265358979323846

#include <cmath>
#include "PerfectApproximator.h"

PerfectApproximator::PerfectApproximator(list_vector &control_points) {
    this->control_points = control_points;
}

void PerfectApproximator::circle_through_points(Vector2<float> &centre, float &radius,
                                                double &t_initial, double &t_final) {
    // Circle through 3 points
    // http://en.wikipedia.org/wiki/Circumscribed_circle#Cartesian_coordinates

    Vector2<float> a = this->control_points[0];
    Vector2<float> b = this->control_points[1];
    Vector2<float> c = this->control_points[2];

    float d = 2 * (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
    float amagsq = a.length_squared();
    float bmagsq = b.length_squared();
    float cmagsq = c.length_squared();
    centre = Vector2<float>(
        (amagsq * (b.y - c.y) + bmagsq * (c.y - a.y) + cmagsq * (a.y - b.y)) / d,
        (amagsq * (c.x - b.x) + bmagsq * (a.x - c.x) + cmagsq * (b.x - a.x)) / d);
    radius = a.distance_from(centre);

    t_initial = circle_t_at(a, centre);
    double t_mid = circle_t_at(b, centre);
    t_final = circle_t_at(c, centre);

    while (t_mid < t_initial) t_mid += 2 * pi;
    while (t_final < t_initial) t_final += 2 * pi;
    if (t_mid > t_final)
    {
        t_final -= 2 * pi;
    }
}

double PerfectApproximator::circle_t_at(Vector2<float> pt, Vector2<float> centre) {
    return atan2(pt.y - centre.y, pt.x - centre.x);
}

Vector2<float> PerfectApproximator::circle_point(Vector2<float> centre, float radius, double t) {
    return Vector2<float>((float)(cos(t) * radius), (float)(sin(t) * radius)) + centre;
}

list_pos PerfectApproximator::create() {
    list_pos output;

    Vector2<float> centre;
    float radius;
    double t_initial, t_final;

    this->circle_through_points(centre, radius, t_initial, t_final);

    double curve_length = abs((t_final - t_initial) * radius);
    int _segments = (int)(curve_length * TOLERANCE);

//    Vector2<float> last_point = this->control_points[0];
    this->control_points[0].add_to_output(output);

    for (int i = 1; i < _segments; i++)
    {
        double progress = (double)i / (double)_segments;
        double t = t_final * progress + t_initial * (1 - progress);

        Vector2<float> new_point = this->circle_point(centre, radius, t);
        new_point.add_to_output(output);

//        lastPoint = newPoint;
    }

//    path.Add(new Line(lastPoint, c));
    this->control_points[2].add_to_output(output);

    return output;

}
