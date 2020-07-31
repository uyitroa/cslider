//
// Created by yuitora . on 31/07/2020.
//

#ifndef BEZIER_BEZIERAPPROXIMATOR_H
#define BEZIER_BEZIERAPPROXIMATOR_H
#define list_pos std::vector<std::vector<float> >
#define list_vector std::vector<Vector2<float> >

#include "Vector2.h"
#include <iostream>
#include <vector>

class BezierApproximator {
private:
    list_vector control_points;
    list_vector subdivision_buffer1;
    list_vector subdivision_buffer2;
    int count;
public:
    const float TOLERANCE = 0.5f;
    const float TOLERANCE_SQ = TOLERANCE * TOLERANCE;

    explicit BezierApproximator(list_vector &control_points);
    bool is_flat_enough(list_vector &control_points);
    void subdivide(list_vector &controlPoints, list_vector &l, list_vector &r);
    void approximate(list_vector &control_points, list_pos &output);
    list_pos create_bezier();
    list_pos create();
};


#endif //BEZIER_BEZIERAPPROXIMATOR_H
