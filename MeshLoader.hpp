#pragma once

#include <fstream>

#include "Classes.hpp"

namespace MeshLoader
{
	Mesh* Load(const char* path);

	void LoadVertices(std::ifstream& inFile, Mesh& mesh);
	void LoadColours(std::ifstream& inFile, Mesh& mesh);
	void LoadIndices(std::ifstream& inFile, Mesh& mesh);
};
