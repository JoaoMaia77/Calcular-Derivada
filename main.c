#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int grau;
    double *coeficientes;
} Polinomio;

Polinomio derivada(Polinomio p) {
    Polinomio dp;
    dp.grau = p.grau - 1;
    dp.coeficientes = (double *)malloc((dp.grau + 1) * sizeof(double));
    for (int i = 0; i < p.grau; i++) {
        dp.coeficientes[i] = p.coeficientes[i + 1] * (i + 1);
    }
    return dp;
}

double valor(Polinomio p, double x) {
    double valor = 0;
    for (int i = 0; i <= p.grau; i++) {
        valor += p.coeficientes[i] * pow(x, i);
    }
    return valor;
}

void imprimirPolinomio(Polinomio p) {
    for (int i = p.grau; i >= 0; i--) {
        if (p.coeficientes[i] != 0) {
            if (i > 1) {
                printf("%.2lfx^%d ", p.coeficientes[i], i);
            } else if (i == 1) {
                printf("%.2lfx ", p.coeficientes[i]);
            } else {
                printf("%.2lf ", p.coeficientes[i]);
            }
            if (i > 0) {
                printf("+ ");
            }
        }
    }
    printf("\n");
}

int main() {
    int continuar = 1;
    while (continuar) {
        Polinomio p;
        char input[256];

        // Lendo o grau do polinômio com tratamento de erro
        do {
            printf("Qual o grau do polinomio? ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = 0;
        } while (sscanf(input, "%d", &p.grau) != 1 || p.grau < 0);

        p.coeficientes = (double *)malloc((p.grau + 1) * sizeof(double));

        // Lendo os coeficientes com tratamento de erro

        for (int i = p.grau; i >= 0; i--) {
            do {
                printf("Digite o coeficiente de x^%d: ", i);
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
            } while (sscanf(input, "%lf", &p.coeficientes[i]) != 1);
        }

        printf("f(x) = ");
        imprimirPolinomio(p);

        Polinomio dp = derivada(p);
        printf("f'(x) = ");
        imprimirPolinomio(dp);

        double a;
        int calcular;

        // Loop para calcular f'(a)
        do {
            printf("Deseja calcular o valor funcional f'(a)? (1 para sim, 0 para nao) ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = 0;
        } while (sscanf(input, "%d", &calcular) != 1 || (calcular != 0 && calcular != 1));

        if (calcular) {
            // Loop para ler o valor de 'a'
            do {
                printf("Qual o valor de a? ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
            } while (sscanf(input, "%lf", &a) != 1);

            double fa = valor(p, a);
            double dfa = valor(dp, a);
            printf("a = %.2lf, f(a) = %.2lf, f'(a) = %.2lf\n", a, fa, dfa);

            // Loop para calcular a equação da reta tangente
            do {
                printf("Deseja calcular a equacao da reta tangente ao grafico de f(x) no ponto P = (a, f(a))? (1 para sim, 0 para nao) ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
            } while (sscanf(input, "%d", &calcular) != 1 || (calcular != 0 && calcular != 1));

            if (calcular && dfa != 0) {
                printf("A equacao da reta tangente ao grafico de f(x) no ponto P = (%.2lf, %.2lf) sera y = %.2lfx + %.2lf\n", a, fa, dfa, fa - dfa * a);
            } else if (calcular) {
                printf("A derivada em a e zero. A reta tangente e vertical.\n");
            }
        }

        // Loop para perguntar se deseja calcular outra derivada
        do {
            printf("Deseja calcular a derivada para outra funcao? (1 para sim, 0 para nao) ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = 0;
        } while (sscanf(input, "%d", &continuar) != 1 || (continuar != 0 && continuar != 1));

        free(p.coeficientes);
        free(dp.coeficientes);
    }

    return 0;
}
