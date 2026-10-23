#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}


//Inicializar la matriz dinámica
int sucursales;
int numMeses;

void* callocMatriz(int sucursales, int numMeses) //Le metemos las sucursales y los meses.
{
	//Reservamos memoria para el arreglo de punteros que en mi matriz son las filas
	int** matriz = new int* [sucursales];

		for (int i = 0; i < sucursales; i++)
		{
			//Reservamos memoria para cada una de las columnas de cada fila
			matriz[i] = new int[numMeses];

			//Inicializamos la matriz con ceros porque así es calloc
			for (int j = 0; j < numMeses; j++)
			{
				//Se guarda 0 en x y y
				matriz[i][j] = 0;
			}
		}
	return matriz;
}

