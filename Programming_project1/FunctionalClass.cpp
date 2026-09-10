#include "FunctionalClass.h"
#include <stdexcept>

Functional_class::Functional_class(Point start_point, std::vector<Point> points)
    : main_point(start_point),
    base_points(std::move(points)),
    rng(std::random_device{}())
{
    if (base_points.empty()) {
        throw std::invalid_argument("No base points inputted");
    }

    dist = std::uniform_int_distribution<size_t>(0, base_points.size() - 1);
}

Point Functional_class::operator()() {
	int i = dist(rng);
	main_point = (base_points[i] + main_point) / 2.0;
	return main_point;
}


