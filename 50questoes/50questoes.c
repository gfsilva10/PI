#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <math.h>

//1
int primeira () {
    int n, max = 0 ;
    while ( n!= 0) {
        scanf("%d" ,&n);
        (n > max) ? max = n : n ;
    }
    return max ;
}

//2
int segunda() {
    int n, sum = 0;
    float elems = 0;
    while(n!=0) {
        scanf("%d" ,&n);
        sum += n;
        elems ++;
    }
    return sum / elems;
}

//3
int terceira() {
    int n, sndmaior = 0, maior = 0;
    while(n!=0){
        scanf("%d",&n);
        if (n >= maior) {
            sndmaior = maior;
            maior = n;
        }
        else if (n > sndmaior && n < maior){
            n = sndmaior;
        }
        }
    return sndmaior;
}

//4
int bitsUm (unsigned int n){
    int contauns = 0;
    while (n > 0){
        if(n % 2 == 1) contauns++;
        n >>= 1;  // anda um bit para a direita     
    }
    return contauns;
}

//5
int trailingZ (unsigned int n){
    int contazeros = 0;
    while(n > 0){
        if(n % 2 == 0) contazeros++; 
        n >>= 1;
    }
    return contazeros;
}

//6
int qDig (unsigned int n) {
    return (n / 10 < 1) ?  1 :  1 + qDig(n / 10);
}

//7
char* my_strcat(char s1[], char s2[]) {
    int N1, N2;
    for(N1 = 0; s1[N1]; N1++);
    for(N2 = 0; s2[N2]; N2++) s1[N1 + N2] = s2[N2];
    s1[N1 + N2] = '\0';
    return s1;
}
//8
char *mystrcpy (char *dest, char source[]){
    int i;
    for (i = 0; source[i] != "\0"; i++){
        dest[i] = source[i];
    }
    dest[i] = "\0";
}
//9
int mystrcmp(char s1[], char s2[]){
    int i;
    for(i=0; s1[i] != '\0' && s2[i] != '\0'; i++){
        if(s1[i] != s2[i]) return s1[i] - s2[i];
    }
    return s1[i] - s2[i];
}
//10
char* mystrstr (char haystack[], char needle[]) {
    int Nh, Nn, found;
    for(Nh = 0; haystack[Nh]; Nh++) {
        found = 1;
        for(Nn = 0; needle[Nn]; Nn++)
            if(needle[Nn] != haystack[Nh + Nn])
                found = 0;
        if(found == 1) break;
    }
    if(found == 1) return haystack + Nh;
    return NULL;
}

//11
 void strrev (char s[]){
    int start = 0;
    int tamanho = strlen(s);
    int end = tamanho - 1;
    for(int i = 0; i < tamanho / 2; i++){
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
 }

//12
void tail(char* s, int N) {
    int i;
    for(i = N; s[i]; i++)
        s[i] = s[i+1];
}

void strnoV (char s[]) {
    int N = 0;
    while(s[N]) { // enquanto nao e car nulo
        (s[N] == 'A' || s[N] == 'E' || s[N] == 'I' || s[N] == 'O' || s[N] == 'U' || s[N] == 'a'
        || s[N] == 'e' || s[N] == 'i' || s[N] == 'o' || s[N] == 'u') ?
        tail(s, N) : N++;
    }
}

//13
void nprimeiros (char* s,int N){
    int i;
    for(i = N; s[i] ; i++){
        s[i] = s[strlen(s)-(strlen(s)-N)];
    }
}

void tail2(char* s) {
    int i;
    for(i = 0; s[i]; i++)
        s[i] = s[i+1];
}

int isSpace(char c) {
    return (c == ' ' || c == '\n' || c == '\t');
}

void truncWAux(char t[], int n, int wordLen) {
    if (*t == '\0') return;
    if (isSpace(*t)) truncWAux(t+1, n, 0);
    else {
        if (wordLen >= n) tail2(t);
        else t++;
        truncWAux(t, n, wordLen + 1);
    }
}

void truncW (char t[], int n) {
    truncWAux(t, n, 0);
}

//14
int freqAux(char ch, char s[]){
    int i = 0, freq = 0;
    while(s[i] != '\0'){
        if (s[i] == ch) freq++;
        i++;
    }
    return freq;                              
}


char charMaisFreq(char s[]) {
    if (s[0] == '\0') { 
        return 0;
    }
    char maisFrequente = s[0];
    int freqMax = 1; 
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        int freqAtual = freqAux(s[i], s);
        if (freqAtual > freqMax) {
            freqMax = freqAtual;
            maisFrequente = s[i];
        }
    }
    return maisFrequente;
}

//15
int iguaisConsecutivos (char s[]){
    int i, inarow= 1, mostinarow = 0;
    for(i = 0; s[i]; i++){
        if(s[i]=s[i+1]) inarow++;
    else{
         if(inarow > mostinarow) mostinarow = inarow;
    }
    }
    return mostinarow;
}

//16
int not_in_prev(char s[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        if(s[i] == s[n]) {
            return 0;
        }
    }
    return 1;
}

int difConsecutivos(char s[]) {
    int consec, difs = 0;
    size_t i, j;
    for(i = 0; s[i]; i++) {
        for(j = 0, consec = 0; s[i+j] && not_in_prev(s+i,j); j++, consec++);
        if (consec > difs) difs = consec;
    }
    return difs;
}

//17
int maiorPrefixo (char s1 [], char s2 []) {
    int i;
    for(i = 0; s1[i] == s2[i] && s1[i] != '\0'; i++);
    return i;
}

//18
int maiorSufixo(char s1[],char s2[]){
    int i, j, ans = -1;
    for(i = 0; s1[i]; i++);//length
    for(j = 0; s2[j]; j++);//length
    while(s1[i--] == s2[j--]) ans++;
    return ans;
}

//19
int sufPref(char s1[], char s2[]){
        int ans = 0, i, j = 0;
    for(i = 0; s1[i]; i++) {
        if(s1[i] == s2[j++]) ans++;
        else ans = j = 0;
    }
    return ans;
}

//20
int contaPal (char s[]){
    int i, palavra, contapalavra = 0;
    for ( i = 0; s[i] ; i++){
        if (s[i] == ' ' || s[i] == '\n'){
            (palavra) ? contapalavra++ : (palavra = 0);
        }
        else palavra = 1;
    }
    if(palavra) contapalavra ++;
    return contapalavra;
}

//21
int contaVogais (char s[]){
    int i, contador = 0;
    for (i = 0; s[i]; i++){
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i'
        || s[i] == 'o' || s[i] == 'u' || s[i] == 'A'
        || s[i] == 'E' || s[i] == 'I' || s[i] == 'O'
        || s[i] == 'U') contador++;
    }
    return contador;
}

//22
int contida (char a[], char b[]) {
    int i, j;
    int acc = 1, contemLetra;
    for(i = 0; a[i] && acc; i++) {
        contemLetra = 0;
        for(j = 0; b[j] && !contemLetra; j++)
            if (b[j] == a[i])
                contemLetra = 1;
        acc = contemLetra;
    }
    return acc;
}

//23
int palindrome (char s[]){
    int start = 0;
    int end = strlen(s) - 1;
    for (int i = 0; i < strlen(s)/2; i++)
    {
        if(s[start] != s[end]) return 0;
        start++;
        end--;
    }
    return 1;
}

//24
int remRep (char x[]){
    int i, j;
    for(i = 0; x[i]; i++){
        if(x[i] == x[i+1]){
            for(j = i; x[j]; j++){
                x[j] = x[j+1];
            }
            i--; // decrement i to check for more than two repeated characters
        }
    }
    return strlen(x);
}

//25
int limpaEspacos (char t[]){
    int i, j;
    for(i = 0; t[i]; i++){
        if(t[i] == ' ' && t[i+1] == ' '){
            for(j = i; t[j]; j++){
                t[j] = t[j+1];
            }
            i--; // decrement i to check for more than two repeated characters
        }
    }
    return strlen(t);
}

//26
void insere (int v[], int N, int x){
    int i, j, inserted = 0;
    for(i = 0; v[i]; i++){
        if(x < v[i]){
            for(j = N; j > i; j--) {
                v[j] = v[j - 1];
            }
            v[i] = x;
            inserted = 1;
        }
    }
    if(!inserted) v[N] = x;
}

//27
void merge (int r [], int a[], int b[], int na, int nb){
    int i = 0, j = 0;
    while (i + j < na + nb)
    {
        if(j == nb || a[i] < b[j]){
            r[i+j] = a[i];
            i++;
        }
        else{
            r[i+j] = b[j];
            j++;
        }
    }
}


void recursive_merge(int r[], int a[], int b[], int na, int nb) {
    if(na > 0) {
        if(nb > 0) {
            if(*a > *b) {
                *r = *b;
                recursive_merge(r+1, a, b+1, na, nb-1);
            }
            else {
                *r = *a;
                recursive_merge(r+1, a+1, b, na-1, nb);
            }
        }
        else {
            *r = *a;
            recursive_merge(r+1, a+1, b, na-1, nb);
        }
    }
    else if(nb > 0) {
        *r = *b;
        recursive_merge(r+1, a, b+1, na, nb-1);
    }
}

//28
int crescente (int a[], int i, int j){
    int x;
    for( x = i; x < j; x++){
        if(a[i] > a[i+1]){
            return 0;
        } 
    }
    return 1;
}

//29
int retiraNeg (int v[],int N){
    int i, j;
    for(i = 0, j = 0; i < N; i++) {
        if(v[i] >= 0) {
            v[j] = v[i];
            j++;
        }
    }
    return j;
}

//30
int contaRepetidos(int numero, int v[], int N){
    int i=0, count=0;

    while(i<N){
        if(numero == v[i])
            count++;
        i++;
    }
    return count;
}


int menosFreq (int v[], int N){
    int i=0, resultado = v[i];

    int menor = contaRepetidos(v[i], v, N);
    
    while(i<N){
        int x = contaRepetidos(v[i], v, N);
        if(x<menor){
            menor = x;
            resultado = v[i];
        }
        i+=x; //salta para o proximo grupo de numeros
    }
    return resultado;
}

//31
int maisFreq (int v[], int N){
    int i=0, resultado = v[i];

    int maior = contaRepetidos(v[i], v, N);
    
    while(i<N){
        int x = contaRepetidos(v[i], v, N);
        if(x>maior){
            maior = x;
            resultado = v[i];
        }
        i+=x; //salta para o proximo grupo de numeros
    }
    return resultado;
}

//32
int maxCresc(int v[], int N){
    int i, maior = 1, r = 1;

    for(i=0; i<N; i++){
        if(v[i+1] >= v[i])
            r++;
        else {
            if(r>maior)
                maior = r;
            r=1;
        }
    }
    return maior;
}

//33
int contarepetidos(int n, int s[], int N){
    int i, conta = 0;
    for(i = 0; i < N; i++){
        if(n == s[i]) conta++;
    }
    return conta;

}

void delete(int n, int s[], int N) {
    int i;
    for (i = 0; i < N - 1; i++) {
        if (n == s[i]) {
            s[i] = s[i + 1];
        }
    }
}

int elimRep (int v[], int n){
    int i, elementosUnicos = 0;

    for (i = 0; i < n; i++) {
        int frequencia = contaRepetidos(v[i], v, n);
        if (frequencia > 1) {
            delete(v[i], v, n);
            n--;  // Decrementa o tamanho do vetor após a remoção
            i--;  // Volta uma posição para reavaliar o elemento movido
        } else {
            elementosUnicos++;
        }
    }

    return elementosUnicos;
}

//34
int elimRepOrd (int v[], int n){
    int i=0, j;

    while(i<n-1){
        if(v[i] == v[i+1]){
            for(j=i; j<n; j++)
                v[j] = v[j+1];
            n--;
        } else
            i++;
    }
    return n;
}

//35
int pertence(int n, int N, int v[]){
    int i, belongs = 0;
    for(i = 0; i < N; i++){
        if(n == v[i]) belongs= 1;
    }
    return belongs;
}

int comunsOrd(int a[], int na, int b[], int nb) {
    int i, conta = 0;

    for (i = 0; i < na; i++) {
        if (pertence(a[i], nb, b) && pertence(a[i], na, a)) {
            conta++;
        }
    }

    return conta;
}

//36 a anterior funciona aqui tmb

//37
int minInd (int v[], int n){
   int i, indice = 0;
   for(i = 0; i < n; i++){
    if(v[i] <= v[indice]) indice = i;
   } 
   return indice;
}

//38
void somasAc (int v[], int Ac [], int N) {
    for(int i = 0; i < N; i++) {
        Ac[i] = 0;
        for(int j = 0; j <= i; j++) {
            Ac[i] += v[j];
        }
    }
}

//39
int triSup (int N, float m [N][N]) {
    int i, j, x = 1;
    for(i = 0; i < N && x; i++) {
        for(j = 0; j < i && x; j++) {
            if(m[i][j]) x = 0;
        }
    }
    return x;
}

//40
void transposta(int N, float m[N][N]){
    int i, j;
    float m_aux[N][N];


    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            m_aux[j][i] = m[i][j];
        }
    }

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            m[i][j] = m_aux[i][j];
        }
    }    
}

// usando a técnica do swap
void transposta2 (int N, float m[N][N]) {
    int i, j;
    float temp;
    for(i = 0; i < N; i++) {
        for(j = 0; j < i; j++) {
            temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }
}

//41
void addTo (int N, int M, int a [N][M], int b[N][M]){
    int i, j;
    for(i = 0; i < N; j++){
        for(j = 0; j < M; j++){
            a[i][j] += b[i][j];
        }
    }
}

//42
int unionSet (int N, int v1[N], int v2[N], int r[N]){
    int i, count = 0;
    for(i = 0; i < N; i++){
        r[i] = v1[i] || v2[i] ;
        count += r[i];
    }
    return count;
}

//43
int intersectSet (int N, int v1[N], int v2[N], int r[N]){
    int i, count = 0;
    for(i = 0; i < N; i++){
        r[i] = v1[i] && v2[i];
        if(r[i]) count += r[i]; //nao precisa do if pois ou é 0 ou 1 como na anterior
    }
    return count;
}

//44
int min(int a, int b){
    return (a < b) ? a : b;
}

int intersectMSet (int N, int v1[N], int v2[N], int r[N]){
    int i, count = 0;
    for(i = 0; i < N; i++){
        r[i] = min(v1[i],v2[i]); //nao percebo pq
        count += r[i];
    }
    return count;
}

//45
int max(int a, int b){
    return (a > b) ? a : b;
}

int unionMSet (int N, int v1[N], int v2[N], int r[N]){
    int i, count = 0;
    for(i = 0; i < N; i++){
        r[i] = max(v1[i],v2[i]); //nao percebo pq
        count += r[i];
    }
    return count;
}

//46
int cardinalMSet (int N, int v[N]){
    int i, count = 0;
    for(i = 0; i < N; i++){
        count += v[i];
    }
    return count;
}

//47
typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
int x, y;
} Posicao;

Posicao posFinal (Posicao inicial, Movimento mov[], int N){
    int i;
    for(i = 0; i < N; i++){
        switch (mov[i])
        {
        case Norte: inicial.y++;
            break;
        case Sul: inicial.y--;
            break;
        case Oeste: inicial.x--;
            break;
        case Este: inicial.x++;
            break;
        }
    }
    return inicial;
}

//48
int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
    int i, r = 0;
    for(i = 0; i < N &&( inicial.x != final.x || inicial.y != final.y); i++){
        if(inicial.x < final.x){
            mov[i] = Oeste;
            inicial.x--;
            r++;
        } else if(inicial.x > final.x){
            mov[i] = Este;
            inicial.x++;
            r++;
        } else if(inicial.y > final.y){
            mov[i] = Norte;
            inicial.y++;
            r++;
        } else if(inicial.y < final.y){
            mov[i] = Sul;
            inicial.y--;
            r++;
        }
    }
    if(inicial.x != final.x || inicial.y != final.y) r = -1;
    return r;
}

//49
int distancia(int x1, int x2, int y1, int y2){
    int distance;
    distance = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    return distance;
}

int maisCentral (Posicao pos[], int N){
    int i;
    int mindistancia = distancia(pos[0].x, 0, pos[0].y, 0);
    int indicecentral = 0;

    for(i = 1; i < N; i++){ //começa em 1 pois a 0 e a mindistancia
        int distancia0 = distancia(pos[i].x,0,pos[i].y,0);
        if(distancia0 < mindistancia){
            mindistancia = distancia0;
            indicecentral = i;
        }
    }
    return indicecentral;
}

//50
int vizinhos (Posicao p, Posicao pos[], int N){
    int i, count = 0;
    for(i = 0; i < N; i++){
        if(distancia(pos[i].x,p.x,pos[i].y,p.y) == 1){
            count++;
        }
    }
    return count;
}

//vou chumbar

int main(){
    int n;
    printf("que nota achas que vais ter\n");
    scanf("%d",&n);
    printf("sonha sonha, vais chumbar\n");
    return 0;
}