
#pragma comment(lib, "Utilities.lib")
#pragma comment(lib, "Input.lib")
#pragma comment(lib, "Graphics.lib")

#include "Systems\System.h"
#include "Game/GameLoop.h"

#include "Graphics/Rendering/RenderingSystem.h"

int main()
{
	System engine;
	GameLoop game(engine);

	game.executeGameLoop();

    return 0;
}

