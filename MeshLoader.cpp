#include "MeshLoader.hpp"

#include <iostream>
#include <fstream>

namespace MeshLoader
{
	using namespace std;
	void LoadColours(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.colourCount;

		if (mesh.colourCount > 0)
		{
			mesh.colours = new Colour[mesh.colourCount];

			for (int i = 0; i < mesh.colourCount; i++)
			{
				inFile >> mesh.colours[i].r;
				inFile >> mesh.colours[i].g;
				inFile >> mesh.colours[i].b;
			}
		}
	}

	void LoadIndices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.indexCount;

		if (mesh.indexCount > 0)
		{
			mesh.indices = new GLushort[mesh.indexCount];

			for (int i = 0; i < mesh.indexCount; i++)
			{
				inFile >> mesh.indices[i];
			}
		}
	}
	void LoadVertices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.vertexCount;

		if (mesh.vertexCount > 0)
		{
			mesh.vertices = new Vertex[mesh.vertexCount];

			for (int i = 0; i < mesh.vertexCount; i++)
			{
				inFile >> mesh.vertices[i].x;
				inFile >> mesh.vertices[i].y;
				inFile >> mesh.vertices[i].z;
			}
		}
	}

	Mesh* MeshLoader::Load(const char* path)
	{
		Mesh* mesh = new Mesh();

		ifstream inFile;
		inFile.open(path);
		if (!inFile.good())
		{
			cerr  << "Can't open texture file " << path << endl;
			return nullptr;
		}

		LoadVertices("cube.txt", *mesh);
		LoadColours("cube.txt", *mesh);
		LoadIndices("cube.txt", *mesh);

		return mesh;
	}
}
