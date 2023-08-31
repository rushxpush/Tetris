#include <iostream>
#include <raylib.h>
#include <vector>
using namespace std;
#pragma once

class Board
{
private:
	float width = 0.2f;
	float height = 1.0f;
	float length = 1.0f;
	float x = 1.0f;
	float y = 0.0f;
	float z = 0.0f;
	int size_x = 10;
	int size_y = 10;
	//vector<float> board;
	vector<vector<float>> board
	{
		{0, 0},
		{0, 1},
		{0, 2},
		{0, 3},
		{0, 4},
		{0, 5},
		{0, 6},
		{0, 7},
		{1, 0},
		{1, 1},
		{1, 2},
		{1, 3},
		{1, 4},
		{1, 5},
		{1, 6},
		{1, 7},
		{2, 0},
		{2, 1},
		{2, 2},
		{2, 3},
		{2, 4},
		{2, 5},
		{2, 6},
		{2, 7},
	};
	// string color_flat = BLACK;

public:
	void Draw();
	void Update();
	void GenerateBoard();
};

