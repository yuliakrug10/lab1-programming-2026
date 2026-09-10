#pragma once
#include <vector>
#include <random>

struct Point {
	double x;
	double y;
	Point operator+(const Point& other) const {
		return { x + other.x, y + other.y };
	}
	Point operator/(double number) const {
		return { x / number, y / number };
	}
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
	std::mt19937 rng;
	std::uniform_int_distribution<size_t> dist;
};

