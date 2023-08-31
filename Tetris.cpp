#include <iostream>
#include <raylib.h>
#include <deque>
#include <vector>
#include "Tetromino.h"
#include "Board.h"

using namespace std;

int screen_width = 1280;
int screen_height = 800;

class BlocksColor
{
public:
	char face_color;
	char edge_color;
};

BlocksColor blocks_color[3];

char blocks[6] = { 'T', 'B','L', 'I', 'S', 'Z'};


Tetromino tetromino;
Board board;


int main(void)
{

	InitWindow(screen_width, screen_height, "3d Tetris");

	// Camera
	Camera3D camera = { 0 };
	// camera.position = { -40.0f, 10.0f, 2.0f };
	camera.position = { -10.0f, 10.0f, 10.0f };
	camera.target = { 0.0f, 0.0f, 0.0f };
	camera.up = { 0.0f, 1.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

	float cube_size = 1.0f;

	SetTargetFPS(60);

	while(!WindowShouldClose())
	{
		float deltaTime = GetFrameTime();

		BeginDrawing();

		ClearBackground(RAYWHITE);

		BeginMode3D(camera);


		if (!tetromino.tetromino_exist)
		{
			tetromino.InitializeTetromino(blocks);
			tetromino.tetromino_exist = true;

		}

		// Update

		tetromino.Update(deltaTime);

		// Collision 
		// Draw
		//DrawCube(cubePosition, cube_size, cube_size, cube_size, RED);
		//DrawCubeWires(cubePosition, 1.0f, 1.0f, 1.0f, MAROON);
		//DrawCubeWires(cubePosition, cube_size, cube_size, cube_size, MAROON);

		//if ()

		tetromino.Draw();
		board.Draw();

		DrawGrid(10, 1.0f);

		EndMode3D();

		DrawText("Tetris 3D", 10, 40, 20, DARKGRAY);

		DrawFPS(10, 10);


		EndDrawing();

	}

	CloseWindow();
	return 0;
}