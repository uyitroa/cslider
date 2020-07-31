//
// Created by yuitora . on 31/07/2020.
//

#ifndef BEZIER_BEZIERAPPROXIMATOR_H
#define BEZIER_BEZIERAPPROXIMATOR_H
#define list_pos std::vector<std::vector<double> >

#include <Python.h>
#include "Vector2.h"
#include <iostream>
#include <vector>

class BezierApproximator {
private:
    std::vector<Vector2<double> > control_points;
    std::vector<Vector2<double> > subdivision_buffer1;
    std::vector<Vector2<double> > subdivision_buffer2;
    int count;
public:
    const float TOLERANCE = 0.5f;
    const float TOLERANCE_SQ = TOLERANCE * TOLERANCE;

    explicit BezierApproximator(std::vector<Vector2<double> > &control_points);
    bool is_flat_enough(std::vector<Vector2<double> > &control_points);
    void subdivide(std::vector<Vector2<double> > &controlPoints, std::vector<Vector2<double> > &l, std::vector<Vector2<double> > &r);
    void approximate(std::vector<Vector2<double> > &control_points, list_pos &output);
    list_pos create_bezier();
};


#endif //BEZIER_BEZIERAPPROXIMATOR_H
