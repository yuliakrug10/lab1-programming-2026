#include "FunctionalClass.h"
#include <stdexcept>
#include <functional>


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
    size_t i = dist(rng);
    std::plus<double> add;
    std::divides<double> div;

    main_point.x = div(add(main_point.x, base_points[i].x), 2.0);
    main_point.y = div(add(main_point.y, base_points[i].y), 2.0);

    return main_point;
}


