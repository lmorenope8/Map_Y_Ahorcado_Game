#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//funcion mostrar el mapa
void mapa() {
	char map[10][10], movimiento; //matriz del mapa 10x10
	int pX = 0, pY = 0, rX,rY; //posiciones iniciales del jugador (pX, pY) y reto (rX, rY) 
	srand(time(NULL)); //Inicializa el generador de numeros aleatorios
	rX = rand() % 10; //Genera posición aleatoria del eje X para el reto
	rY = rand() % 10; //Genera posición aleatoria del eje Y para el reto

	printf("HAZ QUE LA X LLEGUE A LA R PARA EMPEZAR EL RETO DEL AHORCADO!\n");
	//Llena el mapa de guiones
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			map[i][j] = '-';
		}
	}
	map[rX][rY] = 'R'; //coloca el reto en una posición aleatoria
	map[0][0] = 'X'; //coloca al jugador en la posición inicial 0,0

	//Bucle principal para mover al jugador hasta el reto
	while (map[pX][pY] != map[rX][rY]) {
		//mostrar mapa
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
		map[pX][pY] = '-'; // Sustituye por un guion la posicion anterior del jugador
		//Solicita el movimiento al usuario
		printf("Introduce el movimiento que quieras realizar: \nw. Moverse Arriba\ns. Moverse Abajo\na. Moverse Izquierda\nd. Moverse Derecha\n");
		scanf_s(" %c", &movimiento, 1);
		//procesa el movimiento
		switch (movimiento)
		{
		case 'w': //mover arriba
			if (pX > 0 || pX < 9) {
				pX--;
			}
			else {
				printf("Movimiento invalido");
			}
			break;
		case 's': //mover abajo
			if (pX > 0 || pX < 9) {
				pX++;
			}
			else {
				printf("Movimiento invalido");
			}
			break;
		case 'a': //mover izquierda
			if (pY > 0 || pY < 9) {
				pY--;
			}
			else {
				printf("Movimiento invalido");
			}
			break;
		case 'd': //mover derecha
			if (pY > 0 || pY < 9) {
				pY++;
			}
			else {
				printf("Movimiento invalido");
			}
			break;
		default:
			printf("Movimiento no reconocido\n");
			break;
		}
		map[pX][pY] = 'X';
	}
}
//funciones de los niveles del ahorcado
void nivelfacil() {	
		srand(time(NULL)); //inicia el generador de numeros aleatorios
	//10 Palabras para el nivel facil
	char palabras[10][20] = { "sal",
								"pato",
								"fresa",
								"gato",
								"gris",
								"casa",
								"dado",
								"vaca",
								"mango",
								"luna" };
	int randWord = rand() % 10; //Selecciona una palabra aleatoria
	char respuesta[20];
	strcpy_s(respuesta, palabras[randWord]);// Se copia la palabra aleatoria en "respuesta"
	char letra, incorrectas[10] = { 0 }; // variable de las letras que introduce el usuario y array de letras incorrectas
	int longitud = strlen(respuesta), //longitud de la palabra random
		vidas = 3, //contador de vidas
		adivinada[20] = { 0 }, // Arreglo que guarda el estado de cada letra de la palabra a adivinar.
		contaIncorrectas = 0, //Contador de las letras incorrectas
		yaexiste=0; //Verificar si ya existe esa letra en la lista 
	printf("\n\nBienvenido al nivel Facil\n(introduce todas las letras en minuscula)\n\n");
	printf(" +---+\n"
		" |   |\n"
		"     |\n"
		"     |\n"
		"     |\n"
		"     |\n"
		"=========\n");
	while (vidas > 0) { //mientras queden vidas
		int completo = 1, acierto = 0;

		//muestra el progreso de la palabra
		for (int i = 0; i < longitud; i++) {
			if (adivinada[i]) {
				printf("%c", respuesta[i]);
			}
			else {
				printf("_ ");
			}
		}

		//muestra las letras incorrectas que ha introducido el usuario
		printf("\nLetras incorrectas: ");
		for (int i = 0; i < contaIncorrectas; i++)
		{
			printf("%c ", incorrectas[i]);
		}

		//solicita una letra al jugador
		printf("\nIntroduce una letra para ver si esta en la palabra:\n");
		scanf_s(" %c", &letra, 1);

		//Revisa si la letra está en la palabra
		for (int i = 0; i < longitud; i++) {
			if (strncmp(&respuesta[i], &letra, 1) == 0) {
				adivinada[i] = 1;
				acierto = 1;
			}
		}

		//si la letra no está en la palabra:
		if (!acierto) {
			vidas--; //Restamos vidas
			printf("La letra que has introducido no esta en la palabra, te quedan %d vidas\n", vidas);

			//Agregamos la letra a las incorrectas si aun no está
			for (int i = 0; i < contaIncorrectas; i++)
			{
				if (incorrectas[i] == letra) {
					yaexiste = 1;
					break;
				}
			}
			if (!yaexiste && contaIncorrectas < 10) {
				incorrectas[contaIncorrectas] = letra;
				contaIncorrectas++;
			}
		}
		//Dibujo del ahorcado segun las vidas que tenemos
		switch (vidas) {
		case 3:
			printf(" +---+\n"
				" |   |\n"
				"     |\n"
				"     |\n"
				"     |\n"
				"     |\n"
				"=========\n");
			break;
		case 2:
			printf(" +---+\n"
				" |   |\n"
				" O   |\n"
				"     |\n"
				"     |\n"
				"     |\n"
				"=========\n");
			break;
		case 1:
			printf(" +---+\n"
				" |   |\n"
				" O   |\n"
				" |   |\n"
				"     |\n"
				"     |\n"
				"=========\n");
			break;
		case 0:
			printf(" +---+\n"
				" |   |\n"
				" O   |\n"
				"/|\\  |\n"
				"/ \\  |\n"
				"     |\n"
				"=========\n");
			break;
		}
		//Verificar si todas las letras han sido adivinadas
		for (int i = 0; i < longitud; i++)
		{
			if (!adivinada[i]) {
				completo = 0;
			}
		}
		//Mensaje de felicidades si gana el jugador (si ha adivinado la palabra)
		if (completo) {
			printf("Felicidades!!! Has adivinado la palabra %s\n", respuesta);
			break;
		}
	}
	//Mensaje avisando de que el jugador ha perdido el juego si pierde todas las vidas
	if (vidas == 0) {
		printf("Has perdido :(\n La palabra era: %s\n", respuesta);
	}
}
//las siguientes funciones son similares al anterior pero con palabras de mayor dificultad cada vez
void nivelmedio() {

	srand(time(NULL));
	char palabras[10][20] = { "mandarina",
								"chaleco",
								"fantasma",
								"albaricoque",
								"lechuza",
								"cepillo",
								"carroza",
								"pelicula",
								"terreno",
								"mancuerna" };
	int randWord = rand() % 10;
	char respuesta[20];
	strcpy_s(respuesta, palabras[randWord]);
	char letra, incorrectas[10] = { 0 };
	int longitud = strlen(respuesta), vidas = 3, adivinada[20] = { 0 }, contaIncorrectas = 0, yaexiste = 0;

	printf("\n\nBienvenido al nivel medio\n(introduce todas las letras en minuscula)\n\n");
	printf(" +---+\n"
		" |   |\n"
		"     |\n"
		"     |\n"
		"     |\n"
		"     |\n"
		"=========\n");
	while (vidas > 0) {
		int completo = 1, acierto = 0;

		for (int i = 0; i < longitud; i++) {
			if (adivinada[i]) {
				printf("%c", respuesta[i]);
			}
			else {
				printf("_ ");
			}
		}

		printf("\nLetras incorrectas: ");
		for (int i = 0; i < contaIncorrectas; i++)
		{
			printf("%c ", incorrectas[i]);
		}

		printf("\nIntroduce una letra para ver si esta en la palabra:\n");
		scanf_s(" %c", &letra, 1);

		for (int i = 0; i < longitud; i++) {
			if (strncmp(&respuesta[i], &letra, 1) == 0) {
				adivinada[i] = 1;
				acierto = 1;
			}
		}
		if (!acierto) {
			vidas--;
			printf("La letra que has introducido no esta en la palabra, te quedan %d vidas\n", vidas);

			for (int i = 0; i < contaIncorrectas; i++)
			{
				if (incorrectas[i] == letra) {
					yaexiste = 1;
					break;
				}
			}
			if (!yaexiste && contaIncorrectas < 10) {
				incorrectas[contaIncorrectas] = letra;
				contaIncorrectas++;
			}
		}

		switch (vidas) {
		case 3:
			printf(" +---+\n"
				" |   |\n"
				"     |\n"
				"     |\n"
				"     |\n"
				"     |\n"
				"=========\n");
			break;
		case 2:
			printf(" +---+\n"
				" |   |\n"
				" O   |\n"
				"     |\n"
				"     |\n"
				"     |\n"
				"=========\n");
			break;
		case 1:
			printf(" +---+\n"
				" |   |\n"
				" O   |\n"
				" |   |\n"
				"     |\n"
				"     |\n"
				"=========\n");
			break;
		case 0:
			printf(" +---+\n"
				" |   |\n"
				" O   |\n"
				"/|\\  |\n"
				"/ \\  |\n"
				"     |\n"
				"=========\n");
			break;
		}

		for (int i = 0; i < longitud; i++)
		{
			if (!adivinada[i]) {
				completo = 0;
			}
		}
		if (completo) {
			printf("Felicidades!!! Has adivinado la palabra %s\n", respuesta);
			break;
		}
	}
	if (vidas == 0) {
		printf("Has perdido :(\n La palabra era: %s\n", respuesta);
	}
}
void nivelalto() {

	srand(time(NULL));
	char palabras[5][20] = { "quehacer",
								"desarrollar",
								"sacacorchos",
								"sangijuela",
								"tejemaneje"};
	int randWord = rand() % 10;
	char respuesta[20];
	strcpy_s(respuesta, palabras[randWord]);
	char letra, incorrectas[10] = { 0 };
	int longitud = strlen(respuesta), vidas = 3, adivinada[20] = { 0 }, contaIncorrectas = 0, yaexiste = 0;

	printf("\n\nBienvenido al nivel dificil\n(introduce todas las letras en minuscula)\n\n");
	printf(" +---+\n"
		" |   |\n"
		"     |\n"
		"     |\n"
		"     |\n"
		"     |\n"
		"=========\n");
	while (vidas > 0) {
		int completo = 1, acierto = 0;

		for (int i = 0; i < longitud; i++) {
			if (adivinada[i]) {
				printf("%c", respuesta[i]);
			}
			else {
				printf("_ ");
			}
		}

		printf("\nLetras incorrectas: ");
		for (int i = 0; i < contaIncorrectas; i++)
		{
			printf("%c ", incorrectas[i]);
		}

		printf("\nIntroduce una letra para ver si esta en la palabra:\n");
		scanf_s(" %c", &letra, 1);

		for (int i = 0; i < longitud; i++) {
			if (strncmp(&respuesta[i], &letra, 1) == 0) {
				adivinada[i] = 1;
				acierto = 1;
			}
		}
		if (!acierto) {
			vidas--;
			printf("La letra que has introducido no esta en la palabra, te quedan %d vidas\n", vidas);

			for (int i = 0; i < contaIncorrectas; i++)
			{
				if (incorrectas[i] == letra) {
					yaexiste = 1;
					break;
				}
			}
			if (!yaexiste && contaIncorrectas < 10) {
				incorrectas[contaIncorrectas] = letra;
				contaIncorrectas++;
			}
		}

		switch (vidas) {
		case 3:
			printf(" +---+\n"
				" |   |\n"
				"     |\n"
				"     |\n"
				"     |\n"
				"     |\n"
				"=========\n");
			break;
		case 2:
			printf(" +---+\n"
				" |   |\n"
				" O   |\n"
				"     |\n"
				"     |\n"
				"     |\n"
				"=========\n");
			break;
		case 1:
			printf(" +---+\n"
				" |   |\n"
				" O   |\n"
				" |   |\n"
				"     |\n"
				"     |\n"
				"=========\n");
			break;
		case 0:
			printf(" +---+\n"
				" |   |\n"
				" O   |\n"
				"/|\\  |\n"
				"/ \\  |\n"
				"     |\n"
				"=========\n");
			break;
		}

		for (int i = 0; i < longitud; i++)
		{
			if (!adivinada[i]) {
				completo = 0;
			}
		}
		if (completo) {
			printf("Felicidades!!! Has adivinado la palabra %s\n", respuesta);
			break;
		}
	}
	if (vidas == 0) {
		printf("Has perdido :(\n La palabra era: %s\n", respuesta);
	}
}

//Funcion principal del programa
int main()
{
	int nivel;
	mapa(); //Llama al juego del mapa

	//Preguntar al usuario el nivel de dificultad para el ahorcado
	printf("\n\nQue nivel de ahorcado deseas realizar?\n1. Nivel Facil\n2. Nivel Medio\n3. Nivel Dificil\n");
	scanf_s("%d", &nivel);

	//Llama a la funcion correspondiente de nivel
	switch (nivel) {
	case 1:
		nivelfacil();
		break;
	case 2:
		nivelmedio();
		break;
	case 3:
		nivelalto();
		break;
	default:
		printf("Tu respuesta no esta entre mis opciones :(");
		break;
	}
}