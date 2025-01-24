// https://codeforces.com/problemset/problem/1989/B
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string a, b; // Las dos cadenas de entrada: a y b
        cin >> a >> b;

        int n = a.size();
        int m = b.size();
        int mn = n + m;   // Inicializamos la longitud mínima como la suma de ambas longitudes

        // Iteramos por cada posición de la cadena 'b'
        for (int i = 0; i < m; ++i) {
            int k = i; // Índice para rastrear la posición actual en 'b'
            // Iteramos por cada carácter en 'a' para intentar alinear subsecuencias
            for (int j = 0; j < n; ++j) {
                // Si el carácter actual de 'a' coincide con el de 'b', avanzamos en 'b'
                if (k < m && a[j] == b[k]) 
                    k++;
            }
            // Calculamos la longitud mínima posible:
            // Longitud de 'a' + Longitud de 'b' - Caracteres comunes alineados (k) + Desplazamiento (i)
            mn = min(mn, n + m - k + i);
        }
        cout << mn << endl;
    }
    return 0;
}
