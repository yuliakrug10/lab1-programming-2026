// MSVC v143 (версія 19.44.35228, 32-bit x86)
// Тракалюк Анжеліка та Круглєня Юлія К-28

#include "FunctionalClass.h"
#include "input_output.h"
#include <stdexcept>
#include <iostream>
#include <functional>
#include <fstream>

using namespace std;

void generate_output(const string& output_file,
    Functional_class& obj, size_t iteration) {
    ofstream outfile(output_file);
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

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Error, does not find file path" << endl;
        return 1;
    }
    const string input_data = argv[1];
    try {
        size_t iteration = 0;
        Functional_class Obj_1 = input_values(iteration, input_data);
        generate_output("output.txt", Obj_1, iteration);
    }
    catch (const exception& e) {
        cerr << "Error" << e.what();
    }
    return 0;
}


