#include "mesh_loader.hpp"

#include <fstream>
#include <iostream>

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

			for (int iteration = 0; iteration < mesh.index_count; iteration++)
			{
				input_file >> mesh.indices[iteration];
			}
		}
	}
	void load_vertices(ifstream& input_file, mesh& mesh)
	{
		input_file >> mesh.vertex_count;

		if (mesh.vertex_count > 0)
		{
			mesh.vertices = new vertex[mesh.vertex_count];

			for (int iteration = 0; iteration < mesh.vertex_count; iteration++)
			{
				input_file >> mesh.vertices[iteration].x;
				input_file >> mesh.vertices[iteration].y;
				input_file >> mesh.vertices[iteration].z;
			}
		}
	}

	mesh* mesh_loader::load(const char* path)
	{
		mesh* object_mesh = new mesh();

		ifstream inFile;
		inFile.open(path);
		if (!inFile.good())
		{
			cerr  << "Can't open texture file " << path << '\n';
			return nullptr;
		}

		load_vertices(inFile, *object_mesh);
		load_colours(inFile, *object_mesh);
		load_indices(inFile, *object_mesh);

		return object_mesh;
	}
}
