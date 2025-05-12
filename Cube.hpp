#pragma once

#include "scene_object.hpp"
#include "structures.hpp"

class cube : public scene_object
{
private:
	vector3 m_cube_position;
	GLfloat m_cube_rotation;

public:
	cube(mesh* mesh, float x, float y, float z);
	~cube();

	void cube_draw();
	void object_draw() override;
	void cube_update();
	void object_update() override;
};
