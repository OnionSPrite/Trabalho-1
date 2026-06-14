#include <stdio.h>
#include <stdlib.h>
#define MAX 100

//O Codigo deve apresentar Erro nas ocasiões onde o Conjunto selecionado não existe.
//Um conjunto que não há numeros dentro mas foi declarado, ainda é um conjunto que EXISTE.

typedef struct { // Struct que define um conjunto de acordo com sua composicao
    int *elementos;
    int tamanho;
    int capacidade;
}Conjunto;

Conjunto* cria_conj(int capacidadeInicial){ //cria um conjunto novo
    Conjunto *c = (Conjunto*)malloc(sizeof(Conjunto));
    if(c == NULL){//verifica se o conjunto retorna NULL
        printf("Erro ao alocar memoria!");
        exit(1);
    }
    c->elementos = (int*)malloc(capacidadeInicial * sizeof(int));
        if(c->elementos == NULL){//verifica se retorna os elementos como NULL
            printf("Erro ao alocar memoria!");
            free(c);
            exit(1);
        }
    c->tamanho = 0;//define um tamanho inicial
    c->capacidade = capacidadeInicial;//define uma capacidade inicial
    return c;
}

void imprime_conjunto (Conjunto *con, int indice){//imprime um conjunto selecionado
    if(con == NULL){//caso o conjunto seja vazio
        printf("Conj %d {}\n", indice);
        return;
    }
    printf("Conj %d = {", indice);
    for(int i = 0; i < con->tamanho; i++){
        printf("%d", con->elementos[i]);
        if(i < con->tamanho - 1){
            printf(", ");
        }
    }
    printf("}\n");
}

void imprime_tudo (Conjunto **conjuntos, int n) { //Impressao de todos os conjuntos.
    for(int i = 0; i < n; i++){
        imprime_conjunto(conjuntos[i], i + 1);
    }
}

// Checa se um elemento de um conjunto pertence a outro
bool pertence(Conjunto *con, int elemento){
    for(int i = 0; i < con->tamanho; i++){
        if(con->elementos[i] == elemento){
            return true;
        }
    }
    return false;
}

// Da free no conjunto
void libera_conjunto(Conjunto *con){
    if(con != NULL){
        if(con->elementos != NULL){
            free(con->elementos);
        }
        free(con);
    }
}

// redimensiona e realoca a memoria de um conjunto
void redimensionar_conjunto(Conjunto *con){
    if(con->tamanho >= con->capacidade){
        con->capacidade *= 2;
        con->elementos = (int*)realloc(con->elementos, con->capacidade * sizeof(int*));
        if(con->elementos == NULL){//caso retorne NULL
            printf("Erro ao realocar memoria!");
            exit(1);
        }
    }
}

//Funcao para adicionar números no conjunto
void adicionar_num (Conjunto *con, int n){
    //Verifica se o conj existe
    if(con == NULL){
        printf("Erro! o conjunto nao existe!");
        return;
    }
    //Chama a funcao
    if(pertence(con, n)){
        return;
    }
    //Realoca a memoria
    redimensionar_conjunto(con);
    con->elementos[con->tamanho] = n;
    con->tamanho++;
}

//Funcao para Unir conjuntos
Conjunto* unir_conj (Conjunto *con1, Conjunto *con2){
    //cria um conjunto para resultado
    Conjunto *con3 = cria_conj(con1->tamanho + con2->tamanho);
    //Chama a funcao de adicionar para con1 e con2 construir o con3
    for(int i = 0; i < con1->tamanho; i++){
        adicionar_num(con3, con1->elementos[i]);
    }
    for(int j = 0; j < con2->tamanho; j++){
        adicionar_num(con3, con2->elementos[j]);
    }
    return con3;
}

//Cria um conjunto usando intercepto de dois conjuntos
Conjunto* intercept_conj (Conjunto *con1, Conjunto *con2){
    //cria um conjunto para resultado
    Conjunto *con3 = cria_conj(con1->tamanho);

    for (int i = 0; i < con1->tamanho; i++) {
      for (int j = 0; j < con1->tamanho; j++) {
            if (con1->elementos[i] == con2->elementos[j]) {//se os elementos são iguais adiciona no con3
              con3->elementos[con3->tamanho++] = con1->elementos[i];
              break;
            }
        }
    }
    return con3;
}
//Cria um conjunto usando a diferenca de dois conjuntos
Conjunto* diferenciar_conj (Conjunto *con1, Conjunto *con2){
    //cria um conjunto para resultado
    Conjunto *con3 = cria_conj(con1->tamanho);

    for(int i=0;i<con1->tamanho;i++) {
        if(!pertence(con2, con1->elementos[i])) {//verifica se o numero de um conjunto nao pertence ao outro(!pertence()) e adiciona a um terceiro conjunto
        con3->elementos[con3->tamanho] = con1->elementos[i];
        con3->tamanho++;
        }
    }
    return con3;
}

//Func que verifica se o conj existe
bool conj_existe(Conjunto **conjuntos, int num_conjuntos, int indice){
    if(indice < 1 || indice > num_conjuntos){//caso o conjunto nao exista
        printf("Erro! o conjunto %d nao existe.\n", indice);
        return false;
    }
    return true;
}

int main(){
    int n; //Quantidade inicial de conjuntos
    scanf("%d", &n);

    int capacidade_conjuntos = (n > 10) ? n : 10;//Define a capacidade total de conjuntos para um minimo de 10
    Conjunto **conjuntos = (Conjunto**)malloc(capacidade_conjuntos * sizeof(Conjunto*));// define uma array para os conjuntos
    if(conjuntos == NULL){//verifica se a array de conjuntos conseguiu ser definida
        printf("Erro ao alocar memoria!");
        return 1;
    }
    int num_conjuntos = n;//define numero total de conjuntos como n dado pelo usuário

    for(int i = 0; i < n; i++){//lê os conjuntos iniciais dados pelo usuário
        int tamanho;
        scanf("%d", &tamanho);
        conjuntos[i] = cria_conj(tamanho > 0 ? tamanho : 10);
        for(int j = 0; j < tamanho; j++){
            int elemento;
            scanf("%d", &elemento);
            adicionar_num(conjuntos[i], elemento);
        }
    }
    imprime_tudo(conjuntos, num_conjuntos);
    printf("\n");

char comando;
while(1){//while para começar as interações com a calculadora
    scanf(" %c", &comando);//escaneia a interação desejada pelo usuário (o espaço antes do '%c' é para evitar whitespaces)
    if(comando == '*'){//terminação do código caso seja recebido '*'
        break;
    }
    switch (comando) { //switch que recebe qual interação o usuário vai fazer na calculadora
        case '+':{//interação para adicionar número ao conjunto dado
            int i, x;
            scanf("%d %d", &i, &x);
            if(conj_existe(conjuntos, num_conjuntos, i)){
                adicionar_num(conjuntos[i - 1], x);
            }
            imprime_tudo(conjuntos, num_conjuntos);
            printf("\n");
            break;
        }

        case 'u':{//interação para unir conjuntos
            int i, j;
            scanf("%d %d", &i, &j);
            if(conj_existe(conjuntos, num_conjuntos, i) && conj_existe(conjuntos, num_conjuntos, j)){
                if(num_conjuntos >= capacidade_conjuntos){//verifica se precisa realocar a array de conjuntos
                    capacidade_conjuntos *= 2;
                    conjuntos = (Conjunto**)realloc(conjuntos, capacidade_conjuntos * sizeof(Conjunto*));
                    if(conjuntos == NULL){
                        printf("Erro ao redimensionar array de conjuntos!");
                        break;
                    }
                }
            conjuntos[num_conjuntos] = unir_conj(conjuntos[i - 1], conjuntos[j - 1]);
            num_conjuntos++;
            }
            imprime_tudo(conjuntos, num_conjuntos);
            printf("\n");
            break;
        }

        case 'i':{//interação para intersecção de conjuntos
            int i, j;
            scanf("%d %d", &i, &j);
            if(conj_existe(conjuntos, num_conjuntos, i) && conj_existe(conjuntos, num_conjuntos, j)){
                if(num_conjuntos >= capacidade_conjuntos){//verifica se precisa realocar a array de conjuntos
                    capacidade_conjuntos *= 2;
                    conjuntos = (Conjunto**)realloc(conjuntos, capacidade_conjuntos * sizeof(Conjunto*));
                    if(conjuntos == NULL){
                        printf("Erro ao redimensionar array de conjuntos!");
                        break;
                    }
                }
            conjuntos[num_conjuntos] = intercept_conj(conjuntos[i - 1], conjuntos[j - 1]);
            num_conjuntos++;
            }
            imprime_tudo(conjuntos, num_conjuntos);
            printf("\n");
            break;
        }

        case '-':{//interação de diferença entre conjuntos
            int i, j;
            scanf("%d %d", &i, &j);
            if(conj_existe(conjuntos, num_conjuntos, i) && conj_existe(conjuntos, num_conjuntos, j)){
                if(num_conjuntos >= capacidade_conjuntos){//verifica se precisa realocar a array de conjuntos
                    capacidade_conjuntos *= 2;
                    conjuntos = (Conjunto**)realloc(conjuntos, capacidade_conjuntos * sizeof(Conjunto*));
                    if(conjuntos == NULL){
                        printf("Erro ao redimensionar array de conjuntos!");
                        break;
                    }
                }
            conjuntos[num_conjuntos] = diferenciar_conj(conjuntos[i - 1], conjuntos[j - 1]);
            num_conjuntos++;
            }
            imprime_tudo(conjuntos, num_conjuntos);
            printf("\n");
            break;
        }
        default:
            printf("Comando invalido!\n");
            break;
        }

    }

    imprime_tudo(conjuntos, num_conjuntos);
    printf("\n");
    //libera todo o lixo de memoria ainda existente
    for(int i = 0; i < num_conjuntos; i++){
        libera_conjunto(conjuntos[i]);
    }
    free(conjuntos);
    return 0;
}
