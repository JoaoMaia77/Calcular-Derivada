#include <stdio.h>
#include <math.h>

typedef struct {
    int grau;
    double coeficientes[100];
} Polinomio;

Polinomio derivada(Polinomio p) {
    Polinomio dp;
    dp.grau = p.grau - 1;
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
        printf("%.2fx^%d ", p.coeficientes[i], i);
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
        printf("Qual o grau do polinomio? ");
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
        printf("Deseja calcular o valor funcional f'(a)? (1 para sim, 0 para nao) ");
        int calcular;
        scanf("%d", &calcular);
        if (calcular) {
            printf("Qual o valor de a? ");
            scanf("%lf", &a);
            double fa = valor(p, a);
            double dfa = valor(dp, a);
            printf("a = %.2f, f(a) = %.2f, f'(a) = %.2f\n", a, fa, dfa);
        }

        printf("Deseja calcular a equacao da reta tangente ao grafico de f(x) no ponto P = (a, f(a))? (1 para sim, 0 para nao) ");
        scanf("%d", &calcular);
        if (calcular) {
            printf("Para qual valor de a gostaria de calcular? ");
            scanf("%lf", &a);
            double fa = valor(p, a);
            double dfa = valor(dp, a);
            printf("A equacao da reta tangente ao grafico de f(x) no ponto P = (%.2f, %.2f) sera y = %.2fx + %.2f\n", a, fa, dfa, fa - dfa*a);
        }

        printf("Deseja calcular a derivada para outra funcao? (1 para sim, 0 para nao) ");
        scanf("%d", &continuar);
    }

    return 0;
}
