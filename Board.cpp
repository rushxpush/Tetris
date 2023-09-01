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

		if (board[i][1] == 0 || board[i][1] == size_y - 1)
		{
			DrawCube({ board[i][0], board[i][1], board[i][2] }, wall_width, height, length, BLUE);
			DrawCubeWires({ board[i][0], board[i][1], board[i][2] }, wall_width, height, length, LIGHTGRAY);
		}
		else if (board[i][2] == 0 || board[i][2] == size_z - 1)
		{
			DrawCube({ board[i][0], board[i][1], board[i][2] }, wall_width, height, length, RED);
			DrawCubeWires({ board[i][0], board[i][1], board[i][2] }, wall_width, height, length, LIGHTGRAY);
		}
		else {
			DrawCube({ board[i][0], board[i][1], board[i][2] }, width, height, length, GRAY);
			DrawCubeWires({ board[i][0], board[i][1], board[i][2] }, width, height, length, LIGHTGRAY);

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
			v1d.push_back(x);
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
