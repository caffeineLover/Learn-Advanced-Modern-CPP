#pragma once
#include <iostream>
#include "life.h"



// This is really just a wrapper around a boolean.
//
class cell
{
	bool alive_;

public:
	// By default, a cell is created as not alive.
	cell(): alive_(false) {}

	// Draw the cell on the grid.
	void draw(int row, int col) const;

	// Bring cell to life
	void create() {
		alive_ = true;
	}

	// End cell's life
	void erase() {
		alive_ = false;
	}

	bool is_alive() const
	{
		return alive_;
	}


};