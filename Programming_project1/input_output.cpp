#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "FunctionalClass.h"
#include <string>

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

	auto read_point = [&f](Point& pt) -> bool {
		double x, y;
		if (f >> x >> y) {
			pt = Point{ x, y };
			return true;
		}
		return false;
		};

	//input starting point
	Point start_point;
	if (!read_point(start_point)) {
		throw std::invalid_argument("Initial point coordinates must be doubles!");
	}

	//input base points
	std::vector<Point> base_points;
	Point curr_point;
	while (read_point(curr_point)) {
		base_points.push_back(curr_point);
	}
	if (!f.eof()) {
		throw std::invalid_argument("Base points coordinates must be a double!");
	}

	iteration_num = num;
	return Functional_class(start_point, base_points);
}

void generate_output(const std::string& output_file,
	Functional_class& obj, size_t iteration) {
	std::ofstream outfile(output_file);
	if (!outfile.is_open()) {
		throw std::runtime_error("Unable to open the output file!");
	}
	auto write_point = [&outfile](const Point& p) {
		outfile << p.x << " " << p.y << '\n';
		};
	for (size_t i = 0; i < iteration; ++i)
	{
		Point temp_point = obj();
		write_point(temp_point);
	}
}

