#pragma once
#include <vector>
#include <random>

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
	std::mt19937 rng;
	std::uniform_int_distribution<size_t> dist;
};

