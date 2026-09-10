#include <fstream>
#include <stdexcept>
#include <string>
#include "FunctionalClass.h"

Functional_class input_values(size_t& iteration_num, const std::string& input_data) {
	std::ifstream f(input_data);
	if (!f.is_open()) {
		throw std::runtime_error("Unable to open the file!");
	}

	//input iteration number
	size_t num;
	if (!(f >> num) || !num) {
		throw std::invalid_argument("Number of iterations must be a positive integer!");
	}

	//input starting point
	double x;
	double y;
	if (!(f >> x >> y)) {
		throw std::invalid_argument("Coordinates must be a double!");
	}
	Point start_point{ x, y };
	
	//input base points
	std::vector<Point> base_points;
	while (f >> x >> y) {
		Point curr_point{ x, y };
		base_points.push_back(curr_point);
	}
	if (!f.eof()) {
		throw std::invalid_argument("Base points coordinates must be a double!");
	}

	iteration_num = num;
	return Functional_class(start_point, base_points);
}

