#include <iostream>
#include <raylib.h>
#include "Board.h"
#include <iterator>
using namespace std;
#pragma once

void Board::Draw(float delta)
{
	// DrawCube({ x, y, z }, width, height, length, GRAY);
	// DrawCubeWires({ x, y, z }, width, height, length, RED);

	for (int i = 0; i < board.size(); i++)
	{
		//cout << 'i: ' << i << endl;
		//DrawCube({ left_wall_bounding_box.min.x, left_wall_bounding_box.min.y, left_wall_bounding_box.min.z}, left_wall_bounding_box.max.x, left_wall_bounding_box.max.y, left_wall_bounding_box.max.z, PINK);
		// DrawCube({ left_wall_bounding_box.min.x, 10.5, 0}, 1, 22, 1, PINK);
		// DrawCube({ left_wall_bounding_box.min.x, 10.5, 0}, 1, 22, 1, PINK);
		DrawLine3D({ 0,0,0 }, { 5,5,5 }, RED);

		if (board[i][1] == 0 || board[i][1] == size_y - 1)
		{
			// DrawCube({ board[i][0], board[i][1], board[i][2] }, block_width, block_height, block_length, BLUE);
			DrawCubeWires({ board[i][0], board[i][1], board[i][2] }, block_width, block_height, block_length, LIGHTGRAY);

		}
		else if (board[i][2] == 0 || board[i][2] == size_z - 1)
		{
			//DrawCube({ board[i][0], board[i][1], board[i][2] }, block_width, block_height, block_length, RED);
			DrawCubeWires({ board[i][0], board[i][1], board[i][2] }, block_width, block_height, block_length, LIGHTGRAY);
		}
		else {
			// DrawCube({ board[i][0], board[i][1], board[i][2] }, panel_width, panel_height, panel_length, GRAY);
			DrawCubeWires({ board[i][0], board[i][1], board[i][2] }, panel_width, panel_height, panel_length, LIGHTGRAY);

		}
	}
};

void Board::Update(float delta)
{};

void Board::GenerateBoard()
{
	int pos_y = 0;
	int pos_z = 0;
	for (int i = 0; i < size_y * size_z; i++)
	{
		if (pos_z == size_z)
		{
			pos_z = 0;
			pos_y += 1;
		}
		
		vector<float> v1d;
			// push x
			v1d.push_back(initial_pos_x);
			// push y
			v1d.push_back(pos_y);
			// push z
			v1d.push_back(pos_z);
		board.push_back(v1d);
		pos_z += 1;
	}

	cout << "---------------------" << endl;
	for (int i = 0; i < board.size(); i++)
	{
		/*
		cout << "***y: " << i << endl;
			cout << "x: " << board[i][0] << endl;
			cout << "y: " << board[i][1] << endl;
			cout << "z: " << board[i][2] << endl;
			cout << " " << endl;
		*/
	}


};

void Board::AddCollisionBoxes()
{

	// Left wall collision
	left_wall_bounding_box.min.x = initial_pos_x + 0 * block_width;
	left_wall_bounding_box.min.y = initial_pos_y + 0 * block_height;
	left_wall_bounding_box.min.z = initial_pos_z + 0 * block_length;

	left_wall_bounding_box.max.x = initial_pos_x + 1 * block_width;
	left_wall_bounding_box.max.y = initial_pos_y + size_y * block_height;
	left_wall_bounding_box.max.z = initial_pos_z + 1 * block_length;

	// Right wall collision
	right_wall_bounding_box.min.x = initial_pos_x + 0 * block_width;
	right_wall_bounding_box.min.y = initial_pos_y + 0 * block_height;
	right_wall_bounding_box.min.z = initial_pos_z + (size_z - 1) * block_length;  // REMEMBER TO SEE THIS : MAYBE I SHOULD DELETE THE -1

	right_wall_bounding_box.max.x = initial_pos_x + 0 * block_width;
	right_wall_bounding_box.max.y = initial_pos_y + (size_y - 1) * block_height;
	right_wall_bounding_box.max.z = initial_pos_z + size_z * block_length;

	// Floor collision
	floor_bounding_box.min.x = initial_pos_x + 0 * block_width;
	floor_bounding_box.min.y = initial_pos_y + (size_y - 1) * block_height;
	floor_bounding_box.min.z = initial_pos_z + (0 + 1) * block_length; 

	floor_bounding_box.max.x = initial_pos_x + 0 * block_width;
	floor_bounding_box.max.y = initial_pos_y + size_y * block_height;
	floor_bounding_box.max.z = initial_pos_z + (size_z - 1) * block_length;

	for (int i = 0; i < board.size(); i++)
	{
		//cout << 'i: ' << i << endl;

		if (board[i][1] == 0 || board[i][1] == size_y - 1)
		{
			
			// DrawCube({ board[i][0], board[i][1], board[i][2] }, block_width, height, length, BLUE);
		}
		else if (board[i][2] == 0 || board[i][2] == size_z - 1)
		{
			// DrawCube({ board[i][0], board[i][1], board[i][2] }, block_width, height, length, RED);
		}
	}

}
