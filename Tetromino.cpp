#include <iostream>
#include <raylib.h>
#include "Tetromino.h"
using namespace std;

	void Tetromino::Draw(float delta)
	{
		//  x
		// 1xx
		DrawCube({ block_1.x, block_1.y, block_1.z }, width, height, length, flat_color);
		DrawCubeWires({ block_1.x, block_1.y, block_1.z }, width, height, length, flat_color);


		//  x
		// x2x 
		DrawCube({ block_2.x, block_2.y, block_2.z }, width, height, length, GREEN);
		DrawCubeWires({ block_2.x, block_2.y, block_2.z }, width, height, length, edge_color);

		//  x
		// xx3 
		DrawCube({ block_3.x, block_3.y, block_3.z }, width, height, length, BLUE);
		DrawCubeWires({ block_3.x, block_3.y, block_3.z }, width, height, length, flat_color);

		//  4 
		// xxx 
		DrawCube({ block_4.x, block_4.y, block_4.z }, width, height, length, YELLOW);
		DrawCubeWires({ block_4.x, block_4.y, block_4.z }, width, height, length, flat_color);



	}

	void Tetromino::Update(float delta)
	{

		// Gravity

		// y = y - speed ;
		// y += -1.0f;
		/*
		*/
		time_elapsed += delta;
		//key_down_time_pressed += delta;
		if (key_down_pressed)
		{
			if (time_elapsed >= tetromino_speed / 1) 
			{
				block_1.y += gravity;
				block_2.y += gravity;
				block_3.y += gravity;
				block_4.y += gravity;

				time_elapsed = 0.95;

			}
		}
		else
		{
			if (time_elapsed >= tetromino_speed)
			{

				block_1.y += gravity;
				block_2.y += gravity;
				block_3.y += gravity;
				block_4.y += gravity;

				time_elapsed = 0;
			}
		}
		if (key_left_pressed)
		{

			cout << "key_left_pressed" << endl;
			if (time_elapsed >= tetromino_speed / 1) {
				block_1.z += -1.0f;
				block_2.z += -1.0f;
				block_3.z += -1.0f;
				block_4.z += -1.0f;

				key_down_time_pressed = 0.95;
			}
		}
		else
		{

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

			key_left_pressed = true;
		}
		if (IsKeyReleased(KEY_LEFT))
		{
			key_down_pressed = false;
		}
		if (IsKeyPressed(KEY_RIGHT))
		{
			block_1.z += 1;
			block_2.z += 1;
			block_3.z += 1;
			block_4.z += 1;
		}
		if (IsKeyPressed(KEY_DOWN))
		{
			block_1.y -= 1;
			block_2.y -= 1;
			block_3.y -= 1;
			block_4.y -= 1;
			key_down_pressed = true;

		}
		if (IsKeyReleased(KEY_DOWN))
		{
			key_down_pressed = false;

		}

	}

	void Tetromino::InitializeTetromino(string blocks) {
		int num = rand() % blocks.length();
		// char block = blocks[num];

		shape = 'T';
		//{ "T", "S", "L", "I", "S", "Z"}
		switch (shape) {
		case 'T':
			block_1.x = 0.0f + x;
			block_1.y = 0.0f + y ;
			block_1.z = -1.0f + z;
			block_1.position = 0;
			block_1.type = "across";

			block_2.x = 0.0f + x;
			block_2.y = 0.0f + y;
			block_2.z = 0.0f + z;
			block_2.position = -1;
			block_2.type = "across";

			block_3.x = 0.0f + x;
			block_3.y = 0.0f + y;
			block_3.z = 1.0f + z;
			block_3.position = 2;
			block_3.type = "across";

			block_4.x = 0.0f + x;
			block_4.y = 1.0f + y;
			block_4.z = 0.0f + z;
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
