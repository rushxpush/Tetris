#include <iostream>
#include <raylib.h>
using namespace std;
#pragma once

class Tetromino
{

private:
	char shape;
	/*
	float x = 1.0f;
	float y = 20.0f;
	float z = 1.0f;
	*/
	float x;
	float y;
	float z;

	float x_displacement = 1.0f;

	float width = 1.0f;
	float height = 1.0f;
	float length = 1.0f;

	float gravity = -1.0f;

	int tetromino_speed = 1;
	float time_elapsed = 0;

	bool key_down_pressed = false;
	bool key_left_pressed = false;
	bool key_right_pressed = false;
	float key_down_time_pressed = 0;
	float key_left_time_pressed = 0;
	float key_right_time_pressed = 0;

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

	void Draw(float delta);

	void Update(float delta);

	void InitializeTetromino(string blocks);

	void InitializePosition(int x, int y, int z);
};
