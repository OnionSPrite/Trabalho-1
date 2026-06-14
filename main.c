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

void adcionar_num (int *con, int n){
    int tamanho_conj = sizeof(con)/sizeof(con[0]);
    for(int i = 0; i < tamanho_conj; i++){
        if(n == con[i]){
            printf("Erro! O numero ja esta no conjunto\n");
            break;
        }else{
            for(int j = 0; j < tamanho_conj; j++){
                if(con[i] == NULL){
                    con[i] = n;
                    break;
                }
            }
        }
    }
}

int unir_conj (int *con1, int *con2){
    int tamanho_conj1 = sizeof(con1)/sizeof(con1[0]);
    int tamanho_conj2 = sizeof(con2)/sizeof(con2[0]);
    int maior_conjunto;
    if(tamanho_conj1 > tamanho_conj2){
        maior_conjunto = tamanho_conj1;
    }else{
        maior_conjunto = tamanho_conj2;
    }
    int aux[MAX];
    int z = 0;
    int *con3;
    *con3 = *con1;
    for (int i = 0; i < maior_conjunto; i++){
        if(con1[i] != con2[i]){
            aux[z] = con2[i];
            z++;
        }
    }
    for (int j = 0; j < tamanho_conj1; j++){

    }

    return *con3;
}

int main(){
    int n, c, *col, **m, num_conjuntos; // Definicao das variaveis
    struct leitura_de_cmd comando;
    scanf("%d", &n); // Quantidade inicial de conjuntos
    c = (int)malloc(n * sizeof(int));
    m = (int **)malloc(n * sizeof(int *));
    num_conjuntos = n;

    for (int i = 0; i < n; i++) { // Criacao dos conjuntos inicias
        scanf("%d", &c);
        col[i] = c;
        for (int j = 0; j < c; j++) {
            scanf("%d", m[i][(int)malloc(c * sizeof(int))]);
        }
    }

    while (comando.interacao[0] != "*") { // Calculadora SUPER CALCULADORA de conjuntos SUPER CONJUNTOS;
        scanf("%s %d %d", comando.interacao[0], &comando.conjunto, &comando.valor); // Recebe do usuario o que sera feito em sequencia;
    }

    for (int i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);
    free(col);

    return 0;
}
