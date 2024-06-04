# Cálculo de Derivadas em C
Este é um projeto para a disciplina de Cálculo 1 na PUC Minas. O objetivo é estudar e codificar algoritmos para resolver problemas sobre funções polinomiais e suas derivadas.

## Grupo
Este trabalho foi elaborado por um grupo de 4 pessoas.<br>
https://github.com/PaulaNogueiraC<br>
https://github.com/alicecazati<br>


## Tarefas
O programa que desenvolvemos realiza cálculos envolvendo as regras de derivação. Aqui estão alguns dos recursos que nosso programa oferece:

1. Solicita ao usuário uma função polinomial $$f(x)$$ de grau $$n$$. Exponente 1, coeficiente 1 e expoente zero não precisam ser digitados.
2. Calcula a derivada da função $$f(x)$$ e apresenta ao usuário a função e sua derivada da seguinte forma: $$f(x) = ...$$ e $$f'(x) = ...$$
3. Após o cálculo da derivada, o programa pergunta ao usuário se ele deseja calcular o valor funcional da derivada em um número real $$a$$. Se sim, solicita o valor de $$a$$ e apresenta os resultados na tela: $$a = ...$$, $$f(a) = ...$$, $$f'(a) = ...$$, $$P = (a, f(a))$$
4. Em seguida, pergunta ao usuário se ele deseja calcular a equação da reta tangente ao gráfico de $$f(x)$$ no ponto $$P = (a, f(a))$$. Se sim, solicita o valor de $$a$$ e imprime na tela os resultados na forma: "A equação da reta tangente ao gráfico de $$f(x) = ...$$ no ponto $$P = (a, f(a))$$ será ..."

## Exemplo
Para a função $$f(x) = x^3 - 2x^2 - 1$$, temos que $$f'(x) = 3x^2 - 4x$$. Se escolhermos $$a = 1$$, teremos $$f(1) = -2$$, $$f'(1) = -1$$ e $$P = (1, -2)$$. A equação da reta tangente ao gráfico de $$f(x) = x^3 - 2x^2 - 1$$ no ponto $$P = (1, -2)$$ será $$y = -x + 3$$.
