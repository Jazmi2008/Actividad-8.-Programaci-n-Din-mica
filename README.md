# Programación Dinámica: Escaleras y Cambio mínimo de monedas

Curso: Análisis y Diseño de Algoritmos – Universidad de La Salle
Lenguaje: C++ (estándar C++11)

Dos problemas resueltos con **Programación Dinámica (tabulación / bottom-up)**:

| Problema | Archivo | Estado DP | Recurrencia | Caso base |
|---|---|---|---|---|
| Escaleras | `src/escaleras.cpp` | `dp[i]` = formas de llegar al escalón `i` | `dp[i] = dp[i-1] + dp[i-2]` | `dp[0] = 1`, `dp[1] = 1` |
| Cambio mínimo de monedas | `src/cambio_monedas.cpp` | `dp[i]` = mínimo de monedas para formar `i` | `dp[i] = min(dp[i-c] + 1)` para cada moneda `c <= i` | `dp[0] = 0` |

Complejidad: escaleras O(N) en tiempo y espacio; monedas O(monto · n) en tiempo y O(monto) en espacio.

## Cómo compilar

Se necesita un compilador de C++ (por ejemplo `g++`).

```bash
g++ -std=c++11 -Wall -o escaleras src/escaleras.cpp
g++ -std=c++11 -Wall -o monedas src/cambio_monedas.cpp
```

## Cómo ejecutar

Se ejecuta el programa y se escriben los datos cuando los pide.

### Escaleras

```bash
./escaleras
```

Entrada: el número de escalones `N` (entero entre 0 y 92).

```
Numero de escalones N: 5
Formas posibles: 8
Tabla DP:
[1, 1, 2, 3, 5, 8]
```

(Para N <= 7 también se listan las formas. Con N > 92 el resultado no cabe en 64 bits y se muestra un error.)

### Cambio mínimo de monedas

```bash
./monedas
```

Entrada: la cantidad de monedas, las monedas (enteros positivos separados por espacios) y la cantidad objetivo.

```
Cantidad de denominaciones: 3
Monedas (enteros positivos separados por espacios): 1 3 4
Cantidad objetivo: 6
Cantidad minima de monedas: 2
Combinacion: 3 + 3
Tabla DP:
[0,1,2,1,1,2,2]
```

Si la cantidad no se puede formar, se avisa y en la tabla aparece `INF`. Si la cantidad es mayor que 100, la tabla se muestra abreviada.

### Ejecutar sin escribir los datos a mano

```bash
echo 5 | ./escaleras
printf '3\n1 3 4\n6\n' | ./monedas
```

En Windows (PowerShell): `echo 5 | .\escaleras.exe` y `"3`n1 3 4`n6" | .\monedas.exe`.
