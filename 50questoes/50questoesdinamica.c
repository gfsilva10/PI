#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lligada {
    int valor;
    struct lligada* prox;
} *LInt;

//1
int length(LInt l) {
    int count = 0;
    while (l != NULL) {
        count++;
        l = l->prox;
    }
    return count;
}

//2
void freeL(LInt l) {
    LInt temp;
    while (l != NULL) {
        temp = l;
        l = l->prox;
        free(temp);
    }
}

//3
void imprimeL(LInt l) {
    while (l != NULL) {
        printf("%d\n", l->valor);
        l = l->prox;
    }
}

//4
LInt reverseL(LInt l) {
    LInt front, back = NULL;

    while (l) {
        front = l->prox; // sets front to the next node in the original list 
        l->prox = back; // next node of the current node becomes the head of the reversed list
        back = l; // back to be the current node (l), which is now the head of the reversed list.
        l = front; // l to be front, which is the next node in the original list.
    }

    return back;
}
// each time adds the current node to the start of the reversed list.

void insertOrd(LInt* l, int x) {
    LInt new;
    new = malloc(sizeof(struct lligada));
    new->valor = x;
    new->prox = NULL;
    while (*l != NULL && (*l)->valor < x) {
        l = &((*l)->prox);
    }
    new->prox = (*l);
    *l = new;
}

int removeOneOrd(LInt* l, int x) {
    LInt prev = NULL;
    for (;*l && x != (*l)->valor; prev = *l, l = &((*l)->prox));
    if (!(*l)) return 1;
    if (!prev) (*l) = (*l)->prox;
    else prev->prox = (*l)->prox;
    return 0;
}

// 7

void merge(LInt* r, LInt a, LInt b) {
    if (!a && !b) return;
    if (b == NULL || a != NULL && a->valor < b->valor) {
        (*r) = a;
        merge(&((*r)->prox), a->prox, b);
    }
    else {
        (*r) = b;
        merge(&((*r)->prox), a, b->prox);
    }
}

// 8

void splitQS(LInt l, int x, LInt* mx, LInt* Mx) {
    if (!l) return;
    if (l->valor < x) {
        (*mx) = l;
        (*Mx) = NULL;
        splitQS(l->prox, x, &((*mx)->prox), Mx);
    }
    else {
        (*Mx) = l;
        (*mx) = NULL;
        splitQS(l->prox, x, mx, &((*Mx)->prox));
    }
}

// 9

LInt parteAmeio(LInt* l) {
    int meio = length(*l) / 2;
    if (meio == 0) return NULL;
    LInt y = (*l);
    LInt prev = NULL;
    for (int i = 0; i < meio; i++) {
        prev = (*l);
        (*l) = (*l)->prox;
    }
    prev->prox = NULL;
    return y;
}

// 10

int removeAll(LInt* l, int x) {
    int rem = 0;
    LInt prev = NULL;
    while (*l) {
        if ((*l)->valor == x) {
            if (!prev) (*l) = (*l)->prox;
            else prev->prox = (*l)->prox;
            rem++;
        }
        else {
            prev = (*l);
            l = &((*l)->prox);
        }
    }
    return rem;
}

// 11

int removeDups(LInt* l) {
    int rem = 0;
    for (;*l; l = &((*l)->prox)) {
        LInt prevAux = (*l), aux = (*l)->prox;
        for (; aux; aux = prevAux->prox) {
            if (aux->valor == (*l)->valor) {
                prevAux->prox = aux->prox;
                rem++;
                free(aux);
            }
            else prevAux = aux;
        }
    }
    return rem;
}

// 13

void init(LInt* l) {
    LInt prev = NULL;
    for (;(*l)->prox;prev = *l, l = &((*l)->prox));
    if (!prev) {
        free(*l);
        *l = NULL;
    }
    else {
        prev->prox = NULL;
        free(*l);
    }
}

// 14

void appendL(LInt* l, int x) {
    LInt new = malloc(sizeof(struct lligada));
    new->valor = x;
    new->prox = NULL;
    if (!(*l)) (*l) = new;
    else {
        for (;(*l)->prox; l = &((*l)->prox));
        (*l)->prox = new;
    }
}

// 15

void concatL(LInt* a, LInt b) {
    if (*a) concatL(&((*a)->prox), b);
    else (*a) = b;
}

// 16

LInt cloneL(LInt l) {
    if (!l) return NULL;
    LInt new = malloc(sizeof(struct lligada));
    new->valor = l->valor;
    new->prox = cloneL(l->prox);
    return new;
}

//17

LInt cloneRev(LInt l) {
    LInt list = NULL;
    while (l) {
        LInt new = malloc(sizeof(struct lligada));
        new->valor = l->valor;
        new->prox = list;
        list = new;
        l = l->prox;
    }
    return list;
}

//18

int maximo(LInt l) {
    int maior = l->valor;
    while (l != NULL) {
        if (l->valor > maior) maior = l->valor;
        l = l->prox;
    }
    return maior;
}

//19

int take(int n, LInt* l) {
    int i;
    for (i = 0; l != NULL && i < n;i++, l = &((*l)->prox))
        if (!(*l)) return i;
    for (;*l;) {
        LInt temp = (*l)->prox;
        free(*l);
        *l = temp;
    }
    return n;
}

//20

int drop(int n, LInt* l) {
    int i;
    for (i = 0; i < n && (*l); i++) {
        LInt temp = (*l);
        (*l) = (*l)->prox;
        free(temp);
    }
    return i;
}

//21

LInt Nforward(LInt l, int N) {
    for (int i = 0; i < N; i++) {
        l = l->prox;
    }
    return l;
}

//22

int listToArray(LInt l, int v[], int N) {
    int i;
    for (i = 0; i < N && l; l = l->prox) v[i++] = l->valor;
    return i;
}

//23

LInt arrayToList(int v[], int N) {
    if (N == 0) return NULL;
    LInt new = malloc(sizeof(struct lligada));
    new->valor = (*v);
    new->prox = arrayToList(v + 1, N - 1);
    return new;
}

//24

LInt somasAcL(LInt l) {
    int sum = 0;
    LInt list = NULL, temp = NULL;
    for (;l; l = l->prox) {
        sum += l->valor;
        LInt new = malloc(sizeof(struct lligada));
        new->valor = sum;
        new->prox = NULL;
        if (!list) list = temp = new;
        else temp = temp->prox = new;
    }
    return list;
}

//25

void remreps(LInt l) {
    if (l) {
        while (l->prox) {
            if (l->prox->valor == l->valor) {
                LInt temp = l->prox;
                l->prox = temp->prox;
                free(temp);
            }
            else l = l->prox;
        }
    }
}

//26

LInt rotateL(LInt l) {
    if (!l || !(l->prox)) return l;
    LInt temp = l;
    LInt list = l->prox;
    while (temp->prox) temp = temp->prox;
    temp->prox = l;
    l->prox = NULL;
    return list;
}

//27

LInt parte(LInt l) {
    if (!l || !l->prox) return NULL;
    LInt newL = l->prox;
    l->prox = l->prox->prox;
    newL->prox = parte(l->prox);
    return newL;
}

//Trees

typedef struct nodo {
    int valor;
    struct nodo* esq, * dir;
} *ABin;

//28

int maximo2(int a, int b) {
    return a > b ? a : b;
}

int altura(ABin a) {
    if (!a) return 0;
    else return 1 + maximo2(altura(a->esq), altura(a->dir));
}

//29

ABin cloneAB(ABin a) {
    if (!a) return NULL;
    ABin new = malloc(sizeof(struct nodo));
    new->valor = a->valor;
    new->esq = cloneAB(a->esq);
    new->dir = cloneAB(a->dir);
    return new;
}

//30

void mirror(ABin* a) {
    if (a) {
        ABin temp = (*a)->esq;
        (*a)->esq = (*a)->dir;
        (*a)->dir = temp;
        mirror(&((*a)->esq));
        mirror(&((*a)->dir));
    }
}

//31

void inorder(ABin a, LInt* l) {
    if (a == NULL) *l = NULL;
    if (a) {
        inorder(a->esq, l);

        while (*l) {
            l = &((*l)->prox);
        }
        *l = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        inorder(a->dir, &(*l)->prox);
    }
}

//32

void preorder(ABin a, LInt* l) {
    if (a == NULL) *l = NULL;
    if (a) {
        *l = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;

        preorder(a->esq, &(*l)->prox);
        while (*l) {
            l = &((*l)->prox);
        }

        preorder(a->dir, &((*l)->prox));
    }
}

//33

void postorder(ABin a, LInt* l) {
    if (a == NULL) *l = NULL;
    if (a) {
        postorder(a->esq, l);
        while (*l) {
            l = &((*l)->prox);
        }
        postorder(a->dir, l);
        while (*l) {
            l = &((*l)->prox);
        }
        *l = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        (*l)->prox = NULL;
    }
}

//34

int depth(ABin a, int x) {
    if (!a) return -1;

    if (a->valor == x) return 1;

    int esq = depth(a->esq, x);
    int dir = depth(a->dir, x);

    if (esq == -1 && dir == -1) return -1;
    if (esq == -1) return 1 + dir;
    if (dir == -1) return 1 + esq;
    return esq < dir ? 1 + esq : 1 + dir;
}

// 35

int freeAB(ABin a) {
    if (!a) return 0;
    int n = 1 + freeAB(a->esq) + freeAB(a->dir);
    free(a);
    return n;
}

//36

int pruneAB(ABin* a, int l) {
    if (!a) return 0;

    if (l == 0) {

    }
}

//37

int iguaisAB(ABin a, ABin b) {
    if (!a && b || a && !b) return 0;

    if (a == b || !a && !b) return 1;

    return (a->valor == b->valor) && iguaisAB(a->esq, b->esq) && iguaisAB(a->dir, b->dir);
}

//38

LInt concat(LInt a, LInt b) {
    if (!a) return b;
    LInt temp = a;

    while (temp->prox) temp->prox;
    temp->prox = b;
    return a;
}

LInt nivelL(ABin a, int n) {
    LInt new = malloc(sizeof(struct lligada));
    new->valor = a->valor;
    new->prox = NULL;

    if (!a || n < 1) return NULL;
    if (n == 1) return new;

    else concat(nivelL(a->esq, n - 1), nivelL(a->dir, n - 1));

}

//39

int nivelV(ABin a, int n, int v[]) {
    if (!a || n < 1) return 0;
    if (n == 1) {
        *v = a->valor;
        return 1;
    }
    else {
        int e = nivelV(a->esq, n - 1, v);
        int d = nivelV(a->dir, n - 1, v + e);
        return e + d;
    }
}

//40

int dumpAbin(ABin a, int v[], int N) {

    if (!a || N < 0)
        return 0;

    int e = dumpAbin(a->esq, v, N);
    if (e < N) {
        *(v + e) = a->valor;
        return e + dumpAbin(a->dir, v + e + 1, N - e - 1) + 1;
    }
    else
        return N;

}

//41

ABin somasAcA(ABin a) {
    if (!a) return NULL;
    ABin new = malloc(sizeof(struct nodo));
    new->esq = somasAcA(a->esq);
    new->dir = somasAcA(a->dir);
    new->valor = a->valor + (new->esq ? new->esq->valor : 0) + (new->dir ? new->dir->valor : 0);
    return new;
}

//42

int contaFolhas(ABin a) {
    if (!a) return 0;

    if (!a->esq && !a->dir) return 1;

    else return  contaFolhas(a->esq) + contaFolhas(a->dir);
}

//43

ABin cloneMirror(ABin a) {
    if (!a) return NULL;
    ABin new = malloc(sizeof(struct nodo));
    new->valor = a->valor;
    new->esq = cloneMirror(a->dir);
    new->dir = cloneMirror(a->esq);
    return new;
}

//44


//45

int lookupAB(ABin a, int x) {
    if (!a) return 0;

    if (a->valor == x) return 1;

    if (a->valor < x) return lookupAB(a->dir, x);
    else return lookupAB(a->esq, x);
}

//46

int depthOrd(ABin a, int x) {
    int d = 0, e = 0;
    if (!a) return -1;

    if (a->valor == x) return 1;

    else {
        if (a->valor < x) d = 1 + depthOrd(a->dir, x);
        else e = 1 + depthOrd(a->esq, x);
    }

    return d + e;
}

//47

int maiorAB(ABin a) {
    if (!a) return 0;

    if (!a->dir) return a->valor;

    while (a->dir) {
        a = a->dir;
    }

    return a->valor;
}

//48
void removeMaiorA(ABin* a) {
    if (!(*a)) return;

    ABin prev = *a;
    while ((*a)->dir) {
        prev = *a;
        a = &((*a)->dir);
    }

    prev->dir = (*a)->esq;
    free(*a);
}

//49

int quantosMaiores(ABin a, int x) {
    if (!a) return 0;

    if (a->valor > x)
        return 1 + quantosMaiores(a->esq, x) + quantosMaiores(a->dir, x);
    else
        return quantosMaiores(a->dir, x);
}

//50

void listToBTree(LInt l, ABin* a) {
    if(!l) return;
    int i = 0;
    ABin new = malloc(sizeof(struct nodo));
    int meio = length(l) / 2 ;
    LInt prev = NULL;
    LInt atual = l;

    while(i<meio){
        prev = l;
        atual = atual->prox;
        i++;
    }

    new->valor = atual->valor;
    if(prev) prev->prox = NULL;
    
    if(l!=atual) listToBTree(l,&(new->esq)); //check if the head is not the same as the middle(atual)
    if(atual->prox) listToBTree(atual->prox,&(new->dir)); //check if right ain't empty
    
    (*a) = new;
}

//51 nao sei, versao da sofia

int deProcuraAux(ABin a, int x, int maior) {
    if(!a) return 1;
    if((maior && a->valor < x) || (!maior && a->valor > x)) return 0;
    return deProcuraAux(a->esq,x,maior) && deProcuraAux(a->dir,x,maior);
}

int deProcura (ABin a) {
    if(!a) return 1;
    int b = deProcuraAux(a->esq,a->valor, 0) && deProcura(a->esq);
    int c = deProcuraAux(a->dir,a->valor, 1) && deProcura(a->dir);
    return b && c;
}

ABin newNode(int value) {
    ABin new = (ABin)malloc(sizeof(struct nodo));
    new->valor = value;
    new->esq = NULL;
    new->dir = NULL;
    return new;
}

int main() {
    ABin root = newNode(10);
    root->esq = newNode(5);
    root->dir = newNode(15);
    root->esq->esq = newNode(3);
    root->esq->dir = newNode(7);
    root->dir->esq = newNode(12);
    root->dir->dir = newNode(17);

    int x = 10;
    int count = quantosMaiores(root, x);
    printf("Number of nodes greater than %d: %d\n", x, count);

    return 0;
}

