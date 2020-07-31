//
// Created by yuitora . on 31/07/2020.
//

#ifndef BEZIER_BEZIERAPPROXIMATOR_H
#define BEZIER_BEZIERAPPROXIMATOR_H
#define list_pos std::vector<std::vector<float> >

#include "Vector2.h"
#include <iostream>
#include <vector>

class BezierApproximator {
private:
    std::vector<Vector2<float> > control_points;
    std::vector<Vector2<float> > subdivision_buffer1;
    std::vector<Vector2<float> > subdivision_buffer2;
    int count;
public:
    const float TOLERANCE = 0.5f;
    const float TOLERANCE_SQ = TOLERANCE * TOLERANCE;

    explicit BezierApproximator(std::vector<Vector2<float> > &control_points);
    bool is_flat_enough(std::vector<Vector2<float> > &control_points);
    void subdivide(std::vector<Vector2<float> > &controlPoints, std::vector<Vector2<float> > &l, std::vector<Vector2<float> > &r);
    void approximate(std::vector<Vector2<float> > &control_points, list_pos &output);
    list_pos create_bezier();
    list_pos create();
};


#endif //BEZIER_BEZIERAPPROXIMATOR_H
