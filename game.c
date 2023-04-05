#include "game.h"

void init_matrix(char grid[][COLMAX], char s_grid[][COLMAX], int density_alive) {
	//Set all char = .
	memset(grid, DEATH, sizeof(char) * ROWSMAX * COLMAX);
	memset (s_grid, DEATH, sizeof(char) * ROWSMAX * COLMAX);
	
	while (density_alive > 0) {
		int row = (rand() % ROWSMAX) - 1;
		int col = (rand() % COLMAX) - 1;
		row = row < 0 ? 0 : row;
		col = col < 0 ? 0 : col;
		grid[row][col] = ALIVE;
		density_alive--;
	}
}

void print_matrix(char grid[][COLMAX]) {
	for (size_t i = 0; i < ROWSMAX; i++) {
		for (size_t j = 0; j < COLMAX; j++) {
			printf("%c", grid[i][j]);
		}
		printf("\n");
	}
}

void make_death_or_alive(char f_grid[][COLMAX], char s_grid[][COLMAX], int c_alive, int row, int col) {
	if ( f_grid[row][col] == DEATH && c_alive == 3 )
		s_grid[row][col] = ALIVE;

	else if ( f_grid[row][col] == ALIVE && (c_alive > 3 || c_alive == 1) )
		s_grid[row][col] = DEATH;
	
	else if ( f_grid[row][col] == ALIVE )
		s_grid[row][col] = ALIVE;
	
	else
		return;
}

void check_alive(char grid[][COLMAX], int *alive, int *death, int row, int col) {
	if (grid[row][col] == ALIVE)
		(*alive)++;
	else
		(*death)++;
}

void check_col(char grid[][COLMAX], char s_grid[][COLMAX], int row, int col) {
	int alive_nr = 0;
	int death_nr = 0;

	if ( row == 0) {
		switch (col) {
			case 0:
				check_alive(grid, &alive_nr, &death_nr, RIGHT_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, RIGHT_UNDER_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, UNDER_CELL(row, col));
				make_death_or_alive(grid, s_grid, alive_nr, row, col);
				break;
			
			case (COLMAX - 1):
				check_alive(grid, &alive_nr, &death_nr, LEFT_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, LEFT_UNDER_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, UNDER_CELL(row, col));
				make_death_or_alive(grid, s_grid, alive_nr, row, col);
				break;

			default:
				check_alive(grid, &alive_nr, &death_nr, LEFT_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, LEFT_UNDER_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, UNDER_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, RIGHT_UNDER_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, RIGHT_CELL(row, col));
				make_death_or_alive(grid, s_grid, alive_nr, row, col);
				break;
		}
	
	} else if ( row == ROWSMAX) {
		switch (col) {
			case 0:
				check_alive(grid, &alive_nr, &death_nr, RIGHT_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, UP_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, RIGHT_UP_CELL(row, col));
				make_death_or_alive(grid, s_grid, alive_nr, row, col);
				break;
			
			case (COLMAX - 1):
				check_alive(grid, &alive_nr, &death_nr, LEFT_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, LEFT_UP_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, UP_CELL(row, col));
				make_death_or_alive(grid, s_grid, alive_nr, row, col);
				break;
			
			default:
				check_alive(grid, &alive_nr, &death_nr, LEFT_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, LEFT_UP_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, UP_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, RIGHT_UP_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, RIGHT_CELL(row, col));
				make_death_or_alive(grid, s_grid, alive_nr, row, col);
				break;
		}
	
	} else {
		switch (col) {
			case 0:
				check_alive(grid, &alive_nr, &death_nr, UP_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, RIGHT_UP_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, RIGHT_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, RIGHT_UNDER_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, UNDER_CELL(row, col));
				make_death_or_alive(grid, s_grid, alive_nr, row, col);
				break;
			
			case (COLMAX - 1):
				check_alive(grid, &alive_nr, &death_nr, UP_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, LEFT_UP_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, LEFT_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, LEFT_UNDER_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, UNDER_CELL(row, col));
				make_death_or_alive(grid, s_grid, alive_nr, row, col);
				break;
			
			default:
				check_alive(grid, &alive_nr, &death_nr, UP_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, RIGHT_UP_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, RIGHT_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, RIGHT_UNDER_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, UNDER_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, LEFT_UNDER_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, LEFT_CELL(row, col));
				check_alive(grid, &alive_nr, &death_nr, LEFT_UP_CELL(row, col));
				make_death_or_alive(grid, s_grid, alive_nr, row, col);
				break;
		}
	}
}

void upt_matrix(char f_grid[][COLMAX], char s_grid[][COLMAX]) {
	for (size_t i = 0; i < ROWSMAX; i++) {
		for (size_t j = 0; j < COLMAX; j++) {
			check_col(f_grid, s_grid, i, j);
		}
	}
}

void make_equal_generation(char f_grid[][COLMAX], char s_grid[][COLMAX]) {
	for (size_t i = 0; i < ROWSMAX; i++) {
		for (size_t j = 0; j < COLMAX; j++) {
			f_grid[i][j] = s_grid[i][j];
		}
	}
}

void crt_new_generation(char f_grind[][COLMAX], char s_grind[][COLMAX]) {
	upt_matrix(f_grind, s_grind);
	make_equal_generation(f_grind, s_grind);
}


/* Start Seed */
void seed_plus(char grid[][COLMAX], char s_grid[][COLMAX]) {

	memset(grid, DEATH, sizeof(char) * ROWSMAX * COLMAX);
	memset(s_grid, DEATH, sizeof(char) * ROWSMAX * COLMAX);

	size_t i = ROWSMAX/2;
	size_t j = COLMAX/2;
	size_t tmp = i;

	int offset = 0;

	while ( tmp > 1 ) {
		grid[i + offset][j] = ALIVE;
		grid[i - offset][j] = ALIVE;
		offset++;
		tmp--;
	}

	tmp = j;
	offset = 0;

	while ( tmp > 1) {
		grid[i][j + offset] = ALIVE;
		grid[i][j - offset] = ALIVE;
		offset++;
		tmp--;
	}
}