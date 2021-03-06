#include "raylib.h"
#include "iostream"
#include "Game.h"

#define GLSL_VERSION  330

int main()
{
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(1920, 1080, "Valiant Engine V2");
    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));
    ToggleFullscreen();

    if (GLSL_VERSION != 330)
    {
        std::cout << "ERROR! Initializing OpenGL failed! Closing program.\n";
        CloseWindow();
        return 1;
    }

    Game game;

    while (!WindowShouldClose())
    {
        game.runApplication();
    }

    game.deInit();
    CloseWindow();
    
    return 0;
}