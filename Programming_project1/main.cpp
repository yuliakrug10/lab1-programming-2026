// MSVC v143 (версія 19.44.35228, 32-bit x86)
// Тракалюк Анжеліка та Круглєня Юлія К-28

#include "FunctionalClass.h"
#include "input_output.h"
#include <stdexcept>
#include <iostream>

using namespace std;


int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "ERROR: does not find file path" << endl;
        return 1;
    }
    const string input_data = argv[1];
    try {
        size_t iteration = 0;
        Functional_class Obj_1 = input_values(iteration, input_data);
        generate_output("output.txt", Obj_1, iteration);
    }
    catch (const exception& e) {
        cerr << "ERROR: " << e.what();
    }
    return 0;
}


