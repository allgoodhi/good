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
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	} while (mode);
	


	return 0;
}