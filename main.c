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

// Função para calcular o valor de um polinômio em um ponto
double valor(Polinomio p, double x) {
    double valor = 0;
    for (int i = 0; i <= p.grau; i++) {
        valor += p.coeficientes[i] * pow(x, i);
    }
    return valor;
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
    int continuar = 1;
    while (continuar) {
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

        double a;
        printf("Deseja calcular o valor funcional f'(a)? (1 para sim, 0 para não) ");
        int calcular;
        scanf("%d", &calcular);
        if (calcular) {
            printf("Qual o valor de a? ");
            scanf("%lf", &a);
            double fa = valor(p, a);
            double dfa = valor(dp, a);
            printf("a = %lf, f(a) = %lf, f'(a) = %lf\n", a, fa, dfa);
        }

        printf("Deseja calcular a equação da reta tangente ao gráfico de f(x) no ponto P = (a, f(a))? (1 para sim, 0 para não) ");
        scanf("%d", &calcular);
        if (calcular) {
            printf("Para qual valor de a gostaria de calcular? ");
            scanf("%lf", &a);
            double fa = valor(p, a);
            double dfa = valor(dp, a);
            printf("A equação da reta tangente ao gráfico de f(x) no ponto P = (%lf, %lf) será y = %lfx + %lf\n", a, fa, dfa, fa - dfa*a);
        }

        printf("Deseja calcular a derivada para outra função? (1 para sim, 0 para não) ");
        scanf("%d", &continuar);
    }

    return 0;
}
