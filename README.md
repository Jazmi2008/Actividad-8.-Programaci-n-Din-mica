# Programación Dinámica: Escaleras y Cambio mínimo de monedas

**Curso:** Análisis y Diseño de Algoritmos – Universidad de La Salle  
**Lenguaje:** C++ (estándar C++11)

Dos problemas resueltos mediante **Programación Dinámica (tabulación / bottom-up)**.

## 1. Problemas implementados

| Problema | Archivo | Estado DP | Recurrencia | Caso base |
|---|---|---|---|---|
| Escaleras | `src/escaleras.cpp` | `dp[i]` = formas de llegar al escalón `i` | `dp[i] = dp[i-1] + dp[i-2]` | `dp[0] = 1`, `dp[1] = 1` |
| Cambio mínimo de monedas | `src/cambio_monedas.cpp` | `dp[i]` = mínimo de monedas para formar `i` | `dp[i] = min(dp[i-c] + 1)` para cada moneda `c <= i` | `dp[0] = 0` |

## 2. Complejidad

- **Escaleras:**
  - Tiempo: `O(N)`.
  - Espacio: `O(N)`.

- **Cambio mínimo de monedas:**
  - Tiempo: `O(monto · n)`, donde `n` es la cantidad de denominaciones.
  - Espacio: `O(monto + n)`, considerando las tablas DP, el arreglo auxiliar y el arreglo de monedas.

## 3. Cómo compilar

Se necesita un compilador de C++ (por ejemplo, `g++`).

```bash
g++ -std=c++11 -Wall -o escaleras src/escaleras.cpp
g++ -std=c++11 -Wall -o monedas src/cambio_monedas.cpp
```

## 4. Cómo ejecutar

Se ejecuta cada programa y se ingresan los datos cuando los solicita.

### Escaleras

```bash
./escaleras
```

Entrada: número de escalones `N` (entero entre 0 y 92).

Ejemplo:

```text
Numero de escalones N: 5
Formas posibles: 8
Tabla DP:
[1, 1, 2, 3, 5, 8]
```

Para `N <= 7` también se listan las formas posibles. Con `N > 92`, el resultado no cabe en 64 bits y se muestra un error.

### Cambio mínimo de monedas

```bash
./monedas
```

Entrada: cantidad de denominaciones, monedas (enteros positivos separados por espacios) y cantidad objetivo.

Ejemplo:

```text
Cantidad de denominaciones: 3
Monedas (enteros positivos separados por espacios): 1 3 4
Cantidad objetivo: 6
Cantidad minima de monedas: 2
Combinacion: 3 + 3
Tabla DP:
[0,1,2,1,1,2,2]
```

Si la cantidad no se puede formar, se muestra un aviso y en la tabla aparece `INF`. Si la cantidad es mayor que 100, la tabla se muestra abreviada.

## 5. Ejecutar sin escribir los datos manualmente

También es posible ejecutar los programas utilizando la terminal y el comando `echo`, que envía los datos directamente al programa.

### Escaleras

```bash
echo 5 | ./escaleras
```

### Cambio mínimo de monedas

```bash
echo "3
1 3 4
6" | ./monedas
```

En estos ejemplos, los datos se envían automáticamente en el mismo orden en que los solicita cada programa.

**Nota:** En Windows, si se utiliza PowerShell o CMD, también se puede usar la redirección de entrada con archivos `.txt`.

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

## 8. Repositorio

[GitHub – Actividad 8: Programación Dinámica](https://github.com/Jazmi2008/Actividad-8.-Programaci-n-Din-mica)
```bash
echo 5 | ./escaleras
printf '3\n1 3 4\n6\n' | ./monedas
```

En Windows (PowerShell): `echo 5 | .\escaleras.exe` y `"3`n1 3 4`n6" | .\monedas.exe`.
