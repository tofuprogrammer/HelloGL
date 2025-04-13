#pragma once

#include <fstream>

#include "Classes.hpp"

namespace mesh_loader
{
	Mesh* load(const char* path);

	void load_vertices(std::ifstream& input_file, Mesh& mesh);
	void load_colours(std::ifstream& input_file, Mesh& mesh);
	void load_indices(std::ifstream& input_file, Mesh& mesh);
};