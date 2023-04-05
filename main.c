#include "game.h"

void clear_terminal() { printf("\033[2J\033[1;1H"); }

int main() {
	srand(time(NULL));
	char grid[ROWSMAX][COLMAX];
	char s_grid[ROWSMAX][COLMAX];
	int density_alive = (ROWSMAX*COLMAX)/20;

	//init_matrix(grid, s_grid, density_alive);
	seed_plus(grid, s_grid);

	int ch;
	do {
		clear_terminal();
		print_matrix(grid);
		crt_new_generation(grid, s_grid);
	}while ( (ch = getchar()) != 'q');

	return 0;
}