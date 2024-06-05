#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1

int pesquisa(int a[], int N, int x) {
    int esq = 0;
    int dir = N - 1;
    while (esq <= dir) {
        int meio = (esq + dir) / 2;
        if (a[meio] == x) {
            return meio;
        }
        else if (a[meio] < x) {
            esq = meio + 1;
        }
        else {
            dir = meio - 1;
        }
    }
    return -1;
}

//2

typedef struct LInt_nodo {
    int valor;
    struct LInt_nodo* prox;
} *LInt;

void roda(LInt* l) {
    if (*l == NULL || (*l)->prox == NULL) {
        return;
    }

    LInt atual = *l;
    LInt prev = NULL;
    while (atual->prox != NULL) {
        prev = atual;
        atual = atual->prox;
    }
    prev->prox = NULL;
    atual->prox = *l;
    *l = atual;
}

//3 impossivel :)

typedef struct ABin_nodo {
    int valor;
    struct ABin_nodo* esq, * dir;
} *ABin;

//4

void checksum(char s[]) {
    int i, soma = 0, length = strlen(s);
    for (i = 0; s[i] != '\0'; i++) {
        int digito = s[i] - '0'; // char para int
        if ((length - i) % 2 == 0) {
            digito *= 2;
            if (digito > 9) {
                digito = digito / 10 + digito % 10;
            }
        }
        soma += digito;
    }

    int checksum_digito = (10 - (soma % 10)) % 10;
    s[i] = checksum_digito + '0'; // int para char
    s[i + 1] = '\0'; //adiciona fim
}


//5

void swap(int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int escolhe(int N, int valor[], int peso[], int C, int quant[]) {
    int i, j;
    int soma = 0, somapeso = 0;

    for (i = 0; i < N - 1; i++) {
        for (j = 0; j < N - i - 1; j++) {
            if (valor[j] < valor[j + 1]) {
                swap(valor, j, j + 1);
                swap(peso, j, j + 1);
            }
        }
    }
    
    i = 0;
    while (somapeso + peso[0] <= C) {
        soma += valor[0];
        somapeso += peso[0];
        quant[0]++;
    }

    i = 1;
    while (i < N && somapeso + peso[i] <= C) {
        soma += valor[i];
        somapeso += peso[i];
        quant[i]++;
        i++;
    }

    return soma;
}

int main() {
    int N = 3;
    int valor[] = {20, 150, 30};
    int peso[] = {2, 10, 3};
    int C = 14;
    int quant[N];

    int soma = escolhe(N, valor, peso, C, quant);

    printf("Valor total: %d\n", soma);

    return 0;
}
// da 180 em vez de 190 ja nao e mau