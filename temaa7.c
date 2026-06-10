#include <iostream>
using namespace std;

bool eAnBisect(int an) {
    if (an % 400 == 0) return true;
    if (an % 100 == 0) return false;
    if (an % 4 == 0) return true;
    return false;
}

int zileLuna(int luna, int an) {
    int zile[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (luna == 2 && eAnBisect(an)) return 29;
    return zile[luna];
}

bool dataValida(int zi, int luna, int an) {
    if (an < 1) return false;
    if (luna < 1  luna > 12) return false;
    if (zi < 1 
 zi > zileLuna(luna, an)) return false;
    return true;
}

void ziUrmătoare(int& zi, int& luna, int& an) {
    zi++;
    if (zi > zileLuna(luna, an)) {
        zi = 1;
        luna++;
        if (luna > 12) {
            luna = 1;
            an++;
        }
    }
}

long long totalZile(int zi, int luna, int an) {
    long long total = 0;
    for (int i = 1; i < an; i++)
        total += eAnBisect(i) ? 366 : 365;
    for (int i = 1; i < luna; i++)
        total += zileLuna(i, an);
    total += zi;
    return total;
}

int main() {
    int z1, l1, a1, z2, l2, a2;
    cin >> z1 >> l1 >> a1;
    cin >> z2 >> l2 >> a2;

    if (!dataValida(z1, l1, a1) || !dataValida(z2, l2, a2)) {
        cout << "Date invalide\n";
        return 0;
    }

    long long dif = abs(totalZile(z1, l1, a1) - totalZile(z2, l2, a2));

    ziUrmătoare(z1, l1, a1);
    ziUrmătoare(z2, l2, a2);

    cout << z1 << " " << l1 << " " << a1 << "\n";
    cout << z2 << " " << l2 << " " << a2 << "\n";
    cout << dif << "\n";
    return 0;
}
