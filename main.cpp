#include "raylib.h"
#include "raymath.h"
#include "Character.h"

int main()
{
    // Window dimensions array
    const int windowWidth(384);
    const int windowHeight(384);
    InitWindow(windowWidth, windowHeight, "RPG WCKED GAMER MOVE GAME MAN GAMER");

    // drawing background
    Texture2D map = LoadTexture("nature_tileset/map.png");
    Vector2 mapPos{0.0, 0.0};

    Character knight;
    knight.setScreenPos(windowWidth, windowHeight);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

        // draw the map
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);

        knight.tick(GetFrameTime());

        // stop drawing
        EndDrawing();
    }
    CloseWindow();
}