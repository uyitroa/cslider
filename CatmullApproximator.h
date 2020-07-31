//
// Created by yuitora . on 01/08/2020.
//

#ifndef BEZIER_CATMULLAPPROXIMATOR_H
#define BEZIER_CATMULLAPPROXIMATOR_H
#define list_pos std::vector<std::vector<float> >
#define list_vector std::vector<Vector2<float> >

#include "Vector2.h"
#include <iostream>
#include <vector>

class CatmullApproximator {
private:
    list_vector control_points;
public:
    const float TOLERANCE = 50.0f;
    CatmullApproximator(list_vector &control_points);
    Vector2<float> catmul_rom(Vector2<float> v1, Vector2<float> v2, Vector2<float> v3, Vector2<float> v4, float amount);
    list_pos create();
};


#endif //BEZIER_CATMULLAPPROXIMATOR_H
