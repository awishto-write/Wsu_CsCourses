#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define HAND_SIZE 5                
#define FACE_TYPES 13
#define SUIT_TYPES 4


typedef struct cards
{
    int  suit_index;
    int  face_value_index;

} Cards;

typedef struct hand
{
    Cards hand_array[5];

} Hand;

void game_menu(void);
void print_rules(void);
int get_option(void);


void shuffle(int wDeck[][13]);
void deal(const int wDeck[][13], Hand* poker, int amount, int* current_card);
void print_hand(Hand poker, const char* wFace[], const char* wSuit[]);

void dealOneCard(const int wDeck[][13], Hand* poker, int index, int* current_card);

void calcNumTimes(Hand poker, int numTimes[13]);

int contains_a_pair(Hand poker, int numTimes[13]);
int contains_two_pairs(Hand poker, int numTimes[13]);
int contains_three_kind(Hand poker, int numTimes[13]);
int contains_straight(Hand poker, int numTimes[13]);

int contains_four_kind(Hand poker, int numTimes[13]);
void calcCountSuit(Hand poker, int suitCount[4]);
int contains_flush(Hand poker, int suitCount[4]);

int evaluate_hand(Hand poker);
int dealer_draw(Hand poker, int player_score, int dealer_score);
