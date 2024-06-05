#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1
void swap(int v[], int x, int y) {
    int temp = v[x];
    v[x] = v[y];
    v[y] = temp;
}

int nesimo(int s[], int N, int i) {
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N - j - 1; k++) {
            if (s[k] > s[k+1]) swap(s, k, k+1);
        }
    }
    return s[i - 1];
}

//2
typedef struct LInt_nodo {
    int valor;
    struct LInt_nodo* prox;
} *LInt;

LInt removeMaiores(LInt l, int x) {
    LInt atual = l, prev = NULL;

    for (; atual != NULL; prev = atual, atual = atual->prox) {
        if (atual->valor > x) {
            if (atual == l) {
                l = l->prox;
                free(atual);
                atual = l;
            }
            else {
                prev->prox = atual->prox;
                free(atual);
                atual = prev;
            }
        }
    }
    return l;
}

typedef struct ABin_nodo {
    int valor;
    struct ABin_nodo* esq, * dir;
} *ABin;

//3

LInt caminho(ABin a, int x) {
    if (a == NULL) {
        return NULL;
    }
    if (a->valor == x) {
        LInt new_node = (LInt)malloc(sizeof(struct LInt_nodo));
        new_node->valor = x;
        new_node->prox = NULL;
        return new_node;
    }
    LInt path;
    if (a->valor > x) {
        path = caminho(a->esq, x);
    }
    else {
        path = caminho(a->dir, x);
    }
    if (path != NULL) {
        LInt new_node = (LInt)malloc(sizeof(struct LInt_nodo));
        new_node->valor = a->valor;
        new_node->prox = path;
        return new_node;
    }
    return NULL;
}

//4

void inc(char s[]) {
    int length = strlen(s);
    int i;
    int r = 0;
    for(i = length - 1; i >= 0 && !r; i--) {
      if (s[i] == '9') {
        s[i] = '0';
      } else {
        s[i] = s[i] + 1;
        r = 1;
      }
    }
}

//5

int ceil2(float num) {
    int number = (int)num;
    if (num == (float)number) {
        return number;
    }
    return number + 1;
}

int sacos(int p[], int N, int C){
    int soma = 0;
    int i;
    for(i = 0; i < N; i++){
        soma += p[i];
    }
    float num_sacos = soma / C;
    int sacos = ceil2(num_sacos);
    return sacos;
}

int main() {
    /*int s[] = {5, 3, 8, 1, 2};
    int N = sizeof(s) / sizeof(s[0]);
    int i = 5;

    int result = nesimo(s, N, i);

    printf("The %dth smallest element is %d\n", i, result);

    return 0;
    */
    int arr[] = {5, 3, 8, 4, 2, 7, 1, 6};
    int N = sizeof(arr) / sizeof(arr[0]);
    int i = 4; // For example, find the 4th smallest element

    int result = nesimo(arr, N, i);
    printf("The %d-th smallest element is: %d\n", i, result);

    return 0;
}
