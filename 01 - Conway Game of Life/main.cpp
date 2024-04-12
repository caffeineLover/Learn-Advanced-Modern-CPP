#include <iostream>
#include "use_ansi.h"
#include "grid.h"

using namespace std;


int main(int argc, char *argv[])
{
	cout << "Conway's game of Life" << endl;
	cout << "Press the return key to display each generation." << endl;
	cin.get();


	grid genCurrent;
	genCurrent.randomize();

	while (true)
	{
		genCurrent.draw();
		// cin.get();

		grid genNext;
		calculate( genCurrent, genNext );
		genCurrent.update( genNext );
	}
}
