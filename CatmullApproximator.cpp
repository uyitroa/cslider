//
// Created by yuitora . on 01/08/2020.
//

#include "CatmullApproximator.h"

CatmullApproximator::CatmullApproximator(list_vector &control_points) {
    this->control_points = control_points;
}

Vector2<float> CatmullApproximator::catmul_rom(Vector2<float> v1, Vector2<float> v2, Vector2<float> v3, Vector2<float> v4, float amount) {
    float amount_squared = amount * amount;
    float amount_cubed = amount_squared * amount;
    return ((v2 * 2.0f +
                (v3 - v1) * amount +
                (v1 * 2.0f - v2 * 5.0f + v3 * 4.0f - v4) * amount_squared +
                (v2 * 3.0f - v1 - v3 * 3.0f + v4) * amount_cubed) * 0.5f);
}

list_pos CatmullApproximator::create() {
    list_pos output;
    for (int j = 0; j < this->control_points.size() - 1; j++) {
        Vector2<float> v1 = (j - 1 >= 0 ? this->control_points[j - 1] : this->control_points[j]);
        Vector2<float> v2 = this->control_points[j];
        Vector2<float> v3 = (j + 1 < this->control_points.size() ? this->control_points[j + 1] : v2 + (v2 - v1));
        Vector2<float> v4 = (j + 2 < this->control_points.size() ? this->control_points[j + 2] : v3 + (v3 - v2));

        for (int k = 0; k <= this->TOLERANCE; k++) {
            Vector2<float> v = catmul_rom(v1, v2, v3, v4, (float) k / this->TOLERANCE);
            v.add_to_output(output);
        }
    }
    return output;
}
