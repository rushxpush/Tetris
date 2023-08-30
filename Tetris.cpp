#include <iostream>
#include <raylib.h>
#include <deque>
#include <vector>

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




class Tetromino
{
private:
	const char* shape = "t";
	float x = 1.0f;
	float y = 1.0f;
	float z = 1.0f;
	float width = 1.0f;
	float height = 1.0f;
	float length = 1.0f;
	// float block[4][3] = { {0.0f, 0.0f, -1.0f}, {0.0f, 0.0f, 0.0f} , {0.0f, 0.0f, 1.0f}, {0.0f, -1.0f, 0.0f} };

	struct block_1 {
		float x = 0.0f;
		float y = 0.0f;
		float z = -1.0f;
		int position = 0;
	} block_1;

	struct block_2 {
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;
	} block_2;

	struct block_3 {
		float x = 0.0f;
		float y = 0.0f;
		float z = 1.0f;
		int position = 2;
	} block_3;

	struct block_4 {
		float x = 0.0f;
		float y = 1.0f;
		float z = 0.0f;
		int position = 1;
	} block_4;

	float t_position[4][3] = { {0.0f, 1.0f, -1.0f}, {0.0f, 1.0f, 1.0f}, {0.0f, -1.0f, 1.0f}, {0.0f, -1.0f, -1.0f} };

	Color flat_color = RED;
	Color edge_color = MAROON;

public:
	void Draw()
	{
		if (shape == "t")
		{

			//  x
			// 1xx
			DrawCube({ block_1.x, block_1.y, block_1.z }, width, height, length, flat_color);
			DrawCubeWires({ block_1.x, block_1.y, block_1.z}, width, height, length, flat_color);


			//  x
			// x2x 
			DrawCube({ block_2.x, block_2.y, block_2.z }, width, height, length, GREEN);
			DrawCubeWires({ block_2.x, block_2.y, block_2.z }, width, height, length, edge_color);

			//  x
			// xx3 
			DrawCube({ block_3.x, block_3.y, block_3.z }, width, height, length, BLUE);
			DrawCubeWires({ block_3.x, block_3.y, block_3.z}, width, height, length, flat_color);

			//  4 
			// xxx 
			DrawCube({ block_4.x, block_4.y, block_4.z}, width, height, length, YELLOW);
			DrawCubeWires({ block_4.x, block_4.y, block_4.z}, width, height, length, flat_color);


		}


	}

	void Update()
	{
		// Gravity
		y = 1.0f;
		/*
		block_1.y += y;
		block_2.y += y;
		block_3.y += y;
		block_4.y += y;
		*/

		if (IsKeyPressed(KEY_DOWN))
		{


		cout << "---------------------" << endl;
		cout << "block_1.position: " << block_1.position << endl;
		cout << "block_1.x: " << block_1.x << endl;
		cout << "block_1.y: " << block_1.y << endl;
		cout << "block_1.z: " << block_1.z << endl;
		cout << " " << endl;

		cout << "block_2.x: " << block_2.x << endl;
		cout << "block_2.y: " << block_2.y << endl;
		cout << "block_2.z: " << block_2.z << endl;
		cout << " " << endl;

		cout << "block_3.position: " << block_3.position << endl;
		cout << "block_3.x: " << block_3.x << endl;
		cout << "block_3.y: " << block_3.y << endl;
		cout << "block_3.z: " << block_3.z << endl;
		cout << " " << endl;

		cout << "block_4.position: " << block_4.position << endl;
		cout << "block_4.x: " << block_4.x << endl;
		cout << "block_4.y: " << block_4.y << endl;
		cout << "block_4.z: " << block_4.z << endl;
		cout << " " << endl;
		}

		// Collision
		if (IsKeyPressed(KEY_UP))
		{
			
			if (shape == "t")
			{
				if (block_1.position == 3)
				{
					cout << "block_1" << endl;
					block_1.position = 0;
					block_1.x += t_position[0][0];
					block_1.y += t_position[0][1];
					block_1.z += t_position[0][2];
				}
				else
				{
					cout << "block_1" << endl;

					block_1.position += 1;
					block_1.x += t_position[block_1.position][0];
					block_1.y += t_position[block_1.position][1];
					block_1.z += t_position[block_1.position][2];
				}

				if (block_3.position == 3)
				{
					block_3.position = 0;
					block_3.x += t_position[0][0];
					block_3.y += t_position[0][1];
					block_3.z += t_position[0][2];
				}
				else
				{
					block_3.position += 1;
					block_3.x += t_position[block_3.position][0];
					block_3.y += t_position[block_3.position][1];
					block_3.z += t_position[block_3.position][2];
				}

				if (block_4.position == 3)
				{
					block_4.position = 0;
					block_4.x += t_position[0][0];
					block_4.y += t_position[0][1];
					block_4.z += t_position[0][2];
				}
				else
				{
					block_4.position += 1;
					block_4.x += t_position[block_4.position][0];
					block_4.y += t_position[block_4.position][1];
					block_4.z += t_position[block_4.position][2];
				}
			}


		cout << "---------------------" << endl;
		cout << "block_1.position: " << block_1.position << endl;
		cout << "block_1.x: " << block_1.x << endl;
		cout << "block_1.y: " << block_1.y << endl;
		cout << "block_1.z: " << block_1.z << endl;
		cout << " " << endl;

		cout << "block_2.x: " << block_2.x << endl;
		cout << "block_2.y: " << block_2.y << endl;
		cout << "block_2.z: " << block_2.z << endl;
		cout << " " << endl;

		cout << "block_3.position: " << block_3.position << endl;
		cout << "block_3.x: " << block_3.x << endl;
		cout << "block_3.y: " << block_3.y << endl;
		cout << "block_3.z: " << block_3.z << endl;
		cout << " " << endl;

		cout << "block_4.position: " << block_4.position << endl;
		cout << "block_4.x: " << block_4.x << endl;
		cout << "block_4.y: " << block_4.y << endl;
		cout << "block_4.z: " << block_4.z << endl;
		cout << " " << endl;

		}

	}

	void Rotate()
	{}
};

Tetromino tetromino;


int main(void)
{

	InitWindow(screen_width, screen_height, "3d Tetris");

	// Camera
	Camera3D camera = { 0 };
	camera.position = { -20.0f, 10.0f, 2.0f };
	camera.target = { 0.0f, 0.0f, 0.0f };
	camera.up = { 0.0f, 1.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

	float cube_size = 1.0f;

	SetTargetFPS(1);

	while(!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		BeginMode3D(camera);

		// Update

		tetromino.Update();

		// Collision 
		// Draw
		//DrawCube(cubePosition, cube_size, cube_size, cube_size, RED);
		//DrawCubeWires(cubePosition, 1.0f, 1.0f, 1.0f, MAROON);
		//DrawCubeWires(cubePosition, cube_size, cube_size, cube_size, MAROON);

		tetromino.Draw();

		DrawGrid(10, 1.0f);

		EndMode3D();

		DrawText("Tetris 3D", 10, 40, 20, DARKGRAY);

		DrawFPS(10, 10);


		EndDrawing();

	}

	CloseWindow();
	return 0;
}