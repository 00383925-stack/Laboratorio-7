#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Leer números desde un archivo
vector<int> leerArchivo(string nombre) {
    ifstream archivo(nombre);
    vector<int> lista;
    int num;

    while (archivo >> num) {
        lista.push_back(num);
    }

    archivo.close();
    return lista;
}

// Clasificar números pares e impares
void clasificarNumeros(const vector<int>& lista) {
    ofstream pares("pares.txt");
    ofstream impares("impares.txt");

    for (int n : lista) {
        if (n % 2 == 0)
            pares << n << endl;
        else
            impares << n << endl;
    }

    pares.close();
    impares.close();
}

// Ordenar archivo usando burbuja
void ordenarArchivo(string nombre) {
    vector<int> lista = leerArchivo(nombre);

    for (int i = 0; i < lista.size(); i++) {
        for (int j = 0; j < lista.size() - 1; j++) {
            if (lista[j] > lista[j + 1]) {
                int aux = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = aux;
            }
        }
    }

    ofstream archivo(nombre);
    for (int n : lista) {
        archivo << n << endl;
    }
    archivo.close();
}

// Mostrar contenido de un archivo
void mostrarArchivo(string nombre) {
    ifstream archivo(nombre);
    int num;

    cout << "\nContenido de " << nombre << ":\n";

    while (archivo >> num) {
        cout << num << " ";
    }

    cout << "\n";
    archivo.close();
}

int main() {

    // 1. Leer datos
    vector<int> lista = leerArchivo("datos.txt");

    // 2. Clasificar pares e impares
    clasificarNumeros(lista);

    // 3. Ordenar ambos archivos
    ordenarArchivo("pares.txt");
    ordenarArchivo("impares.txt");

    // 4. Mostrar resultados
    mostrarArchivo("pares.txt");
    mostrarArchivo("impares.txt");

    return 0;
}