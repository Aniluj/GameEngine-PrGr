#pragma once

#include <iostream>
#include "Exports.h"
#include "Renderer.h"
#include "TypeDef.h"
#include "Window.h"
#include <ctime>

using namespace std;

class ENGINEDLL_API GameBase
{
public:
	GameBase();
	~GameBase();
	bool Start();
	bool Stop();
	void Loop();
	Renderer* renderer;
	Window* window;
	double deltaTime;
	double acumTime;
protected:
	bool virtual OnStart()= 0;
	bool virtual OnStop()= 0;
	bool virtual OnUpdate() = 0;
	void virtual OnDraw() = 0;
};

