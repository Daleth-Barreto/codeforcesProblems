// https://codeforces.com/problemset/problem/1927/D


#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n; // Tamaño del array a
        cin >> n;
        vector<int> a(n);// Array de n elementos
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int q; // Número de consultas
        cin >> q;

        // Preprocesamos los índices donde a[i] != a[i+1]
        vector<int> diff_indices; // Vector para almacenar los índices donde los elementos son diferentes
        for (int i = 0; i < n - 1; i++) {
            if (a[i] != a[i + 1]) {
                diff_indices.push_back(i + 1); // Guardamos el índice (usamos 1-basado) si los elementos son diferentes
            }
        }

        // Procesamos cada consulta
        while (q--) {
            int l, r; // Límites de la consulta
            cin >> l >> r;
            
            // Si los elementos en los índices l y r son diferentes, imprimimos los índices
            if (a[l - 1] != a[r - 1]) {
                cout << l << " " << r << "\n";
                continue;
            }
            
            // Usamos lower_bound para encontrar el primer índice en diff_indices que es >= l
            auto it = lower_bound(diff_indices.begin(), diff_indices.end(), l);
            
            // Si encontramos un índice en diff_indices dentro del rango [l, r], lo imprimimos
            if (it != diff_indices.end() && *it < r) {
                cout << *it << " " << (*it + 1) << "\n";
            } else {
                // Si no encontramos tal índice, imprimimos -1 -1
                cout << "-1 -1\n";
            }
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
