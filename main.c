#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int grau;
    double *coeficientes;
} Polinomio;

Polinomio derivada(Polinomio p) {
    Polinomio dp;
    dp.grau = p.grau - 1;
    dp.coeficientes = (double *)malloc((dp.grau + 1) * sizeof(double));
    for (int i = 0; i < p.grau; i++) {
        dp.coeficientes[i] = p.coeficientes[i+1] * (i + 1);
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
            printf("%.2fx^%d ", p.coeficientes[i], i);
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
        printf("Qual o grau do polinomio? ");
        if (scanf("%d", &p.grau) != 1 || p.grau < 0) {
            printf("Entrada inválida! Tente novamente.\n");
            continue;
        }
p.coeficientes = (double *)malloc((p.grau + 1) * sizeof(double));
        int validInput = 1; // Variável de controle
        for (int i = p.grau; i >= 0 && validInput; i--) {
          printf("Digite o coeficiente de x^%d: ", i);
          if (scanf("%lf", &p.coeficientes[i]) != 1) {
           printf("Entrada inválida! Tente novamente.\n");
           validInput = 0; // Se a entrada for inválida, altere a variável de controle
          }
        }
        printf("f(x) = ");
        imprimirPolinomio(p);
        Polinomio dp = derivada(p);
        printf("f'(x) = ");
        imprimirPolinomio(dp);

        double a;
        printf("Deseja calcular o valor funcional f'(a)? (1 para sim, 0 para nao) ");
        int calcular;
        scanf("%d", &calcular);
        if (calcular) {
            printf("Qual o valor de a? ");
            if (scanf("%lf", &a) != 1) {
                printf("Entrada inválida! Tente novamente.\n");
                continue;
            }
            double fa = valor(p, a);
            double dfa = valor(dp, a);
            printf("a = %.2f, f(a) = %.2f, f'(a) = %.2f\n", a, fa, dfa);
        }

        printf("Deseja calcular a equacao da reta tangente ao grafico de f(x) no ponto P = (a, f(a))? (1 para sim, 0 para nao) ");
        scanf("%d", &calcular);
        if (calcular) {
            printf("Para qual valor de a gostaria de calcular? ");
            if (scanf("%lf", &a) != 1) {
                printf("Entrada inválida! Tente novamente.\n");
                continue;
            }
            double fa = valor(p, a);
            double dfa = valor(dp, a);
            printf("A equacao da reta tangente ao grafico de f(x) no ponto P = (%.2f, %.2f) sera y = %.2fx + %.2f\n", a, fa, dfa, fa - dfa*a);
        }

        printf("Deseja calcular a derivada para outra funcao? (1 para sim, 0 para nao) ");
        scanf("%d", &continuar);

        // Liberando a memória alocada
        free(p.coeficientes);
        free(dp.coeficientes);
    }

    return 0;
}
