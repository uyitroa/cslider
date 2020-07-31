//
// Created by yuitora . on 31/07/2020.
//

#ifndef BEZIER_BEZIERAPPROXIMATOR_H
#define BEZIER_BEZIERAPPROXIMATOR_H
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

    BezierApproximator(std::vector<Vector2<double> > control_points, int count);
    bool is_flat_enough(std::vector<Vector2<double> > control_points);
    void subdivide(std::vector<Vector2<double> > controlPoints, std::vector<Vector2<double> > l, std::vector<Vector2<double> > r);
    void approximate(std::vector<Vector2<double> > control_points, PyObject *output);
    void create_bezier(PyObject *output);
};


#endif //BEZIER_BEZIERAPPROXIMATOR_H
