#ifndef _GAME_H
#define _GAME_H
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3

void checkerboard(char arr[][COL]);
void game(char arr[][COL]);
void init_game(char arr[][COL]);
void game_menu();
void player_move(char arr[][COL]);
void computer_move(char arr[][COL]);
char is_win(char arr[][COL]);

#endif
