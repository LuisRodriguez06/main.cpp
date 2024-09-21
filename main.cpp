#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para generar una carta aleatoria
int generarCarta() {
    return rand() % 10 + 1;  // Genera cartas del 1 al 10
}

// Función para calcular el valor total de la mano
int calcularValorTotal(const vector<int>& mano) {
    int total = 0;
    for (int carta : mano) {
        total += carta;
    }
    return total;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Inicializa la semilla para números aleatorios

    int numJugadores;
    cout << "Ingrese el número de jugadores: ";
    cin >> numJugadores;

    vector<int> apuestas(numJugadores);
    vector<vector<int>> partidas(numJugadores);

    // Lectura de apuestas
    for (int i = 0; i < numJugadores; ++i) {
        cout << "Ingrese la apuesta del jugador " << (i + 1) << ": ";
        cin >> apuestas[i];
    }

    // Generación de cartas para cada jugador
    for (int i = 0; i < numJugadores; ++i) {
        partidas[i].push_back(generarCarta());
        partidas[i].push_back(generarCarta());
    }

    // Juego
    for (int i = 0; i < numJugadores; ++i) {
        cout << "Partida del jugador " << (i + 1) << ": ";
        for (int carta : partidas[i]) {
            cout << carta << " ";
        }
        cout << endl;

        int total = calcularValorTotal(partidas[i]);

        if (total > 21) {
            cout << "¡Jugador " << (i + 1) << " perdiste!" << endl;
        } else if (total == 21) {
            cout << "¡Jugador " << (i + 1) << " Black Jack! ¡Ganaste!" << endl;
        } else {
            char respuesta;
            cout << "¿Jugador " << (i + 1) << " quieres seguir jugando? (s/n): ";
            cin >> respuesta;

            if (respuesta == 's') {
                partidas[i].push_back(generarCarta());
                cout << "Nueva carta: " << partidas[i].back() << endl;
                total = calcularValorTotal(partidas[i]);

                if (total > 21) {
                    cout << "¡Jugador " << (i + 1) << " perdiste!" << endl;
                }
            }
        }
    }

    return 0;
}
