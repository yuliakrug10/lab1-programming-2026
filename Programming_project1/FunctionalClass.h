#pragma once
#include <vector>
struct Point {
	double x;
	double y;
};
class FunctionalClass
{
public:
	FunctionalClass(Point start_point, std::vector<Point> points);
	Point operator()();
private:
	Point main_point;
	std::vector<Point> base_points;
	// std::vector<Point> generated_points;
};

