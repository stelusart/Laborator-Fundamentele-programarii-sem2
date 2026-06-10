#include <iostream>
using namespace std;

bool estePrim(int x) {
    if (x < 2) return false;
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) return false;
    }
    return true;
}

int main() {
    int n, mat[100][100];
    int pare[10000], nPare = 0;
    int prime[10000], nPrime = 0;
    int diag1[100], nD1 = 0;
    int diag2[100], nD2 = 0;
    int triunghiSus[10000], nTs = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val = mat[i][j];

            if (val % 2 == 0)
                pare[nPare++] = val;

            if (estePrim(val))
                prime[nPrime++] = val;

            if (i == j)
                diag1[nD1++] = val;

            if (i + j == n - 1)
                diag2[nD2++] = val;

            if (i < j && i + j < n - 1)
                triunghiSus[nTs++] = val;
        }
    }

    for (int i = 0; i < nPare; i++) cout << pare[i] << " ";
    cout << "\n";
    for (int i = 0; i < nPrime; i++) cout << prime[i] << " ";
    cout << "\n";
    for (int i = 0; i < nD1; i++) cout << diag1[i] << " ";
    cout << "\n";
    for (int i = 0; i < nD2; i++) cout << diag2[i] << " ";
    cout << "\n";
    for (int i = 0; i < nTs; i++) cout << triunghiSus[i] << " ";
    cout << "\n";

    return 0;
}
