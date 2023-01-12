#include "game.h"


int main() {
	srand((unsigned int)time(NULL));
	char arr[ROW][COL];
	
	int mode = 0;
	do {
		game_menu();
		scanf("%d", &mode);
		switch (mode)
		{
		case 1:
			game(arr);
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (mode);
	


	return 0;
}