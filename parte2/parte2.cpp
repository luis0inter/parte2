// parte2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>

int main()
{
	int sucursales, mesas, menu;
	bool continuar = true;

	printf("Ingrese el numero de sucursales: ");
	scanf("%d", &sucursales);

	printf("Ingrese el numero de mesas: ");
	scanf("%d", &mesas);

	int *matriz = (int*)calloc(sucursales, sizeof(int));

	if(matriz == NULL){
		printf("Error al asignar memoria\n");
		return 1;
	}

	do{
		printf("Seleccione una opción:\n");
		printf("1. Registrar o actualizar las ventas de una sucursal en un mes determinado.\n");
		printf("2. Consultar las ventas de una sucursal en un mes determinado.\n");
		printf("3. Calcular las ventas totales de cada sucursal.\n");
		printf("4. Identificar la sucursal con mayores ventas acumuladas.\n");
		printf("5. Mostrar la matriz completa.\n");
		printf("6. Salir.\n");
		scanf("%d", &menu);

		switch (menu) {
			case 1:
				// Registrar o actualizar las ventas de una sucursal en un mes determinado
				break;
			case 2:
				// Consultar las ventas de una sucursal en un mes determinado
				break;
			case 3:
				// Calcular las ventas totales de cada sucursal
				break;
			case 4:
				// Identificar la sucursal con mayores ventas acumuladas
				break;
			case 5:
				// Mostrar la matriz completa
				break;
			case 6:
				continuar = false;
				break;
			default:
				printf("Opción no válida\n");
		}
	} while (!continuar);

	free(matriz);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
