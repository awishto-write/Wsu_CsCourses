#define _CRT_SECURE_NO_WARNINGS

#include<math.h>
#include<stdio.h>

#include<stdlib.h>
#include<time.h>
#include<string.h>

#include <ctype.h>


int print_menu(int menu_choice);
void print_rules(void);

void play_game(void);

int roll_die(void);
int alternations(int array_check[]);

int sum(int z, int dice_value[]);  

int final_score(int *dice_value, int array_check[]);   

