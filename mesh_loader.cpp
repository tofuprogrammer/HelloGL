#include "mesh_loader.hpp"

#include <iostream>
#include <fstream>

namespace mesh_loader
{
	using namespace std;
	void load_colours(ifstream& input_file, mesh& mesh)
	{
		input_file >> mesh.colour_count;

		if (mesh.colour_count > 0)
		{
			mesh.colours = new colour[mesh.colour_count];

			for (int iteration = 0; iteration < mesh.colour_count; iteration++)
			{
				input_file >> mesh.colours[iteration].r;
				input_file >> mesh.colours[iteration].g;
				input_file >> mesh.colours[iteration].b;
			}
		}
	}

	void load_indices(ifstream& input_file, mesh& mesh)
	{
		input_file >> mesh.index_count;

		if (mesh.index_count > 0)
		{
			mesh.indices = new GLushort[mesh.index_count];

			for (int i = 0; i < mesh.index_count; i++)
			{
				input_file >> mesh.indices[i];
			}
		}
	}
	void load_vertices(ifstream& input_file, mesh& mesh)
	{
		input_file >> mesh.vertex_count;

		if (mesh.vertex_count > 0)
		{
			mesh.vertices = new vertex[mesh.vertex_count];

			for (int i = 0; i < mesh.vertex_count; i++)
			{
				input_file >> mesh.vertices[i].x;
				input_file >> mesh.vertices[i].y;
				input_file >> mesh.vertices[i].z;
			}
		}
	}

	mesh* load(const char* path)
	{
		mesh* loaded_mesh = new mesh();

		ifstream input_file;
		input_file.open(path);
		if (!input_file.good())
		{
			cerr  << "Can't open texture file " << path << endl;
			return nullptr;
		}

		load_vertices(input_file, *loaded_mesh);
		load_colours(input_file, *loaded_mesh);
		load_indices(input_file, *loaded_mesh);

		return loaded_mesh;
	}
}
