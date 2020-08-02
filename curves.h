//
// Created by yuitora . on 01/08/2020.
//

#ifndef BEZIER_CURVES_H
#define BEZIER_CURVES_H
#include "Vector2.h"
#include "CatmullApproximator.h"
#include "PerfectApproximator.h"
#include "BezierApproximator.h"
#include "LinearApproximator.h"

list_pos get_bezier(list_pos &control_points);
list_pos get_linear(list_pos &control_points);
list_pos get_catmull(list_pos &control_points);
list_pos get_perfect(list_pos &control_points);
void adjust_curve(list_pos &path, double expected_length);

#endif //BEZIER_CURVES_H
