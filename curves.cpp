#include <iostream>
#include <vector>
#include "Vector2.h"
#include "BezierApproximator.h"

void printpos(list_pos &output) {
    printf("%d\n", output.size());
    for(int x = 0; x < output.size(); x++) {
        printf("%f %f\n", output[x][0], output[x][1]);
    }
}


int main() {

    std::vector<Vector2<double> > control_points = {Vector2<double>(306, 222), Vector2<double>(303, 149), Vector2<double>(303, 149), Vector2<double>(361, 207), Vector2<double>(372, 277), Vector2<double>(372, 277), Vector2<double>(401, 271), Vector2<double>(401, 271), Vector2<double>(413, 339), Vector2<double>(460, 375), Vector2<double>(460, 375), Vector2<double>(514, 306), Vector2<double>(482, 209), Vector2<double>(428, 191), Vector2<double>(428, 191), Vector2<double>(454, 129), Vector2<double>(454, 129), Vector2<double>(403, 88), Vector2<double>(355, 87), Vector2<double>(355, 87), Vector2<double>(368, 38), Vector2<double>(368, 38), Vector2<double>(278, 66), Vector2<double>(156, 53), Vector2<double>(82, 11)};

    BezierApproximator b(control_points);
    list_pos output = b.create_bezier();
    printpos(output);
    return 0;
}