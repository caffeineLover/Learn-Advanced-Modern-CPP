#pragma once
#include "cell.h"



class grid
{
	// We have a border consisting of inactive cells.  These are used for calculation of the next generation
	// of cells, but are not displayed on the screen.
	cell cells[rowmax+2][colmax+2];


	public:
		void create(int row, int col);
		void draw();
		void randomize();
		bool will_survive(int row, int col);
		bool will_create(int row, int col);
		void update(const grid& next);
};


// Non-member functions
// Calculate which cells survive to the next generation.
void calculate( grid& old_generation, grid& new_generation);