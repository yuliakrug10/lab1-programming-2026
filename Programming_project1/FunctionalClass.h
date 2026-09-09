#pragma once
#include <vector>
struct Point {
	double x;
	double y;
};
class Functional_class
{
public:
	Functional_class(Point start_point, std::vector<Point> points);
	Point operator()();
private:
	Point main_point;
	std::vector<Point> base_points;
	// std::vector<Point> generated_points;
};

