#include "game.h"

void game_menu()
{
	printf("**************************\n");
	printf("********三子棋游戏********\n");
	printf("******* 1.开始游戏  ******\n");
	printf("******* 0.退出游戏  ******\n");
	printf("**************************\n");
	printf("请输入>");
}



void init_game(char arr[][COL]) {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			arr[i][j] = ' ';

		}
	}
}

void checkerboard(char arr[][COL])
{
	for (int i = 0; i < ROW; i++) {
		printf("\n");
		for (int j = 0; j < COL; j++) {
			printf(" %c ", arr[i][j]);
			if (j < COL - 1) {
				printf(" | ");
			}
		}
		printf("\n");
		for (int j = 0; j < COL; j++) {
			
			if (i < ROW - 1) {
				printf("---");
				if (j < COL - 1) {
					printf(" | ");
				}
			}
			
		}
	}
	printf("\n");
}

void player_move(char arr[][COL])
{
	int x = 0;
	int y = 0;
	
	while (1) {
		printf("请用户输入下棋坐标>");
		scanf("%d %d", &x, &y);
		if (x > 0 && x < 4 && y>0 && y < 4) {
			if (arr[x - 1][y - 1] == ' ') {
				arr[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("坐标以占用，重新输入！");
			}
		}
		else {
			printf("坐标超出边界，重新输入！");
		}
	}
	
}

void computer_move(char arr[][COL]) {
	printf("电脑下棋为>");
	while (1) {
		int x = rand() % ROW;
		int y = rand() % COL;
		if (arr[x][y] == ' ') {
			arr[x][y] = '#';
			break;
		}
	}
	
}

char is_win(char arr[][COL]) {
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++) {
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][1] != ' ') {
			return arr[i][1];
		}
	}
	for (i = 0; i < COL; i++) {
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[1][i] != ' ') {
			return arr[1][i];
		}
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != ' ') {
		return arr[1][1];
	}
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != ' ') {
		return arr[1][1];
	}
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COL; j++) {
			if (arr[i][j] == ' ') {
				return 'c';
			}
		}
	}
	return 'p';
}

void game(char arr[][COL]) {
	init_game(arr);
	checkerboard(arr);
	char temp = 0;
	while (1) {
		player_move(arr);
		checkerboard(arr);
		temp=is_win(arr);
		if (temp != 'c') {
			break;
		}
		computer_move(arr);
		checkerboard(arr);
		temp=is_win(arr);
		if (temp != 'c') {
			break;
		}
	}
	if (temp == '*') {
		printf("玩家赢了！\n");
	}
	else if (temp == '#') {
		printf("电脑赢了！\n");
	}
	else {
		printf("平局！\n");
	}
}
