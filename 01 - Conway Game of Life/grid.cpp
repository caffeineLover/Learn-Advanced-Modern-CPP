#include "grid.h"
using std::cout;



void grid::create(int row, int col)
{
	cells[row][col].create();
}



// ANSI control commands:
//	\x1b means "escape"
//	Escape[2J clears the screen and sends the cursor to the "home" position.
//
void grid::draw()
{
	cout << "\x1b[2J";

	for (int row = 1; row < rowmax; ++row)
		for (int col = 1; col < colmax; ++col)
			cells[row][col].draw(row, col);
}


// Populate the grid with cells at random in the beginning of the simulation.
//
void grid::randomize()
{
	// A factor of 5 means there's a 1 in 5 chance (20%) that a cell starts off alive.
	const int factor = 5;
	const int cutoff = RAND_MAX/factor;
	time_t now;
	time(&now);
	// srand(now);

	for (int row = 1; row < rowmax; ++row)
		for (int col = 1; col < colmax; ++col)
			if( rand()/cutoff == 0)
				create(row, col);
}



// Will the cell at (row, column) survive to the next generation?
//
bool grid::will_survive(int row, int col)
{
	// If there's no live cell there right now, it obviously can't survive.  It *could* be generated, but that's
	// a separate process -- for now, we're just checking if already alive cells will survive.
	if (!cells[row][col].is_alive())
		return false;

	// Find the number of live neighbors.
	int neighbors = cells[row - 1][col - 1].is_alive()
				  + cells[row - 1][col + 1].is_alive()
				  + cells[row][col - 1].is_alive()
				  + cells[row][col + 1].is_alive()
				  + cells[row + 1][col - 1].is_alive()
				  + cells[row + 1][col + 1].is_alive();

	// The cell has too few or too many neighbors, so it died.
	if (neighbors < min_neighbors || neighbors > max_neighbors)
		return false;

	return true;
}



// Will the cell at (row, column) survive to the next generation?
//
bool grid::will_create(int row, int col)
{
	// There's already a live cell here, so we don't need to create it.
	if (!cells[row][col].is_alive())
		return false;

	// Find the number of live parents.
	int parents = cells[row - 1][col - 1].is_alive()
				+ cells[row - 1][col + 1].is_alive()
				+ cells[row][col - 1].is_alive()
				+ cells[row][col + 1].is_alive()
				+ cells[row + 1][col - 1].is_alive()
				+ cells[row + 1][col + 1].is_alive();

	// The cell has too few or too many neighbors, so it died.
	if (parents < min_parents || parents > max_parents)
		return false;

	return true;
}


// Promote the newly calculated next generation to the current generation.
void grid::update(const grid& next)
{
	for( int row = 1; row < rowmax; ++row )
		for( int col = 1; col < colmax; ++col )
			cells[row][col] = next.cells[row][col];
}


// This function oversees the simulation process.
//
// By default, all cells in the next generation are initially unpopulated.
// Calculate which live cells survive to the next gneration and which
// unpopulated cells are populated in the next generation.
//
void calculate(grid& old_generation, grid& new_generation)
{
	for (int row = 1; row < rowmax; ++row)
		for (int col = 1; col < colmax; ++col)
		{
			if( old_generation.will_survive(row, col) )
				new_generation.create(row, col);
			else if( old_generation.will_create(row, col))
				new_generation.create(row, col);
		}
}