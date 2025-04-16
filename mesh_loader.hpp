#pragma once

#include <fstream>

#include "classes.hpp"

namespace mesh_loader
{
	mesh* load(const char* path);

	void load_vertices(std::ifstream& input_file, mesh& loaded_mesh);
	void load_colours(std::ifstream& input_file, mesh& loaded_mesh);
	void load_indices(std::ifstream& input_file, mesh& loaded_mesh);
};
