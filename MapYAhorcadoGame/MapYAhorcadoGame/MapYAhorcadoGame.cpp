#include <stdio.h>

int main()
{
	char map[10][10], usuario='X', joc='R';
	int movimiento;
	for (int i = 0; i < 10; i++) {
		for(int j=0; j< 10; j++){
			map[i][j] = '-';
		}
	}
	map[4][4] = joc;
	map[0][0] = usuario;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}