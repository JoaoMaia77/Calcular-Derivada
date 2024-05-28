#include <stdio.h>

// Estrutura para representar um polinômio
typedef struct {
    int grau;
    double coeficientes[100];
} Polinomio;

// Função para calcular a derivada de um polinômio
Polinomio derivada(Polinomio p) {
    Polinomio dp;
    dp.grau = p.grau - 1;
    for (int i = 0; i < p.grau; i++) {
        dp.coeficientes[i] = p.coeficientes[i+1] * (i + 1);
    }
    return dp;
}

// Função para imprimir um polinômio
void imprimirPolinomio(Polinomio p) {
    for (int i = p.grau; i >= 0; i--) {
        printf("%lfx^%d ", p.coeficientes[i], i);
        if (i > 0) {
            printf("+ ");
        }
    }
    printf("\n");
}

int main() {
    Polinomio p;
    printf("Qual o grau do polinômio? ");
    scanf("%d", &p.grau);
    for (int i = p.grau; i >= 0; i--) {
        printf("Digite o coeficiente de x^%d: ", i);
        scanf("%lf", &p.coeficientes[i]);
    }
    printf("f(x) = ");
    imprimirPolinomio(p);
    Polinomio dp = derivada(p);
    printf("f'(x) = ");
    imprimirPolinomio(dp);
    return 0;
}
