#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void mapa() {
	char map[10][10];
	int movimiento = 0, pX = 0, pY = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			map[i][j] = '-';
		}
	}
	map[4][4] = 'R';
	map[0][0] = 'X';

	while (map[pX][pY] != map[4][4]) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
		map[pX][pY] = '-';
		printf("Introduce el movimiento que quieras realizar: \n1. Moverse Arriba\n2. Moverse Abajo\n3. Moverse Izquierda\n4. Moverse Derecha\n");
		scanf_s("%d", &movimiento);
		switch (movimiento)
		{
		case 1:
			if (pX > 0 || pX < 9) {
				pX--;
			}
			else {
				printf("Movimiento invalido");
			}
			break;
		case 2:
			if (pX > 0 || pX < 9) {
				pX++;
			}
			else {
				printf("Movimiento invalido");
			}
			break;
		case 3:
			if (pY > 0 || pY < 9) {
				pY--;
			}
			else {
				printf("Movimiento invalido");
			}
			break;
		case 4:
			if (pY > 0 || pY < 9) {
				pY++;
			}
			else {
				printf("Movimiento invalido");
			}
			break;
		default:
			break;
		}
		map[pX][pY] = 'X';
	}
}

int main()
{
	char respuesta[10] = { "mandarina" }, letra;
	//mapa();
	printf("\nBienvenido al juego del ahorcado\n");
	for (int i = 0; i < 9; i++)
	{
		printf("-");
	}

	printf("\nIntroduce una letra para ver si esta en la palabra:\n");
	scanf_s("%c", &letra, 1);

	for (int i = 0; i < 9; i++) {
		if (respuesta[i] = letra) {
			printf("%c", letra);
		}
		else {
			printf("-");
		}
	}

}