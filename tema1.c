#include <stdio.h>

int main() {
    int n;

    printf("Introduceti un numar mai mic decat 1000: ");
    if (scanf("%d", &n) != 1) return 1;

    if (n < 0 || n >= 1000) {
        printf("Eroare: Introduceti un numar intre 0 si 999.\n");
        return 0;
    }

    if (n == 0) {
        printf("zero\n");
        return 0;
    }

    int s = n / 100;
    if (s == 1) printf("osuta");
    else if (s == 2) printf("douasute");
    else if (s == 3) printf("treisute");
    else if (s == 4) printf("patrusute");
    else if (s == 5) printf("cincisute");
    else if (s == 6) printf("sasesute");
    else if (s == 7) printf("saptesute");
    else if (s == 8) printf("optsute");
    else if (s == 9) printf("nouasute");

    int rest = n % 100;

    if (rest > 0) {
        if (rest < 10) {
            if (rest == 1) printf("unu");
            else if (rest == 2) printf("doi");
            else if (rest == 3) printf("trei");
            else if (rest == 4) printf("patru");
            else if (rest == 5) printf("cinci");
            else if (rest == 6) printf("sase");
            else if (rest == 7) printf("sapte");
            else if (rest == 8) printf("opt");
            else if (rest == 9) printf("noua");
        }
        else if (rest >= 10 && rest <= 19) {
            if (rest == 10) printf("zece");
            else if (rest == 11) printf("unsprezece");
            else if (rest == 12) printf("doisprezece");
            else if (rest == 13) printf("treisprezece");
            else if (rest == 14) printf("paisprezece");
            else if (rest == 15) printf("cincisprezece");
            else if (rest == 16) printf("saisprezece");
            else if (rest == 17) printf("saptesprezece");
            else if (rest == 18) printf("optsprezece");
            else if (rest == 19) printf("nouasprezece");
        }
        else {
            int z = rest / 10;
            int u = rest % 10;

            if (z == 2) printf("douazeci");
            else if (z == 3) printf("treizeci");
            else if (z == 4) printf("patruzeci");
            else if (z == 5) printf("cincizeci");
            else if (z == 6) printf("saizeci");
            else if (z == 7) printf("saptezeci");
            else if (z == 8) printf("optzeci");
            else if (z == 9) printf("nouazeci");

            if (u > 0) {
                printf("si");
                if (u == 1) printf("unu");
                else if (u == 2) printf("doi");
                else if (u == 3) printf("trei");
                else if (u == 4) printf("patru");
                else if (u == 5) printf("cinci");
                else if (u == 6) printf("sase");
                else if (u == 7) printf("sapte");
                else if (u == 8) printf("opt");
                else if (u == 9) printf("noua");
            }
        }
    }

    printf("\n");
    return 0;
}