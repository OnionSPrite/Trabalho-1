#include <stdio.h>
#include <stdlib.h>
#define MAX 100

//Horas gastas no código: 1 (Atualze sempre que mexer no código :D);
//NÃO ESQUECER O PONTO E VÍRGULA (;);
//NÃO ESQUECER O 'E UNIVERSAL (&)' NO SCANF;
//Conferir SEMPRE as chaves ({});
//COMENTE NO CÓDIGO;

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
