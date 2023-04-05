#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWSMAX 50
#define COLMAX	100
#define DEATH 46
#define ALIVE 42
#define UP_CELL(row, col)			row-1, col
#define LEFT_CELL(row, col)			row, col-1
#define RIGHT_CELL(row, col)		row, col+1
#define UNDER_CELL(row, col)		row+1, col
#define LEFT_UP_CELL(row, col)		row-1, col-1
#define RIGHT_UP_CELL(row, col)		row-1, col+1
#define LEFT_UNDER_CELL(row, col)	row+1, col-1
#define RIGHT_UNDER_CELL(row, col)	row+1, col+1

enum _bool {
	true = 1,
	false = 0
};
typedef enum _bool bool;

void init_matrix(char grid[][COLMAX], char s_grid[][COLMAX], int density_alive);
void print_matrix(char grid[][COLMAX]);
void make_death_or_alive(char grid[][COLMAX], char s_grid[][COLMAX], int c_alive, int row, int col);
void check_alive(char grid[][COLMAX], int *alive, int *death, int row, int col);
void check_col(char grid[][COLMAX], char s_grid[][COLMAX], int row, int col);
void upt_matrix(char f_grid[][COLMAX], char s_grid[][COLMAX]);
void make_equal_generation(char f_grid[][COLMAX], char s_grid[][COLMAX]);
void crt_new_generation(char f_grind[][COLMAX], char s_grind[][COLMAX]);

/* Start Seed*/
void seed_plus(char grid[][COLMAX], char s_grid[][COLMAX]);
#endif