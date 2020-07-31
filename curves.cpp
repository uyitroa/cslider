#include <iostream>
#include <vector>
#include "Vector2.h"
#include "BezierApproximator.h"
#include "PerfectApproximator.h"
#include "CatmullApproximator.h"

void printpos(list_pos &output) {
    printf("%d\n", output.size());
    for(int x = 0; x < output.size(); x++) {
        printf("%f %f\n", output[x][0], output[x][1]);
    }
}


int main() {

//    list_vector control_points = {Vector2<float>(306, 222), Vector2<float>(303, 149), Vector2<float>(303, 149), Vector2<float>(361, 207), Vector2<float>(372, 277), Vector2<float>(372, 277), Vector2<float>(401, 271), Vector2<float>(401, 271), Vector2<float>(413, 339), Vector2<float>(460, 375), Vector2<float>(460, 375), Vector2<float>(514, 306), Vector2<float>(482, 209), Vector2<float>(428, 191), Vector2<float>(428, 191), Vector2<float>(454, 129), Vector2<float>(454, 129), Vector2<float>(403, 88), Vector2<float>(355, 87), Vector2<float>(355, 87), Vector2<float>(368, 38), Vector2<float>(368, 38), Vector2<float>(278, 66), Vector2<float>(156, 53), Vector2<float>(82, 11)};
    list_vector control_points = {Vector2<float>(302, 117), Vector2<float>(352, 222), Vector2<float>(439, 241)};

    CatmullApproximator b(control_points);
    list_pos output = b.create();
    printpos(output);
    return 0;
}