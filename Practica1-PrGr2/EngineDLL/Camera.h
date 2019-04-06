#pragma once

#include "Exports.h"
#include "Renderer.h"
#include "Entity.h"

class ENGINEDLL_API Camera : public Entity
{
public:
	Camera(Renderer* rendererPtr);
	~Camera();
	void Walk(float forwardMovement);
	void Strafe();
};

