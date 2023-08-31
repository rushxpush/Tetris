#include <iostream>
#include <raylib.h>
#include "Board.h"
using namespace std;
#pragma once

void Board::Draw()
{

	// DrawCube({ x, y, z }, width, height, length, GRAY);
	// DrawCubeWires({ x, y, z }, width, height, length, RED);

	for (int i = 0; i < board.size(); i++)
	{
		//cout << 'i: ' << i << endl;

		DrawCube({ x, board[i][0], board[i][1] }, width, height, length, GRAY);
		DrawCubeWires({ x, board[i][0], board[i][1] }, width, height, length, LIGHTGRAY);
	}
};

void Board::Update()
{};

void Board::GenerateBoard()
{

};
