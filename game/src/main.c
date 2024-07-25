

#include "raylib.h"


int main(void)
{

    const int screenWidth = 800;
    const int screenHeight = 460;
    const int gridScale = 20;
    const int cols = screenWidth / gridScale;
    const int rows = screenHeight / gridScale;

    InitWindow(screenWidth, screenHeight, "The Coding Train - Infinite Landscape");


    /*InitAudioDevice();
    Music music = LoadMusicStream("resources/ethereal.wav");
    PlayMusicStream(music);*/

    SetTargetFPS(60);  

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        //UpdateMusicStream(music);

        BeginDrawing();

            ClearBackground(RAYWHITE);

            for(int x = 0; x < cols; x++){
                for(int y = 0; y < rows; y++){
                    //DrawLine(x*gridScale, y*gridScale, x*gridScale, screenHeight, BLACK);
                    //DrawLine(x*gridScale, y*gridScale, screenWidth, y*gridScale, BLACK);
                    DrawRectangleLines(x*gridScale, y*gridScale, gridScale, gridScale, BLACK);
                    //DrawFi
                }

            }


        EndDrawing();

    }

    /*UnloadMusicStream(music);
    CloseAudioDevice();*/


    CloseWindow();        // Close window and OpenGL context


    return 0;
}
