#include <stdio.h>

int main() {
    int optiune;

    do {
        printf("\n--- MENIU INTERACTIV ---\n");
        printf("1. Valoare maxima si frecventa\n");
        printf("2. CMMDC si CMMMC\n");
        printf("3. Reprezentare in baza b (b < 10)\n");
        printf("4. Primele n numere din sirul Fibonacci\n");
        printf("5. Iesire\n");
        printf("Alegeti o optiune: ");

        // MODIFICARE: Adaugam un spatiu inainte de %d pentru a sari peste whitespace/Enter
        if (scanf(" %d", &optiune) != 1) {
            printf("Eroare: Te rog introdu o cifra, nu litere!\n");
            // Curatam buffer-ul in caz de input invalid (litere)
            while (getchar() != '\n');
            optiune = 0; // Resetam optiunea pentru a afisa meniul din nou
            continue;
        }

        switch (optiune) {
            case 1: {
                int n, num, max, frecventa = 0;
                printf("n = "); scanf(" %d", &n);
                if (n > 0) {
                    printf("Introduceti cele %d numere:\n", n);
                    for (int i = 0; i < n; i++) {
                        scanf(" %d", &num);
                        if (i == 0 || num > max) {
                            max = num;
                            frecventa = 1;
                        } else if (num == max) {
                            frecventa++;
                        }
                    }
                    printf("Maximul este %d si apare de %d ori.\n", max, frecventa);
                }
                break;
            }

            case 2: {
                long long m, n, a, b, cmmdc, cmmmc;
                printf("m = "); scanf(" %lld", &m);
                printf("n = "); scanf(" %lld", &n);
                a = m; b = n;
                while (b != 0) {
                    long long rest = a % b;
                    a = b;
                    b = rest;
                }
                cmmdc = a;
                if (cmmdc != 0) cmmmc = (m * n) / cmmdc;
                else cmmmc = 0;
                printf("CMMDC = %lld, CMMMC = %lld\n", cmmdc, cmmmc);
                break;
            }

            case 3: {
                int n, b;
                long long rezultat = 0, p = 1;
                printf("n = "); scanf(" %d", &n);
                printf("b (b < 10) = "); scanf(" %d", &b);
                int copie_n = n;
                while (copie_n > 0) {
                    rezultat += (copie_n % b) * p;
                    p *= 10;
                    copie_n /= b;
                }
                printf("Numarul %d in baza %d este: %lld\n", n, b, rezultat);
                break;
            }

            case 4: {
                int n;
                long long f1 = 0, f2 = 1, f3;
                printf("n = "); scanf(" %d", &n);
                printf("Sirul Fibonacci: ");
                for (int i = 1; i <= n; i++) {
                    if (i == 1) printf("%lld ", f1);
                    else if (i == 2) printf("%lld ", f2);
                    else {
                        f3 = f1 + f2;
                        printf("%lld ", f3);
                        f1 = f2;
                        f2 = f3;
                    }
                }
                printf("\n");
                break;
            }

            case 5:
                printf("Programul se inchide. La revedere!\n");
                break;

            default:
                printf("Optiune invalida! Incercati din nou.\n");
        }
    } while (optiune != 5);

    return 0;
}