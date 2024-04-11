#pragma once

const char live_cell{'X'};
const char dead_cell{' '};

// Standard ANSI terminals have 24 rows and 80 columns, but we're going to leave a 1 character border
// around the edge that will always be unpopulated, so rows go from 1 to 23 and cols go from 1 to 79.
const int rowmax = 23;
const int colmax = 79;

// Conway's parameters: conditions for life
const int min_neighbors = 2;
const int max_neighbors = 3;
const int min_parents = 3;
const int max_parents = 3;
