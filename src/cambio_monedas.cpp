/*
 * Programacion Dinamica - Problema 2: Cambio minimo de monedas
 *
 * Problema: dado un conjunto de denominaciones (se puede usar cada moneda las
 * veces que se quiera) y una cantidad objetivo, hallar el minimo numero de
 * monedas que suman exactamente esa cantidad.
 *
 * Estado DP:
 *   dp[i] = minimo numero de monedas necesarias para formar exactamente i.
 *
 * Caso base:
 *   dp[0] = 0   (cero monedas para formar la cantidad 0)
 *   dp[i] = INF al inicio (todavia no se sabe formar i)
 *
 * Relacion de recurrencia (i >= 1):
 *   dp[i] = min sobre cada moneda c <= i de ( dp[i - c] + 1 )
 *   (se prueba usar la moneda c como ultima moneda y se queda con la mejor)
 *
 * Para mostrar una combinacion se guarda en ultima[i] la moneda con la que se
 * obtuvo dp[i]; al final se reconstruye restando monedas desde la cantidad.
 *
 * Tecnica: tabulacion (bottom-up).
 *
 * Entrada (por teclado o redirigida desde un archivo):
 *   n                    (cantidad de denominaciones)
 *   c1 c2 ... cn         (monedas, enteros positivos)
 *   cantidad             (entero >= 0)
 *
 * Complejidad: tiempo O(cantidad * n), espacio O(cantidad).
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int INF = INT_MAX / 2;               // "infinito": cantidad aun no alcanzable
const long long MONTO_MAX = 10000000;      // limite para no gastar demasiada memoria
const int LIMITE_TABLA = 100;              // si la cantidad es mayor, la tabla se muestra abreviada

// Imprime un valor de la tabla (INF se muestra como "INF").
void imprimirValor(int v) {
    if (v >= INF) cout << "INF";
    else cout << v;
}

int main() {
    // Los mensajes para el usuario van a cerr; los resultados van a cout.
    int n;
    cerr << "Cantidad de denominaciones: ";
    if (!(cin >> n) || n < 0) {
        cout << "Error: la cantidad de denominaciones debe ser un entero mayor o igual a 0." << endl;
        return 1;
    }

    vector<int> monedas(n);
    cerr << "Monedas (enteros positivos separados por espacios): ";
    for (int i = 0; i < n; i++) {
        if (!(cin >> monedas[i]) || monedas[i] <= 0) {
            cout << "Error: la moneda " << i + 1 << " no es un entero positivo." << endl;
            return 1;
        }
    }

    long long monto;
    cerr << "Cantidad objetivo: ";
    if (!(cin >> monto) || monto < 0) {
        cout << "Error: la cantidad objetivo debe ser un entero mayor o igual a 0." << endl;
        return 1;
    }
    if (monto > MONTO_MAX) {
        cout << "Error: la cantidad objetivo no puede pasar de " << MONTO_MAX << "." << endl;
        return 1;
    }
    int objetivo = (int)monto;

    // Se ordenan las monedas y se quitan las repetidas.
    sort(monedas.begin(), monedas.end());
    monedas.erase(unique(monedas.begin(), monedas.end()), monedas.end());

    // PASO 1: crear la tabla y poner el caso base.
    vector<int> dp(objetivo + 1, INF);     // dp[i] = minimo de monedas para formar i
    vector<int> ultima(objetivo + 1, 0);   // ultima[i] = moneda usada para llegar a dp[i]
    dp[0] = 0;                             // caso base: 0 monedas para formar 0

    // PASO 2: llenar la tabla de izquierda a derecha.
    for (int i = 1; i <= objetivo; i++) {
        for (size_t k = 0; k < monedas.size(); k++) {
            int c = monedas[k];
            // Solo sirve si la moneda cabe y si ya se sabe formar i - c.
            if (c <= i && dp[i - c] != INF && dp[i - c] + 1 < dp[i]) {
                dp[i] = dp[i - c] + 1;
                ultima[i] = c;
            }
        }
    }

    // PASO 3: mostrar resultados.
    if (dp[objetivo] == INF) {
        cout << "No es posible formar la cantidad " << objetivo << " con las monedas dadas." << endl;
    } else {
        cout << "Cantidad minima de monedas: " << dp[objetivo] << endl;

        // Reconstruir una combinacion valida siguiendo ultima[] desde el objetivo.
        vector<int> usadas;
        for (int i = objetivo; i > 0; i -= ultima[i]) usadas.push_back(ultima[i]);
        sort(usadas.rbegin(), usadas.rend());   // de mayor a menor para leerla mejor

        cout << "Combinacion: ";
        if (usadas.empty()) cout << "(ninguna moneda)";
        for (size_t k = 0; k < usadas.size(); k++) {
            if (k > 0) cout << " + ";
            cout << usadas[k];
        }
        cout << endl;
    }

    cout << "Tabla DP:" << endl;
    cout << "[";
    if (objetivo <= LIMITE_TABLA) {
        for (int i = 0; i <= objetivo; i++) {
            imprimirValor(dp[i]);
            if (i < objetivo) cout << ",";
        }
        cout << "]" << endl;
    } else {
        // Tabla muy larga: se muestran los primeros 20 y los ultimos 5 valores.
        for (int i = 0; i < 20; i++) {
            imprimirValor(dp[i]);
            cout << ",";
        }
        cout << " ... ";
        for (int i = objetivo - 4; i <= objetivo; i++) {
            imprimirValor(dp[i]);
            if (i < objetivo) cout << ",";
        }
        cout << "]" << endl;
        cout << "(Tabla abreviada: la cantidad es mayor que " << LIMITE_TABLA << ")" << endl;
    }
    return 0;
}
