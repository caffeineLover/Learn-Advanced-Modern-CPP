#include "cell.h"
using std::cout;



void cell::draw(int row, int col) const
{
	// ANSI control commands
	// 
	// escape[n;mH moves the cursor to row n, col m.
	// Note: These are 1-based, i.e. row 1 is the first row!

	cout << "\x1b[" << row + 1 << ";" << col + 1 << "H";
	cout << (alive_ ? live_cell : dead_cell);
}