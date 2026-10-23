
#include <iostream>
#include <new>

using namespace std;

// Funcion para crear e inicializar la matriz dinamica
int* callocMatriz(int sucursales, int numMeses)
{
    // Reservamos memoria para todas las ventas en un solo bloque
    int* matriz = new (nothrow) int[sucursales * numMeses];

    // Comprobamos si se pudo reservar memoria
    if (matriz == nullptr) {
        return nullptr;
    }
    // Recorremos las sucursales
    for (int i = 0; i < sucursales; i++) {
        // Recorremos los meses
        for (int j = 0; j < numMeses; j++)
        {
            // Inicializamos cada posicion en cero
            matriz[i * numMeses + j] = 0;
        }
    }

    return matriz;
}

int main() {
    int sucursales, meses;
    int opcion = 0;
    int sucursal, mes, monto, indice;
    long long total, mayor;

    cout << "CONTROL DE VENTAS\n";

    cout << "Numero de sucursales (1 a 1000): ";
    cin >> sucursales;

    cout << "Numero de meses (1 a 120): ";
    cin >> meses;

    // Validamos las cantidades ingresadas
    if (sucursales < 1 || sucursales > 1000 || meses < 1 || meses > 120)
    {
        cout << "Cantidad de sucursales o meses no valida.\n";
        return 1;
    }

    // Llamamos a nuestra funcion para crear la matriz
    int* ventas = callocMatriz(sucursales, meses);

    if (ventas == nullptr)
    {
        cout << "No se pudo reservar memoria.\n";
        return 1;
    }

    do
    {
        cout << "\n----- MENU -----\n";
        cout << "1 -> Registrar o actualizar una venta\n";
        cout << "2 -> Consultar ventas de una sucursal\n";
        cout << "3 -> Mostrar totales por sucursal\n";
        cout << "4 -> Mostrar sucursal con mas ventas\n";
        cout << "5 -> Mostrar toda la matriz\n";
        cout << "6 -> Salir\n";

        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            // Registrar o actualizar una venta
            cout << "Numero de sucursal: ";
            cin >> sucursal;

            cout << "Numero de mes: ";
            cin >> mes;

            if (sucursal < 1 || sucursal > sucursales || mes < 1 || mes > meses) {
                cout << "Sucursal o mes incorrecto.\n";
            }
            else {
                // Calculamos la posicion de la venta
                indice = (sucursal - 1) * meses + (mes - 1);

                cout << "Venta anterior: " << ventas[indice] << "\n";
                cout << "Nueva venta: ";
                cin >> monto;
                if (monto < 0) {
                    cout << "La venta no puede ser negativa.\n";
                }
                else {
                    ventas[indice] = monto;
                    cout << "Venta guardada.\n";
                }
            }
            break;

        case 2:
            // Consultar ventas de una sucursal
            cout << "Numero de sucursal: ";
            cin >> sucursal;

            if (sucursal < 1 || sucursal > sucursales) {
                cout << "Sucursal incorrecta.\n";
            }
            else {
                total = 0;
                for (int j = 1; j <= meses; j++)
                {
                    indice = (sucursal - 1) * meses + (j - 1);
                    cout << "Mes " << j << ": " << ventas[indice] << "\n";
                    total = total + ventas[indice];
                }
                cout << "Total: " << total << "\n";
            }
            break;

        case 3:
            // Mostrar ventas totales por sucursal
            for (int i = 1; i <= sucursales; i++) {
                total = 0;

                for (int j = 1; j <= meses; j++) {
                    indice = (i - 1) * meses + (j - 1);

                    total = total + ventas[indice];
                }
                cout << "Sucursal " << i << ": " << total << "\n";
            }
            break;

        case 4:
            // Buscar la sucursal con mayores ventas
            mayor = 0;

            for (int i = 1; i <= sucursales; i++) {
                total = 0;

                for (int j = 1; j <= meses; j++) {
                    indice = (i - 1) * meses + (j - 1);

                    total = total + ventas[indice];
                }

                if (total > mayor) {
                    mayor = total;
                }
            }
            if (mayor == 0) {
                cout << "Todavia no hay ventas registradas.\n";
            }
            else {
                cout << "Mayor total de ventas: " << mayor << "\n";
                cout << "Sucursal(es) con ese total: ";

                // Revisamos si varias sucursales tienen el mismo total
                for (int i = 1; i <= sucursales; i++) {
                    total = 0;

                    for (int j = 1; j <= meses; j++) {
                        indice = (i - 1) * meses + (j - 1);

                        total = total + ventas[indice];
                    }

                    if (total == mayor) {
                        cout << i << " ";
                    }
                }
                cout << "\n";
            }
            break;


        case 5:
            // Mostrar toda la matriz de ventas
            for (int i = 1; i <= sucursales; i++) {
                cout << "Sucursal " << i << ": ";

                for (int j = 1; j <= meses; j++) {
                    indice = (i - 1) * meses + (j - 1);

                    cout << ventas[indice] << " ";
                }
                cout << "\n";
            }
            break;

        case 6:
            cout << "Fin del programa.\n";
            break;
        default:
            cout << "Opcion incorrecta.\n";
        }

    } while (opcion != 6);

    // Liberamos la memoria reservada con new[]
    delete[] ventas;
    ventas = nullptr;

    cout << "Memoria liberada.\n";


    return 0;
}
