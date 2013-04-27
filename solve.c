#include "decide.h"
#include "move.h"
#include "walls.h"

// solve the maze
void solve(void) {
    while (1){
		// move forward 1 cell
		track();

		// stop
		stop();

		// get direction and turn
		turn(r_wall());

		// stop again
		stop();
	}
}
