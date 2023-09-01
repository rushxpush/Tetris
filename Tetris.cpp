#include <iostream>
#include <raylib.h>
#include <deque>
#include <vector>
#include "Tetromino.h"
#include "Board.h"

using namespace std;

int screen_width = 1280;
int screen_height = 900;
bool is_timestep_active = false;

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



	Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };


	float cube_size = 1.0f;

	
	BoundingBox box;


	SetTargetFPS(60);
	board.GenerateBoard();
	tetromino.InitializePosition(board.size_x, board.size_y, board.size_z);

	// Camera
	Camera3D camera = { 0 };
	// camera.position = { -40.0f, 10.0f, 2.0f };
	camera.position = { -30.0f, 10.0f , 5.0f };
	// camera.target = { 8.0f, 8.0f, 8.0f };
	camera.target = { float(board.size_x) / 2, float(board.size_y) / 2, float(board.size_z) / 2};
	camera.up = { 0.0f, 1.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;

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

		if(is_timestep_active)
		{ }

		// Update

		tetromino.Update(deltaTime);

		// Collision 
		// Draw
		//DrawCube(cubePosition, cube_size, cube_size, cube_size, RED);
		//DrawCubeWires(cubePosition, 1.0f, 1.0f, 1.0f, MAROON);
		//DrawCubeWires(cubePosition, cube_size, cube_size, cube_size, MAROON);

		//if ()

		tetromino.Draw(deltaTime);
		board.Draw(deltaTime);

		DrawGrid(100, 1.0f);

		EndMode3D();

		DrawText("Tetris 3D", 10, 40, 20, DARKGRAY);

		DrawFPS(10, 10);


		EndDrawing();

	}

	CloseWindow();
	return 0;
}