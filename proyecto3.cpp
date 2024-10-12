#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para repartir una carta (simulando un valor entre 1 y 11)
int dealCard() {
    return rand() % 11 + 1; // Valores entre 1 y 11
}

// Función para calcular la puntuación
int calculateScore(int card1, int card2) {
    return card1 + card2;
}

// Función para validar el ganador
string validateWinner(int playerScore, int dealerScore) {
    if (playerScore == 21) {
        return "Ganaste";
    } else if (playerScore > dealerScore) {
        return "Ganaste";
    } else if (playerScore == dealerScore) {
        return "Empate";
    } else {
        return "Perdiste";
    }
}

// Función principal del juego
int main() {
    srand(static_cast<unsigned int>(time(0))); // Inicializa el generador de números aleatorios

    // Repartir cartas
    int playerCard1 = dealCard();
    int playerCard2 = dealCard();
    int dealerCard1 = dealCard();
    int dealerCard2 = dealCard();

    // Calcular puntuaciones
    int playerScore = calculateScore(playerCard1, playerCard2);
    int dealerScore = calculateScore(dealerCard1, dealerCard2);

    // Mostrar manos y puntuaciones
    cout << "Tu mano: " << playerCard1 << " " << playerCard2 << ", Puntuación: " << playerScore << endl;
    cout << "Mano del dealer: " << dealerCard1 << " " << dealerCard2 << ", Puntuación: " << dealerScore << endl;

    // Validar y mostrar el resultado
    string result = validateWinner(playerScore, dealerScore);
    cout << result << endl;

    return 0;
}































