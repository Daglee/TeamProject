#pragma once

#include "Subsystem.h"

#include <vector>
#include <memory>

class System
{
public:
	System();
	~System();

	void updateNextSystemFrame(const float& deltaTime);
	void addSubsystem(Subsystem* subsystem);

private:
	std::vector<Subsystem*> subsystems;
};

