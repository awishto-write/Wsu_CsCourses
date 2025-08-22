#define _CRT_SECURE_NO_WARNINGS
#define MAX_ROWS 10
#define MAX_COLS 10

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#define HIT '*'
#define MISS 'm'
#define WATER '-'

#define CARRIER 'c'
#define BATTLESHIP 'b'
#define CRUISER 'r'
#define SUBMARINE 's'
#define DESTROYER 'd'


typedef enum dir
{
	horizontal = 0, vertical = 1

} Dir;

typedef struct coordinate
{
	int row;
	int col;

}Coordinate;

typedef struct ship
{
	char* name;
	char symbol;
	int length;

} Ship;

typedef struct stats
{
	int total_shots;
	int total_misses;
	int total_hits;
	double hit_miss_ratio;

}Stats;

int welcome_screen_rules_menu(void);

void init_board(char board[][MAX_COLS], int num_rows, int num_cols);
void print_board(char board[][MAX_COLS], int num_rows, int num_cols, bool hides);

int who_starts_first(void);
int ship_placement_option(void);

Dir generate_dir(void);
void generate_starting_point(Coordinate* start_pt_ptr, Dir direction, int length);

void manually_place_ships(char board[][MAX_COLS], int num_rows, int num_cols, Ship ship[]);
void randomly_place_ships(char board[][MAX_COLS], int num_rows, int num_cols, Ship ship[]);

int is_valid(char board[][MAX_COLS], int num_rows, int num_cols, Coordinate start_pt, Dir direction, int length);
int shot_valid(int row_target, int col_target);
bool is_ships_sunk(int sunkships[]);

void computer_shot(char board[][MAX_COLS], int num_rows, int num_cols, FILE* outfile, Stats stat, int shots[][MAX_COLS], int sunk_ships[]);
void player_shot(char board[][MAX_COLS], int num_rows, int num_cols, FILE* outfile, Stats stat, int sunk_ships[]);

void output_stats(Stats p1_stats, Stats p2_stats, FILE* outfile);