#include <iostream>
#include <raylib.h>
#include <vector>
using namespace std;
#pragma once

class Board
{
private:

	// Panel Size
	// float panel_width = 0.2f;
	// Board individual block size
	// float block_width = 1.0f;

	// Board individual block size
	float panel_width = 0.2f;
	float panel_height = 1.0f;
	float panel_length = 1.0f;

	float block_width = 1.0f;
	float block_height = 1.0f;
	float block_length = 1.0f;

	float initial_pos_x = 1.0f;
	float initial_pos_y = 0.0f;
	float initial_pos_z = 0.0f;

	// vector<vector<vector<float>>> board;
	
	vector<vector<float>> board;
	vector<float> ::iterator it;
	// string color_flat = BLACK;



public:

	BoundingBox left_wall_bounding_box;
	BoundingBox right_wall_bounding_box;
	BoundingBox floor_bounding_box;
	vector<BoundingBox> collision_box_vector = { left_wall_bounding_box, right_wall_bounding_box, floor_bounding_box };
	// Board size
	int ceiling_floor = 2;
	int wall_wall = 2;
	int size_x = 0;
	int size_y = 20 + ceiling_floor; 
	int size_z = 10 + wall_wall;  
	void Draw(float delta);
	void Update(float delta);
	void GenerateBoard();
	void AddCollisionBoxes();
};

