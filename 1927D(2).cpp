// https://codeforces.com/problemset/problem/1927/D

#include <bits/stdc++.h>
using namespace std;

// Función para realizar la búsqueda binaria
int lower_bin(vector<int>& v, int value) {
    int max = v.size(), min = 0;
    while (min < max) {
        int mid = min + (max - min) / 2;
        if (value > v[mid]) 
            min = mid + 1;
        else 
            max = mid;
    }
    return min; // Retorna el índice en el que el valor debería insertarse
}

void solve() {
    int t; // Número de casos de prueba
    cin >> t;

    // Procesamos cada caso de prueba
    while (t--) {
        int n, q; // Tamaño del array a y número de consultas
        cin >> n;
        vector<int> a(n); // Array de n elementos
        for (int i = 0; i < n; i++) {
            cin >> a[i]; // Leemos los elementos del array a
        }

        cin >> q; // Número de consultas

        vector<int> v; // Vector para almacenar los índices donde a[i] != a[i+1]
        for (int i = 0; i < n - 1; i++) {
            if (a[i] != a[i + 1]) 
                v.push_back(i + 1); // Guardamos el índice si los elementos son diferentes
        }

        // Procesamos cada consulta
        while (q--) {
            int l, r; // Límites de la consulta
            cin >> l >> r;

            // Si los elementos en los índices l y r son diferentes, imprimimos los índices
            if (a[l - 1] != a[r - 1]) {
                cout << l << " " << r << endl;
                continue;
            }

            // Usamos la búsqueda binaria para encontrar el primer índice en v que es >= l
            int it = lower_bin(v, l);
            
            // Si encontramos un índice en v dentro del rango [l, r], lo imprimimos
            if (it < v.size() && v[it] < r) 
                cout << v[it] << " " << v[it] + 1;
            else 
                cout << "-1 -1"; // Si no, imprimimos -1 -1
            cout << endl; // Fin de la consulta
        }
        cout << endl; // Imprimimos una línea vacía entre casos de prueba
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve(); // Llamamos a la función solve que maneja todos los casos de prueba
    return 0;
}
