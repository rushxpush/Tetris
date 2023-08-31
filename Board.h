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
	int size_x = 0;
	int size_y = 20;
	int size_z = 10;

	// vector<vector<vector<float>>> board;
	
	vector<vector<float>> board;
	vector<float> ::iterator it;
	// string color_flat = BLACK;

public:
	void Draw(float delta);
	void Update(float delta);
	void GenerateBoard();
};

