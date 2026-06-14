#include <stdio.h>
#include <stdlib.h>
#define MAX 100

//Horas gastas no código: 5 (Atualize sempre que mexer no código :D);
//NÃO ESQUECER O PONTO E VÍRGULA (;);
//NÃO ESQUECER O 'E UNIVERSAL (&)' NO SCANF;
//Conferir SEMPRE as chaves ({});
//COMENTE NO CÓDIGO;
//O Codigo deve apresentar Erro nas ocasiões onde o Conjunto selecionado não existe.
//Um conjunto que não há numeros dentro mas foi declarado, ainda é um conjunto que EXISTE.

typedef struct { // Struct que define os conjuntos
    int *elementos;
    int tamanho;
    int capacidade;
}Conjunto;

//inicia um conjunto vazio
Conjunto* cria_conj(int capacidadeInicial){
    Conjunto *c = (Conjunto*)malloc(sizeof(Conjunto));
    if(c == NULL){
        printf("Erro de alocação de memória!");
        exit(1);
    }
    c->elementos = (int*)malloc(capacidadeInicial * sizeof(int));
        if(c->elementos == NULL){
            printf("Erro de alocação de memória!");
            free(c);
            exit(1);
        }
    c->tamanho = 0;
    c->capacidade = capacidadeInicial;
    return c;
}

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
    int x = 0;
    int *con3;
    *con3 = *con1;
    for (int i = 0; i < maior_conjunto; i++){
        if(con1[i] != con2[i]){
            aux[z] = con2[i];
            z++;
        }
    }

    int tamanho_conj3 = maior_conjunto + z;
    for (int i = 0; i < tamanho_conj3; i++){
    if (con3[i] == NULL){
    con3[i] = aux[x]
    x++
       }
    }

    return *con3;
}

int intercept_conj (int *con1, int *con2){
    int tamanho_conj1 = sizeof(con1)/sizeof(con1[0]);
    int tamanho_conj2 = sizeof(con2)/sizeof(con2[0]);
    int maior_conjunto;
    if(tamanho_conj1 > tamanho_conj2){
        maior_conjunto = tamanho_conj1;
    }else{
        maior_conjunto = tamanho_conj2;
    }
    int z = 0;
    int x = 0;
    int *con3;
       for (int i = 0; i < maior_conjunto; i++){
        if(con1[i] = con2[i]){
            con3[z] = con2[i];
            z++;
        }
    }

    return *con3;
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

char comando;
while(1){
    scanf("%c", &comando);
    if(comando == '*'){
        break;
    }
    switch (comando) { //switch que recebe qual interação o usuário vai fazer na calculadora
        case '+':{
            int i, j;
        }

        case 'u':{
            int i, j;
        }

        case 'i':{
            int i, j;
        }

        case '-':{
            int i, j;
        }
    }

}

    for (int i = 0; i < n; i++) {
        free(m[i]);
    }
    free(m);
    free(col);

    return 0;
}
