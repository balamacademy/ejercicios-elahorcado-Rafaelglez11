#include <iostream>
#include <string>
using namespace std;

// Mostrar el progreso actual de la palabra
void mostrarProgreso(string progreso) {
    for (int i = 0; i < progreso.length(); i++) {
        cout << progreso[i] << " ";
    }
    cout << endl;
}

// Actualizar el progreso si la letra está en la palabra
bool actualizarProgreso(string palabraSecreta, string &progreso, char letra) {
    bool acierto = false;
    for (int i = 0; i < palabraSecreta.length(); i++) {
        if (palabraSecreta[i] == letra && progreso[i] == '_') {
            progreso[i] = letra;
            acierto = true;
        }
    }
    return acierto;
}

// Mostrar la parte del cuerpo que se pierde según errores
void mostrarParteDelCuerpo(int errores) {
    switch (errores) {
        case 1: cout << "Pierde \"pierna derecha\"\n"; break;
        case 2: cout << "Pierde \"pierna izquierda\"\n"; break;
        case 3: cout << "Pierde \"brazo derecho\"\n"; break;
        case 4: cout << "Pierde \"brazo izquierdo\"\n"; break;
        case 5: cout << "Pierde \"tronco\"\n"; break;
        case 6: cout << "Pierde \"cabeza\"\n"; break;
    }
}

int main() {
    string palabraSecreta;
    string progreso = "";
    char letra;
    int errores = 0;
    const int maxErrores = 6;

    cout << "Ingrese la palabra: ";
    getline(cin, palabraSecreta);

    // Inicializar progreso con guiones bajos
    for (int i = 0; i < palabraSecreta.length(); i++) {
        if (palabraSecreta[i] != ' ') {
            progreso += "_";
        } else {
            progreso += " ";
        }
    }

    cout << "Comienza el juego!\n";
    mostrarProgreso(progreso);

    while (errores < maxErrores && progreso != palabraSecreta) {
        cout << "Ingrese letra: ";
        cin >> letra;

        bool acerto = actualizarProgreso(palabraSecreta, progreso, letra);
        if (acerto) {
            mostrarProgreso(progreso);
        } else {
            errores++;
            mostrarParteDelCuerpo(errores);
        }
    }

    if (progreso == palabraSecreta) {
        cout << "¡Felicidades! Has adivinado la palabra: " << palabraSecreta << endl;
    } else {
        cout << "\nHaz perdido el juego!\n";
    }

    return 0;
}
