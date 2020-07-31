//
// Created by yuitora . on 31/07/2020.
//

#include "BezierApproximator.h"


BezierApproximator::BezierApproximator(std::vector<Vector2<float> > &control_points) {
    this->control_points = control_points;
    this->count = control_points.size();
    this->subdivision_buffer1.resize(count);
    this->subdivision_buffer2.resize(count * 2 - 1);
}



bool BezierApproximator::is_flat_enough(std::vector<Vector2<float> > &control_points) {
	for (int i = 1; i < control_points.size() - 1; i++)
		if ((control_points[i - 1] - control_points[i] * 2 + control_points[i + 1]).length_squared() > this->TOLERANCE_SQ)
			return false;

	return true;
}

void BezierApproximator::subdivide(std::vector<Vector2<float> > &control_points, std::vector<Vector2<float> > &l, std::vector<Vector2<float> > &r) {
    std::vector<Vector2<float> > midpoints(this->count);

    for (int i = 0; i < count; i++)
        midpoints[i] = control_points[i];

    for (int i = 0; i < count; i++)
    {
        l[i] = midpoints[0];
        r[count - i - 1] = midpoints[count - i - 1];

        for (int j = 0; j < count - i - 1; j++)
            midpoints[j] = (midpoints[j] + midpoints[j + 1]) / 2;
    }
}

void BezierApproximator::approximate(std::vector<Vector2<float> > &control_points, list_pos &output) {
    std::vector<Vector2<float> >l(this->count * 2 -1);
    std::vector<Vector2<float> > r(this->count);

    this->subdivide(control_points, l, r);

    for (int i = 0; i < count - 1; ++i)
        l[count + i] = r[i + 1];

    control_points[0].add_to_output(output);
    for (int i = 1; i < count - 1; ++i)
    {
        int index = 2 * i;
        Vector2<float> p =(l[index] * 2 + l[index - 1] + l[index + 1]) * 0.25f;
        p.add_to_output(output);
    }
}

list_pos BezierApproximator::create_bezier() {
    list_pos output;
    if (this->count == 0)
        return output;

    std::vector<std::vector<Vector2<float> > > to_flatten;
    std::vector<std::vector<Vector2<float> > > free_buffers;

    // "to_flatten" contains all the curves which are not yet approximated well enough.
    // We use a stack to emulate recursion without the risk of running into a stack overflow.
    // (More specifically, we iteratively and adaptively refine our curve with a
    // <a href="https://en.wikipedia.org/wiki/Depth-first_search">Depth-first search</a>
    // over the tree resulting from the subdivisions we make.)
    to_flatten.push_back(control_points);

    std::vector<Vector2<float> > left_child = this->subdivision_buffer2;

    while (!to_flatten.empty())
    {
        std::vector<Vector2<float> > parent = to_flatten.back();
        to_flatten.pop_back();
        if (this->is_flat_enough(parent))
        {
            // If the control points we currently operate on are sufficiently "flat", we use
            // an extension to De Casteljau's algorithm to obtain a piecewise-linear approximation
            // of the bezier curve represented by our control points, consisting of the same amount
            // of points as there are control points.
            this->approximate(parent, output);
            free_buffers.push_back(parent);
            continue;
        }

        // If we do not yet have a sufficiently "flat" (in other words, detailed) approximation we keep
        // subdividing the curve we are currently operating on.
        std::vector<Vector2<float> > right_child;
        if (!free_buffers.empty()) {
            right_child = free_buffers.back();
            free_buffers.pop_back();
        } else {
            right_child.resize(count);
        }
        this->subdivide(parent, left_child, right_child);

        // We re-use the buffer of the parent for one of the children, so that we save one allocation per iteration.
        for (int i = 0; i < count; ++i)
            parent[i] = left_child[i];

        to_flatten.push_back(right_child);
        to_flatten.push_back(parent);
    }

    control_points[count - 1].add_to_output(output);
    return output;
}

list_pos BezierApproximator::create() {
    return create_bezier();
}
