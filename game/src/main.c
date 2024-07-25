

#include "raylib.h"


int main(void)
{

    const int screenWidth = 800;
    const int screenHeight = 640;
    const int gridScale = 20;
    const int cols = screenWidth / gridScale;
    const int rows = screenHeight / gridScale;

    InitWindow(screenWidth, screenHeight, "Voxels game");


     Camera camera = { 0 };
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE; 

    /*InitAudioDevice();
    Music music = LoadMusicStream("resources/ethereal.wav");
    PlayMusicStream(music);*/
    DisableCursor();
    SetTargetFPS(60);  

    //Mesh cube = GenMeshCube(1,1,1);

    //Model cubePerlin = LoadModelFromMesh(cube);
    Image heightMap = LoadImage("resources/heightmap.png");


    //Image perlinNoise = GenImagePerlinNoise(100, 100, 0,0, 1);


    //Texture2D perlinTexture = LoadTextureFromImage(perlinNoise);
    //cubePerlin.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = perlinTexture;


    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        //UpdateMusicStream(music);

        UpdateCamera(&camera, CAMERA_FIRST_PERSON);
        

        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

            // works
            //DrawCube((Vector3){10,10,0},1,1,1, BLACK);
            for(int i = 0; i < heightMap.width; i++){
                for(int j = 0; j < heightMap.height; j++){
                    Color pixelColor = GetImageColor(heightMap,i,j);
                    float saturation = (pixelColor.r + pixelColor.g + pixelColor.b) /3;
                    DrawCube((Vector3){i,0,j},1, saturation/255 * 20,1, (Color){saturation,saturation,saturation,255});
                }
            }
            //DrawModel(cubePerlin, (Vector3){0, 0,0},1, WHITE);
            //DrawTexture(perlinTexture, 0,0, WHITE);
            //DrawTextureEx(perlinTexture, (Vector2){0,0}, 45, 100, BLACK);

            EndMode3D();


        EndDrawing();

    }

    /*UnloadMusicStream(music);
    CloseAudioDevice();*/


    CloseWindow();        // Close window and OpenGL context


    return 0;
}
