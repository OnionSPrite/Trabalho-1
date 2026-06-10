#include <stdio.h>
#include <stdlib.h>
#define MAX 100

//Horas gastas no código: 1 (Atualze sempre que mexer no código :D);
//NÃO ESQUECER O PONTO E VÍRGULA (;);
//NÃO ESQUECER O 'E UNIVERSAL (&)' NO SCANF;
//Conferir SEMPRE as chaves ({});
//COMENTE NO CÓDIGO;
//O Codigo deve apresentar Erro nas ocasiões onde o Conjunto selecionado não existe.
//Um conjunto que não há numeros dentro mas foi declarado, ainda é um conjunto que EXISTE.

int main()
{
    int n, m[MAX][MAX];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j == j; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; m[i][j] != NULL; j++) {
            printf("%d ", m[i][j]);
        }
    }

    return 0;
}
