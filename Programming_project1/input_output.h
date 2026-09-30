#pragma once
#include "FunctionalClass.h"
#include <string>

Functional_class input_values(size_t& iteration_num, const std::string& input_data);
void generate_output(const std::string& output_file, Functional_class& obj, size_t iteration);

