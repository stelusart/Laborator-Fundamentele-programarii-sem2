#include <stdio.h>
#include <string.h>

#define MAX 1001

typedef struct {
    int cifre[MAX];
    int lungime;
} NumarMare;

NumarMare conversie(char s[]) {
    NumarMare n;
    n.lungime = strlen(s);
    for (int i = 0; i < n.lungime; i++) {
        n.cifre[i] = s[n.lungime - 1 - i] - '0';
    }
    return n;
}

void afisare(NumarMare n) {
    for (int i = n.lungime - 1; i >= 0; i--) {
        printf("%d", n.cifre[i]);
    }
    printf("\n");
}

NumarMare adunare(NumarMare a, NumarMare b) {
    NumarMare rez;
    int t = 0, i;
    int max_len = (a.lungime > b.lungime) ? a.lungime : b.lungime;

    for (i = 0; i < max_len || t; i++) {
        int cifra_a = (i < a.lungime) ? a.cifre[i] : 0;
        int cifra_b = (i < b.lungime) ? b.cifre[i] : 0;
        int suma = cifra_a + cifra_b + t;
        rez.cifre[i] = suma % 10;
        t = suma / 10;
    }
    rez.lungime = i;
    return rez;
}

NumarMare scadere(NumarMare a, NumarMare b) {
    NumarMare rez;
    int imprumut = 0;

    for (int i = 0; i < a.lungime; i++) {
        int cifra_b = (i < b.lungime) ? b.cifre[i] : 0;
        int diff = a.cifre[i] - cifra_b - imprumut;
        if (diff < 0) {
            diff += 10;
            imprumut = 1;
        } else {
            imprumut = 0;
        }
        rez.cifre[i] = diff;
    }

    rez.lungime = a.lungime;
    while (rez.lungime > 1 && rez.cifre[rez.lungime - 1] == 0) {
        rez.lungime--;
    }
    return rez;
}

NumarMare inmultireCifra(NumarMare a, int cifra) {
    NumarMare rez;
    if (cifra == 0) {
        rez.cifre[0] = 0;
        rez.lungime = 1;
        return rez;
    }

    int t = 0, i;
    for (i = 0; i < a.lungime || t; i++) {
        int cifra_a = (i < a.lungime) ? a.cifre[i] : 0;
        long long prod = (long long)cifra_a * cifra + t;
        rez.cifre[i] = prod % 10;
        t = prod / 10;
    }
    rez.lungime = i;
    return rez;
}

int main() {
    char s1[MAX], s2[MAX];
    int cifra;

    scanf("%s", s1);
    scanf("%s", s2);
    scanf("%d", &cifra);

    NumarMare n1 = conversie(s1);
    NumarMare n2 = conversie(s2);

    afisare(adunare(n1, n2));
    afisare(scadere(n1, n2));
    afisare(inmultireCifra(n1, cifra));

    return 0;
}12345