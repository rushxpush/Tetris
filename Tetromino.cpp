#include <iostream>
#include <raylib.h>
#include "Tetromino.h"
#include <vector>
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

bool Tetromino::CheckCollision(BoundingBox col_box_1, BoundingBox col_box_2, float pos_x, float pos_y, float pos_z)
{
	BoundingBox future_col_box = col_box_1;
	future_col_box.min.x += pos_x;
	future_col_box.min.y += pos_y;
	future_col_box.min.z += pos_z;

	future_col_box.max.x += pos_x;
	future_col_box.max.y += pos_y;
	future_col_box.max.z += pos_z;

	if (
		future_col_box.min.x == col_box_2.min.x &&
		future_col_box.min.y >= col_box_2.min.y &&
		future_col_box.min.z == col_box_2.min.z &&
		future_col_box.max.x == col_box_2.max.x &&
		future_col_box.max.y <= col_box_2.max.y &&
		future_col_box.max.z == col_box_2.max.z
		)
	{
		cout << "My COLLISION" << endl;
		return true;
	}

	/*
	if (CheckCollisionBoxes(future_col_box, col_box_2))
	{
			return true;
	}
	*/
	else
	{
		return false;
	}

}

void Tetromino::RotateBlock(block& block, int position, string configuration)
{
	if (configuration == "across")
	{

		if (block.position == 3)
		{
			block.position = 0;
			block.x += across_position[0][0];
			block.y += across_position[0][1];
			block.z += across_position[0][2];
		}
		else
		{

			block.position += 1;
			block.x += across_position[block.position][0];
			block.y += across_position[block.position][1];
			block.z += across_position[block.position][2];
		}
	}
	else {

	}
}

// void Tetromino::Update(float delta, vector<BoundingBox> collision_boxes)
void Tetromino::Update(float delta, BoundingBox collision_boxes)
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

			UpdateCollisionBox(block_1);
			UpdateCollisionBox(block_2);
			UpdateCollisionBox(block_3);
			UpdateCollisionBox(block_4);


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

			UpdateCollisionBox(block_1);
			UpdateCollisionBox(block_2);
			UpdateCollisionBox(block_3);
			UpdateCollisionBox(block_4);

			time_elapsed = 0;
		}
	}
	if (key_left_pressed)
	{

		//cout << "key_left_pressed" << endl;
		if (time_elapsed >= tetromino_speed / 1) {
			cout << "works " << endl;


			/*
			block_1.z += -player_step;
			block_2.z += -player_step;
			block_3.z += -player_step;
			block_4.z += -player_step;

			UpdateCollisionBox(block_1);
			UpdateCollisionBox(block_2);
			UpdateCollisionBox(block_3);
			UpdateCollisionBox(block_4);

			*/
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



	// Movement 
	if (IsKeyPressed(KEY_UP))
	{
		if (shape == 'T')
		{

			if (block_3.position == 3)
			{
				if (!CheckCollision(block_3.collision_box, collision_boxes, 0, 0, across_position[0][2]))
				{
				}
				else
				{
					collision_flag = true;

				}
			}
		}

		if (!collision_flag)
		{
			if (block_1.position == 3)
			{
				RotateBlock(block_1, 0, "across");
			}
			else
			{
				RotateBlock(block_1, block_1.position + 1, "across");
			}

			if (block_3.position == 3)
			{ 
				RotateBlock(block_3, 0, "across");
			}
			else
			{
				RotateBlock(block_3, block_3.position + 1, "across");
			}

			if (block_4.position == 3)
			{
				RotateBlock(block_4, 0, "across");
			}
			else
			{
				RotateBlock(block_4, block_4.position + 1, "across");
			}

			UpdateCollisionBox(block_1);
			UpdateCollisionBox(block_2);
			UpdateCollisionBox(block_3);
			UpdateCollisionBox(block_4);
		}
		else
		{
			cout << "COLLISION HAPPENS!" << endl;
			collision_flag = false;
		}


	}
	if (IsKeyPressed(KEY_LEFT))
	{

		// Inefficient. Think later of a better way
		if (CheckCollision(block_1.collision_box, collision_boxes, 0, 0, -player_step))
		{
			cout << "COLLIDED 1!" << endl;
		}
		else if (CheckCollision(block_2.collision_box, collision_boxes, 0, 0, -player_step))
		{
			cout << "COLLIDED 2!" << endl;
		}
		else if (CheckCollision(block_3.collision_box, collision_boxes, 0, 0, -player_step))
		{
			cout << "COLLIDED 3!" << endl;
		}
		else if (CheckCollision(block_4.collision_box, collision_boxes, 0, 0, -player_step))
		{
			cout << "COLLIDED 4!" << endl;
		}
		else
		{
			block_1.z -= 1;
			block_2.z -= 1;
			block_3.z -= 1;
			block_4.z -= 1;
			UpdateCollisionBox(block_1);
			UpdateCollisionBox(block_2);
			UpdateCollisionBox(block_3);
			UpdateCollisionBox(block_4);

		}





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

		UpdateCollisionBox(block_1);
		UpdateCollisionBox(block_2);
		UpdateCollisionBox(block_3);
		UpdateCollisionBox(block_4);
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

void Tetromino::UpdateCollisionBox(block& block)
{

	block.collision_box.min.x = block.x;
	block.collision_box.min.y = block.y;
	block.collision_box.min.z = block.z;

	block.collision_box.max.x = block.x + width;
	block.collision_box.max.y = block.y + height;
	block.collision_box.max.z = block.z + length;
}


void Tetromino::InitializeTetromino(string blocks) {
	int num = rand() % blocks.length();
	// char block = blocks[num];

	shape = 'T';
	//{ "T", "S", "L", "I", "S", "Z"}
	switch (shape) {
	case 'T':
		// Initialize Position
		block_1.x = 0.0f + x;
		block_1.y = 0.0f + y;
		block_1.z = -1.0f + z;
		block_1.position = 0;
		block_1.type = "across";

		UpdateCollisionBox(block_1);

		block_2.x = 0.0f + x;
		block_2.y = 0.0f + y;
		block_2.z = 0.0f + z;
		block_2.position = -1;
		block_2.type = "across";

		UpdateCollisionBox(block_2);

		block_3.x = 0.0f + x;
		block_3.y = 0.0f + y;
		block_3.z = 1.0f + z;
		block_3.position = 2;
		block_3.type = "across";

		UpdateCollisionBox(block_3);

		block_4.x = 0.0f + x;
		block_4.y = 1.0f + y;
		block_4.z = 0.0f + z;
		block_4.position = 1;
		block_4.type = "across";

		UpdateCollisionBox(block_4);


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

void Tetromino::InitializePosition(int size_x, int size_y, int size_z)
{
	x = size_x + x_displacement;
	y = size_y;
	z = int(size_z / 2);
}
