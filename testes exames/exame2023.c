#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// 1

int isFib(int x)
{
    if (x == 0)
        return 1;
    int a = 0, b = 1, c;
    while (b < x)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b == x ? 1 : 0;
}

// 2

typedef struct
{
    float teste, minis;
} Aluno;

int moda(Aluno turma[], int N)
{
    int notas[N];
    int frequencia[30] = {0};
    int i, maxFreq = 0, moda = -1;

    for (i = 0; i < N; i++)
    {
        notas[i] = 0.8 * turma[i].teste + 0.2 * turma[i].minis;
    }

    for (i = 0; i < N; i++)
    {
        frequencia[notas[i]]++;
    }

    for (i = 0; i < 30; i++)
    {
        if (frequencia[i] > maxFreq)
        {
            maxFreq = frequencia[i];
            moda = i;
        }
    }
    return moda;
}

// 4

int verifica(char frase[], int k)
{
    int count = 0;
    for (int i = 0; frase[i]; i++)
    {
        if (frase[i] != '\n' && frase[i] != ' ' && frase[i] != '\t')
            count++;
        else
        {
            if (count > 0 && count < k)
            {
                return 0;
            }
            count = 0;
        }
    }
    return 1;
}

int main(){
        // Adjusted example data to fit the 0-20 grading scale
        Aluno turma[] = {
            {20, 20}, // 20 grade
            {16, 18}, // 16.4 grade, approximated to 16
            {14, 12}, // 13.6 grade, approximated to 14
            {20, 20}, // 20 grade
            {16, 18}  // 16.4 grade, approximated to 16
        };
        int N = sizeof(turma) / sizeof(turma[0]);

        // Testing the moda function
        int result = moda(turma, N);
        printf("The most frequent grade is: %d\n", result);

        return 0;
}
