#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"

int main()
{
    // Window dimensions array
    const int windowWidth(384);
    const int windowHeight(384);
    InitWindow(windowWidth, windowHeight, "RPG WCKED GAMER MOVE GAME MAN GAMER");

    // drawing background
    Texture2D map = LoadTexture("nature_tileset/map.png");
    Vector2 mapPos{0.0, 0.0};
    const float mapScale{4.0f};

    Character knight{windowWidth, windowHeight};
    
    Prop rock{Vector2{0.f, 0.f}, LoadTexture("nature_tileset/Rock.png")};
    

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

        // draw the map
        DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);

        rock.Render(knight.getWorldPos());

        knight.tick(GetFrameTime());
        // check map bounds
        if (knight.getWorldPos().x < 0.f || 
            knight.getWorldPos().y < 0.f || 
            knight.getWorldPos().x + windowWidth > map.width * mapScale || 
            knight.getWorldPos().y + windowHeight > map.height * mapScale)
        {
            knight.undoMovement();
        }

        // stop drawing
        EndDrawing();
    }
    CloseWindow();
}