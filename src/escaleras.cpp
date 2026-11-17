/*
 * Programacion Dinamica - Problema 1: Escaleras
 *
 * Problema: una escalera tiene N escalones y el personaje puede subir 1 o 2
 * escalones a la vez. Se quiere saber de cuantas formas distintas puede llegar
 * exactamente al escalon N.
 *
 * Estado DP:
 *   dp[i] = numero de formas distintas de llegar al escalon i.
 *
 * Casos base:
 *   dp[0] = 1   (una forma: no moverse)
 *   dp[1] = 1   (una forma: un paso de 1 escalon)
 *
 * Relacion de recurrencia (i >= 2):
 *   dp[i] = dp[i-1] + dp[i-2]
 *   (el ultimo paso fue de 1 escalon, viniendo del i-1, o de 2, viniendo del i-2)
 *
 * Tecnica: tabulacion (bottom-up), llenando la tabla de izquierda a derecha.
 *
 * Entrada (por teclado o redirigida desde un archivo):
 *   N     (entero entre 0 y 92)
 *
 * Complejidad: tiempo O(N), espacio O(N).
 *
 * Nota: con N > 92 el resultado ya no cabe en 64 bits (dp[93] = 1.97 x 10^19),
 * por eso el programa acepta como maximo N = 92.
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef unsigned long long ull;
const int N_MAX = 92;

// Genera todas las formas de subir 'restante' escalones (solo para mostrar
// los ejemplos con N pequeño; la respuesta la da la tabla DP).
void listarFormas(int restante, const string& actual, vector<string>& formas) {
    if (restante == 0) {
        formas.push_back(actual);
        return;
    }
    for (int paso = 1; paso <= 2; paso++) {
        if (paso <= restante) {
            string siguiente = actual.empty() ? to_string(paso) : actual + " + " + to_string(paso);
            listarFormas(restante - paso, siguiente, formas);
        }
    }
}

int main() {
    // Los mensajes para el usuario van a cerr; los resultados van a cout.
    long long N;
    cerr << "Numero de escalones N: ";
    if (!(cin >> N) || N < 0) {
        cout << "Error: N debe ser un entero mayor o igual a 0." << endl;
        return 1;
    }
    if (N > N_MAX) {
        cout << "Error: con N > " << N_MAX << " el resultado no cabe en 64 bits (maximo permitido: "
             << N_MAX << ")." << endl;
        return 1;
    }
    int n = (int)N;

    // PASO 1: crear la tabla y poner los casos base.
    vector<ull> dp(n + 1);
    dp[0] = 1;                         // caso base: una forma de estar en el escalon 0
    if (n >= 1) dp[1] = 1;             // caso base: una forma de llegar al escalon 1

    // PASO 2: llenar la tabla de izquierda a derecha con la recurrencia.
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // PASO 3: mostrar la respuesta y la tabla DP.
    cout << "Formas posibles: " << dp[n] << endl;
    cout << "Tabla DP:" << endl;
    cout << "[";
    for (int i = 0; i <= n; i++) {
        cout << dp[i];
        if (i < n) cout << ", ";
    }
    cout << "]" << endl;

    // Extra: para N pequeño (hasta 7) se listan las formas (sirve para comprobar el resultado).
    if (n >= 1 && n <= 7) {
        vector<string> formas;
        listarFormas(n, "", formas);
        cout << "Formas encontradas (" << formas.size() << "):" << endl;
        for (size_t k = 0; k < formas.size(); k++) cout << formas[k] << endl;
    }
    return 0;
}
