#include <stdio.h>
#include <stdlib.h>

int fizz(int n);
int buzz(int n);

//1
/*
int fizzbuzz(int n) {
    int fibuzz = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (fizz(i) && buzz(i)){
           if(!fibuzz) fibuzz = 1;
           printf("FizzBuzz\n");
        }
        else if (fizz(i)) printf("Fizz\n");
        else if (buzz(i)){
            if(fibuzz) return count;
            printf("Buzz\n");
        }
        else {
            if(fibuzz) count++;
            printf("%d\n", i);
        }
    }
    return -1;
}
*/

//2

void rodaEsq(int a[], int N, int r) {
    int i, j, contador = 0;
    int temp[r];
    for (i = 0; i < r; i++) {
        temp[i] = a[i];
    }

    for (j = 0;j < N; j++) {
        if (j + r < N) a[j] = a[j + r];

        else a[j] = temp[contador++];
    }

}

//3

typedef struct lint_nodo {
    int valor;
    struct lint_nodo* prox;
} *LInt;

int delete(int n, LInt* l) {
    LInt prev = *l;
    LInt atual = *l;
    int i = 0;
    if (!l || n < 0) return 1;

    if (n == 0) {
        *l = atual->prox;
        free(atual);
        return 0;
    }

    while (prev->prox && i < n) {
        prev = atual;
        atual = atual->prox;
        i++;
    }

    prev->prox = atual->prox;
    free(atual);
    return 0;
}

int maxCresc(LInt l) {
    if (!l) return 0;
    int maxseq = 0;
    int count = 1;

    for (;l && l->prox; l = l->prox) {
        if (l->prox->valor > l->valor)count++;
        else {
            if (count > maxseq) {
                maxseq = count;
            }
            count = 1;
        }
    }

    if (count > maxseq) {
        maxseq = count;
        count = 1;
    }

    return maxseq;
}

typedef struct abin_nodo {
    int valor;
    struct abin_nodo* esq, * dir;
} *ABin;

//5

ABin folhaEsq(ABin a) {
    if(!a) return NULL;

    if(!a->esq && !a->dir) return a;

    while(a->esq || a->dir){
        if(!a->esq) a = a->dir;

        else a = a->esq;
    }

    return folhaEsq(a);
}

//6
int parentesisOk(char exp[]){
    int idk;
    int length = strlen(exp);
    for(int i = 0; i < length; i++){
        idk += 1;
    }

    return idk;
}


//2
// int main() {
//     int s[] = { 1, 2, 3, 4, 5 };
//     int N = sizeof(s) / sizeof(s[0]);
//     int r = 2;

//     rodaEsq(s, N, r);

//     for (int i = 0; i < N; i++) {
//         printf("%d ", s[i]);
//     }
//     printf("\n");

//     return 0;
// }

//3
// int main() {
//     // Criar uma lista ligada
//     LInt head = malloc(sizeof(struct lint_nodo));
//     head->valor = 1;
//     head->prox = malloc(sizeof(struct lint_nodo));
//     head->prox->valor = 2;
//     head->prox->prox = malloc(sizeof(struct lint_nodo));
//     head->prox->prox->valor = 3;
//     head->prox->prox->prox = NULL;

//     // Testar a função delete
//     printf("Antes de deletar:\n");
//     LInt temp = head;
//     while (temp) {
//         printf("%d ", temp->valor);
//         temp = temp->prox;
//     }
//     printf("\n");

//     delete(1, &head);

//     printf("Depois de deletar:\n");
//     temp = head;
//     while (temp) {
//         printf("%d ", temp->valor);
//         temp = temp->prox;
//     }
//     printf("\n");

//     // Liberar a memória
//     while (head) {
//         LInt next = head->prox;
//         free(head);
//         head = next;
//     }

//     return 0;
// }

//4
// int main() {
//     // Create a linked list
//     LInt head = malloc(sizeof(struct lint_nodo));
//     LInt current = head;
//     int values[] = { 1, 2, 3, 2, 1, 4, 10, 12, 5, 4 };
//     int n = sizeof(values) / sizeof(values[0]);

//     for (int i = 0; i < n; i++) {
//         current->valor = values[i];
//         if (i < n - 1) {
//             current->prox = malloc(sizeof(struct lint_nodo));
//             current = current->prox;
//         }
//         else {
//             current->prox = NULL;
//         }
//     }

//     // Test the maxCresc function
//     int max = maxCresc(head);
//     printf("The maximum increasing sequence length is: %d\n", max);

//     // Free the memory
//     while (head) {
//         LInt next = head->prox;
//         free(head);
//         head = next;
//     }

//     return 0;
// }

ABin newNode(int value) {
    ABin new = (ABin) malloc(sizeof(struct abin_nodo));
    new->valor = value;
    new->esq = NULL;
    new->dir = NULL;
    return new;
}

int main() {
    ABin root = newNode(1);
    root->esq = newNode(2);
    root->dir = newNode(3);
    root->esq->esq = newNode(4);
    root->esq->dir = newNode(5);

    printf("The value of the leftmost leaf node is: %d\n", folhaEsq(root));

    return 0;
}
