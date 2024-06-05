#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int perfeito2(int x) {  // bue ineficiente porque sou limitado
    int divisores[x];
    int i, count = 0;
    int soma = 0;
    for (i = 1; i < x; i++) {
        if (x % i == 0) {
            divisores[count] = i;
            count++;
        }
    }
    for (int j = 0; j < count; j++) {
        soma += divisores[j];
    }
    if (x == soma) return 1;
    return 0;
}

int perfeito(int x) {
    int i;
    int soma = 0;
    for (i = 1; i < x; i++) {
        if (x % i == 0) soma += i;
    }
    return (x == soma) ? 1 : 0;
}

//2

typedef struct {
    int x, y;
} Ponto;

void swapPonto(Ponto pos[], int i, int j) {
    Ponto temp = pos[i];
    pos[i] = pos[j];
    pos[j] = temp;
}

void ordena(Ponto pos[], int N) {
    double distancia[N];
    for (int i = 0; i < N; i++) {
        distancia[i] = sqrt(pos[i].x * pos[i].x + pos[i].y * pos[i].y);
    }
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N - i - 1; k++) {
            if (distancia[k] > distancia[k + 1]) swapPonto(pos, k, k + 1);
        }
    }
}

//3

typedef struct ABin_nodo {
    int valor;
    struct ABin_nodo* esq, * dir;
} *ABin;

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

//4

int contachar(char s[]) {
    int count = 0;
    for (int i = 0; s[i]; i++) {
        count++;
    }
    return count;
}

int elem(char x, char s[]) {
    for (int i = 0; s[i]; i++) {
        if (s[i] == x) return 1;
    }
    return 0;
}


int wordle(char secreta[], char tentativa[]) {
    int count = 0;
    for (int i = 0; secreta[i] && tentativa[i]; i++) {
        if (secreta[i] == tentativa[i]) {
            tentativa[i] = toupper(tentativa[i]);
            count++;
        }
    }
    for (int j = 0; tentativa[j]; j++) {
        if (!isupper(tentativa[j]) && !elem(tentativa[j], secreta)) {
            tentativa[j] = '*';
        }
    }
    return count;
}


int main() {
    /*
    Ponto pos[] = {{3,3},{2,1},{-1,0}};
    int N = sizeof(pos) / sizeof(pos[0]);

    ordena(pos, N);

    for(int i = 0; i < N; i++) {
        printf("{%d, %d},", pos[i].x, pos[i].y);
    }

    return 0;
    */
    char secreta[] = "laranja";
    char tentativa[] = "cerejas";

    int result = wordle(secreta, tentativa);

    printf("The number of correct characters is %d\n", result);
    printf("The modified attempt is %s\n", tentativa);

    return 0;
}

