#include <stdio.h>
#include <stdlib.h>
#define MAX 100

//Horas gastas no código: 4 (Atualize sempre que mexer no código :D);
//NÃO ESQUECER O PONTO E VÍRGULA (;);
//NÃO ESQUECER O 'E UNIVERSAL (&)' NO SCANF;
//Conferir SEMPRE as chaves ({});
//COMENTE NO CÓDIGO;
//O Codigo deve apresentar Erro nas ocasiões onde o Conjunto selecionado não existe.
//Um conjunto que não há numeros dentro mas foi declarado, ainda é um conjunto que EXISTE.

struct leitura_de_cmd { // Struct que define o comando executado dentro da nossa calculadora, o conjunto selecionado e o valor inserido;
    char interacao[1];
    int conjunto;
    int valor;
};

void imprime_conjuntos (int m[MAX][MAX], int col[MAX], int n) { //Funcao que faz a impressao dos conjuntos, do 1 ao ultimo;
    for (int i = 0; i < n; i++) {
        printf("Conj %d: {", (i + 1));
        for (int j = 0; j < col[i]; j++) {
            printf("%d", m[i][j]);
            if (j + 1 < col[i]) {
                printf(", ");
            }
        }
        printf("}\n");
    }
}

int main(){
    int n, c, col[MAX], m[MAX][MAX]; // Definicao das variaveis
    struct leitura_de_cmd comando;
    scanf("%d", &n); // Quantidade inicial de conjuntos

    for (int i = 0; i < n; i++) { // Criacao dos conjuntos inicias
        scanf("%d", &c);
        col[i] = c;
        for (int j = 0; j < c; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    while (comando.interacao[0] != "*") { // Calculadora SUPER CALCULADORA de conjuntos SUPER CONJUNTOS;                    !!!!!!!!!!!!!!!!! SEM FUNCIONAR !!!!!!!!!!!!!!!!!
        scanf("%s %d %d", comando.interacao[0], &comando.conjunto, &comando.valor); // Recebe do usuario o que sera feito em sequencia;
    }

    return 0;
}
