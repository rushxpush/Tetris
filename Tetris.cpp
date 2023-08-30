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

char blocks[6] = { 'T', 'B','L', 'I', 'S', 'Z'};




class Tetromino
{
private:
	char shape;
	float x = 1.0f;
	float y = 1.0f;
	float z = 1.0f;
	float gravity = -1.0f;
	float width = 1.0f;
	float height = 1.0f;
	float length = 1.0f;
	int tetromino_speed = 1;
	float time_elapsed = 0;

	struct block {
		float x;
		float y;
		float z;
		int position;
		string type;
	} block_1, block_2, block_3, block_4;

	float across_position[4][3] = { {0.0f, 1.0f, -1.0f}, {0.0f, 1.0f, 1.0f}, {0.0f, -1.0f, 1.0f}, {0.0f, -1.0f, -1.0f} };
	// float across_2_position[4][3] = { {0.0f, 2.0f, 0.0f}, {0.0f, 0.0f, 2.0f}, {0.0f, -2.0f, 0.0f}, {0.0f, 0.0f, -2.0f} };
	float diagonal_position[4][3] = { {0.0f, 2.0f, 0.0f}, {0.0f, 0.0f, 2.0f}, {0.0f, -2.0f, 0.0f}, {0.0f, 0.0f, -2.0f} };



	Color flat_color = RED;
	Color edge_color = MAROON;

public:
	bool tetromino_exist = false;

	void Draw()
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

	void Update(float delta)
	{

		// Gravity

		// y = y - speed ;
		// y += -1.0f;
		/*
		*/
		time_elapsed += delta;
		if (time_elapsed >= tetromino_speed)
		{
			time_elapsed = 0;

			block_1.y += gravity;
			block_2.y += gravity;
			block_3.y += gravity;
			block_4.y += gravity;
		}

		/*
		cout << "--------------" << endl;
		// cout << "delta: " << delta << endl;
		cout << "time_elapsed: " << time_elapsed << endl;
		cout << "y: " << y << endl;
		*/
		


		// Collision
		if (IsKeyPressed(KEY_UP))
		{
			if (shape == 'T')
			{
				if (block_1.position == 3)
				{
					cout << "block_1" << endl;
					block_1.position = 0;
					block_1.x += across_position[0][0];
					block_1.y += across_position[0][1];
					block_1.z += across_position[0][2];
				}
				else
				{
					cout << "block_1" << endl;

					block_1.position += 1;
					block_1.x += across_position[block_1.position][0];
					block_1.y += across_position[block_1.position][1];
					block_1.z += across_position[block_1.position][2];
				}

				if (block_3.position == 3)
				{
					block_3.position = 0;
					block_3.x += across_position[0][0];
					block_3.y += across_position[0][1];
					block_3.z += across_position[0][2];
				}
				else
				{
					block_3.position += 1;
					block_3.x += across_position[block_3.position][0];
					block_3.y += across_position[block_3.position][1];
					block_3.z += across_position[block_3.position][2];
				}

				if (block_4.position == 3)
				{
					block_4.position = 0;
					block_4.x += across_position[0][0];
					block_4.y += across_position[0][1];
					block_4.z += across_position[0][2];
				}
				else
				{
					block_4.position += 1;
					block_4.x += across_position[block_4.position][0];
					block_4.y += across_position[block_4.position][1];
					block_4.z += across_position[block_4.position][2];
				}
			}


		}
		if (IsKeyPressed(KEY_LEFT))
		{
			block_1.z -= 1; 
			block_2.z -= 1; 
			block_3.z -= 1; 
			block_4.z -= 1; 
		}
		if (IsKeyPressed(KEY_RIGHT))
		{
			block_1.z += 1;
			block_2.z += 1;
			block_3.z += 1;
			block_4.z += 1;
		}

	}

	void InitializeTetromino(string blocks) {
		int num = rand() % blocks.length();
		// char block = blocks[num];

		shape = 'T';
		//{ "T", "S", "L", "I", "S", "Z"}
		switch (shape){
			case 'T':
				block_1.x = 0.0f;
				block_1.y = 0.0f;
				block_1.z = -1.0f;
				block_1.position = 0;
				block_1.type = "across";

				block_2.x = 0.0f;
				block_2.y = 0.0f;
				block_2.z = 0.0f;
				block_2.position = -1;
				block_2.type = "across";

				block_3.x = 0.0f;
				block_3.y = 0.0f;
				block_3.z = 1.0f;
				block_3.position = 2;
				block_3.type = "across";

				block_4.x = 0.0f;
				block_4.y = 1.0f;
				block_4.z = 0.0f;
				block_4.position = 1;
				block_4.type = "across";
				break;
			case 'S':
				block_1.x = 0.0f;
				block_1.y = 0.0f;
				block_1.z = -1.0f;
				block_1.position = 0;
				block_1.type = "across";

				block_2.x = 0.0f;
				block_2.y = 0.0f;
				block_2.z = 0.0f;
				block_2.position = -1;
				block_2.type = "center";

				block_3.x = 0.0f;
				block_3.y = 1.0f;
				block_3.z = 0.0f;
				block_3.position = 2;
				block_3.type = "across";

				block_4.x = 0.0f;
				block_4.y = 1.0f;
				block_4.z = 1.0f;
				block_4.position = 1;
				block_4.type = "diagonal";
				break;

		}

	}
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

		DrawGrid(10, 1.0f);

		EndMode3D();

		DrawText("Tetris 3D", 10, 40, 20, DARKGRAY);

		DrawFPS(10, 10);


		EndDrawing();

	}

	CloseWindow();
	return 0;
}