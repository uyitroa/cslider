//
// Created by yuitora . on 01/08/2020.
//

#ifndef BEZIER_PERFECTAPPROXIMATOR_H
#define BEZIER_PERFECTAPPROXIMATOR_H
#define list_pos std::vector<std::vector<float> >

#include "Vector2.h"
#include <iostream>
#include <vector>

class PerfectApproximator {
private:
    std::vector<Vector2<float> > control_points;
public:
    const float TOLERANCE = 0.125f;

    explicit PerfectApproximator(std::vector<Vector2<float> > &control_points);
    void circle_through_points(Vector2<float> &centre, float &radius, double &t_initial, double &t_final);
    double circle_t_at(Vector2<float> pt, Vector2<float> centre);
    Vector2<float> circle_point(Vector2<float> centre, float radius, double t);
    list_pos create();
};


#endif //BEZIER_PERFECTAPPROXIMATOR_H
