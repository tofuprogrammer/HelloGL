#pragma once

#include "Classes.hpp"

namespace MeshLoader
{
	Mesh* Load(char* path);

	void LoadVertices(const char* inFile, Mesh& mesh);
	void LoadColours(const char* inFile, Mesh& mesh);
	void LoadIndices(const char* inFile, Mesh& mesh);
};

