#include <iostream>
#include <vector>
#include <cmath>
#include "curves.h"

//void printpos(list_pos &output) {
//    printf("%d\n", output.size());
//    for(int x = 0; x < output.size(); x++) {
//        printf("%f %f\n", output[x][0], output[x][1]);
//    }
//}
//
//
//int main() {
//
////    list_vector control_points = {Vector2<float>(306, 222), Vector2<float>(303, 149), Vector2<float>(303, 149), Vector2<float>(361, 207), Vector2<float>(372, 277), Vector2<float>(372, 277), Vector2<float>(401, 271), Vector2<float>(401, 271), Vector2<float>(413, 339), Vector2<float>(460, 375), Vector2<float>(460, 375), Vector2<float>(514, 306), Vector2<float>(482, 209), Vector2<float>(428, 191), Vector2<float>(428, 191), Vector2<float>(454, 129), Vector2<float>(454, 129), Vector2<float>(403, 88), Vector2<float>(355, 87), Vector2<float>(355, 87), Vector2<float>(368, 38), Vector2<float>(368, 38), Vector2<float>(278, 66), Vector2<float>(156, 53), Vector2<float>(82, 11)};
//    list_vector control_points = {Vector2<float>(302, 117), Vector2<float>(352, 222)};
//
////    CatmullApproximator b(control_points);
//    list_pos output;
//    create_linear(output, control_points);
//    printpos(output);
//    return 0;
//}


bool is_straight_line(list_vector control_points) {
    Vector2<float> a = control_points[0];
    Vector2<float> b = control_points[1];
    Vector2<float> c = control_points[2];
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y) == 0.0f;
}

list_pos get_bezier(list_pos &control_points) {
    list_vector cp(control_points.size());
    list_pos output;
    for (int i = 0; i < control_points.size(); i++) {
        cp[i] = Vector2<float>(control_points[i][0], control_points[i][1]);
    }

    create_bezier(output, cp);
    return output;
}

list_pos get_perfect(list_pos &control_points) {
    list_vector cp(control_points.size());
    list_pos output;
    for (int i = 0; i < control_points.size(); i++) {
        cp[i] = Vector2<float>(control_points[i][0], control_points[i][1]);
    }
    if(is_straight_line(cp) || cp.size() < 3)
        create_linear(output, cp);
    else if(cp.size() > 3)
        create_bezier(output, cp);
    else
        create_perfect(output, cp);
    return output;
}

list_pos get_linear(list_pos &control_points) {
    list_vector cp(control_points.size());
    list_pos output;
    for (int i = 0; i < control_points.size(); i++) {
        cp[i] = Vector2<float>(control_points[i][0], control_points[i][1]);
    }

    create_linear(output, cp);
    return output;
}

list_pos get_catmull(list_pos &control_points) {
    list_vector cp(control_points.size());
    list_pos output;
    for (int i = 0; i < control_points.size(); i++) {
        cp[i] = Vector2<float>(control_points[i][0], control_points[i][1]);
    }

    create_catmull(output, cp);
    return output;
}

double distance(std::vector<float> a, std::vector<float> b) {
    return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
}

Vector2<float> normalize(Vector2<float> value) {
    double val = 1.0f / (double)sqrt((value.x * value.x) + (value.y * value.y));
    printf("%f %0.2f %0.2f\n", val, value.x, value.y);
    value.x *= val;
    value.y *= val;
    return value;
}


void adjust_curve(list_pos &path, double expected_length) {
    const double MIN_SEGMENT_LENGTH = 0.0001;
    double total = 0;
    for (int i = 1; i < path.size(); i++)
        total += distance(path[i-1], path[i]);

    double excess = total - expected_length;
    while (path.size() >= 2) {
        Vector2<float> v2(path[path.size() - 1][0], path[path.size() - 1][1]);
        Vector2<float> v1(path[path.size() - 2][0], path[path.size() - 2][1]);

        float last_line_length = v1.distance_from(v2);

        if (last_line_length > excess + MIN_SEGMENT_LENGTH) {
            if (v2 != v1) {
                printf("%0.2f %0.2f %0.2f %0.2f\n", v2.x, v2.y, v1.x, v1.y);
                Vector2<float> what = normalize(v2 - v1);
                printf("%0.2f %0.2f %0.2f\n", what.x, what.y, (v2 - v1).length() - (float)excess);
                Vector2<float> l = v1 + normalize(v2 - v1) * ((v2 - v1).length() - (float)excess);
                path[path.size() - 1][0] = l.x;
                path[path.size() - 1][1] = l.y;
            }
            break;
        }
        path.pop_back();
        excess -= last_line_length;
    }
}