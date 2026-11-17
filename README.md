# Programación Dinámica: Escaleras y Cambio mínimo de monedas

**Curso:** Análisis y Diseño de Algoritmos – Universidad de La Salle  
**Lenguaje:** C++ (estándar C++11)

Esta actividad desarrolla dos problemas aplicando **Programación Dinámica mediante tabulación (bottom-up)**. Ambos algoritmos utilizan tablas para almacenar resultados de subproblemas y reutilizarlos durante la ejecución.

## 1. Problemas implementados

| Problema | Archivo | Estado DP | Recurrencia | Caso base |
|---|---|---|---|---|
| Escaleras | `src/escaleras.cpp` | `dp[i]` = número de formas de llegar al escalón `i` | `dp[i] = dp[i-1] + dp[i-2]` | `dp[0] = 1`, `dp[1] = 1` |
| Cambio mínimo de monedas | `src/cambio_monedas.cpp` | `dp[i]` = mínimo número de monedas para formar la cantidad `i` | `dp[i] = min(dp[i-c] + 1)` para cada moneda `c <= i` | `dp[0] = 0` |

## 2. Complejidad de los algoritmos

**Problema 1: Escaleras**

- Complejidad temporal: `O(N)`.
- Complejidad espacial: `O(N)`.

Se llena una tabla de `N + 1` posiciones y cada posición se calcula mediante una suma.

**Problema 2: Cambio mínimo de monedas**

- Complejidad temporal: `O(monto · n)`, donde `n` representa la cantidad de denominaciones.
- Complejidad espacial: `O(monto)`.

El algoritmo prueba las denominaciones disponibles para cada cantidad y utiliza tablas auxiliares para calcular y reconstruir la combinación de monedas.

## 3. Cómo compilar

Se necesita un compilador de C++ compatible con el estándar C++11, como `g++`.

Ejecutar los siguientes comandos desde la carpeta principal del proyecto:

```bash
g++ -std=c++11 -Wall -o escaleras src/escaleras.cpp
```

```bash
g++ -std=c++11 -Wall -o monedas src/cambio_monedas.cpp
```

## 4. Cómo ejecutar los programas

Después de compilar, se puede ejecutar cada programa desde la terminal.

### Problema 1: Escaleras

```bash
./escaleras
```

El programa solicita el número de escalones `N`, que debe ser un entero entre 0 y 92.

**Ejemplo de ejecución:**

```text
Numero de escalones N: 5
Formas posibles: 8

Tabla DP:
[1, 1, 2, 3, 5, 8]
```

Para valores de `N` menores o iguales a 7, también se muestran las formas posibles de subir la escalera. Si `N` es mayor que 92, se muestra un mensaje de error porque el resultado no cabe en 64 bits.

### Problema 2: Cambio mínimo de monedas

```bash
./monedas
```

El programa solicita:
1. La cantidad de denominaciones.
2. Los valores de las monedas, separados por espacios.
3. La cantidad objetivo que se desea formar.

**Ejemplo de ejecución:**

```text
Cantidad de denominaciones: 3
Monedas (enteros positivos separados por espacios): 1 3 4
Cantidad objetivo: 6

Cantidad minima de monedas: 2
Combinacion: 3 + 3

Tabla DP:
[0,1,2,1,1,2,2]
```

Si la cantidad no se puede formar con las monedas disponibles, el programa muestra un mensaje indicando que no existe una solución y representa las cantidades no alcanzables con `INF`.

Cuando la cantidad objetivo es mayor que 100, la tabla DP se muestra abreviada para facilitar su visualización.

## 5. Ejecución automática de los programas

También es posible ejecutar los programas enviando los datos directamente desde la terminal, sin ingresarlos manualmente.

### Escaleras

```bash
echo 5 | ./escaleras
```

### Cambio mínimo de monedas

```bash
printf '3\n1 3 4\n6\n' | ./monedas
```

En el segundo ejemplo, los datos se envían en el orden solicitado por el programa: cantidad de denominaciones, monedas y cantidad objetivo.

**Nota para Windows:** Si se utiliza PowerShell, se puede emplear la siguiente forma de ejecución:

```powershell
echo 5 | .\escaleras.exe
```

```powershell
"3`n1 3 4`n6" | .\monedas.exe
```

## 6. Estructura del proyecto

```text
Actividad-8-Programacion-Dinamica/
│
├── src/
│   ├── escaleras.cpp
│   └── cambio_monedas.cpp
│
├── README.md
└── ...
```

## 7. Requisitos

- Compilador de C++ compatible con C++11.
- Terminal o consola para compilar y ejecutar los programas.

## 8. Repositorio de GitHub

El código fuente de ambos problemas se encuentra disponible en el siguiente repositorio:

[Actividad 8 - Programación Dinámica](https://github.com/Jazmi2008/Actividad-8.-Programaci-n-Din-mica)
