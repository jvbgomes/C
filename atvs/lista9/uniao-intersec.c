#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *v;
    int n;
} Conjunto;

static int contains(const Conjunto *c, int x){
    for(int i=0;i<c->n;i++) if(c->v[i]==x) return 1;
    return 0;
}

Conjunto cria_conjunto_da_entrada(void){
    int m;
    if(scanf("%d", &m)!=1){ Conjunto z = {NULL,0}; return z; }
    if (m <= 0) { Conjunto z = {NULL,0}; /* consume possible following numbers? none */ return z; }
    int *tmp = malloc(m * sizeof(int));
    if (!tmp) { Conjunto z = {NULL,0}; return z; }
    int cnt = 0;
    for(int i=0;i<m;i++){
        int x;
        if(scanf("%d", &x)!=1) break;
        int ok = 1;
        for(int j=0;j<cnt;j++) if(tmp[j]==x){ ok = 0; break; }
        if(ok) tmp[cnt++] = x;
    }
    if(cnt==0){
        free(tmp);
        Conjunto z = {NULL,0};
        return z;
    }
    int *arr = malloc(cnt * sizeof(int));
    if (!arr) { free(tmp); Conjunto z={NULL,0}; return z; }
    for(int i=0;i<cnt;i++) arr[i]=tmp[i];
    free(tmp);
    Conjunto r = {arr, cnt};
    return r;
}

Conjunto uniao(const Conjunto *A, const Conjunto *B){
    if((A->n==0) && (B->n==0)){ Conjunto z={NULL,0}; return z; }
    int cap = A->n + B->n;
    int *arr = malloc((cap>0?cap:1) * sizeof(int));
    if (!arr) { Conjunto z={NULL,0}; return z; }
    int k = 0;
    for(int i=0;i<A->n;i++) arr[k++] = A->v[i];
    for(int i=0;i<B->n;i++){
        int x = B->v[i], seen = 0;
        for(int j=0;j<k;j++) if(arr[j]==x){ seen = 1; break; }
        if(!seen) arr[k++] = x;
    }
    int *out = NULL;
    if (k > 0) {
        out = malloc(k * sizeof(int));
        if (!out) { free(arr); Conjunto z={NULL,0}; return z; }
        for(int i=0;i<k;i++) out[i]=arr[i];
    }
    free(arr);
    Conjunto r = { out, k };
    return r;
}

Conjunto intersecao(const Conjunto *A, const Conjunto *B){
    if(A->n==0 || B->n==0){ Conjunto z={NULL,0}; return z; }
    int *arr = malloc((A->n<B->n?A->n:B->n) * sizeof(int));
    if (!arr) { Conjunto z={NULL,0}; return z; }
    int k = 0;
    for(int i=0;i<B->n;i++){
        int x = B->v[i];
        if(contains(A,x)){
            int dup = 0;
            for(int j=0;j<k;j++) if(arr[j]==x){ dup = 1; break; }
            if(!dup) arr[k++] = x;
        }
    }
    int *out = NULL;
    if (k > 0) {
        out = malloc(k * sizeof(int));
        if (!out) { free(arr); Conjunto z={NULL,0}; return z; }
        for(int i=0;i<k;i++) out[i]=arr[i];
    }
    free(arr);
    Conjunto r = { out, k };
    return r;
}

void libera(Conjunto *c){
    if(c->v) free(c->v);
    c->v = NULL; c->n = 0;
}

void imprime_conjunto(const char *titulo, const Conjunto *c){
    if (c->n == 0) {
        printf("%s == {vazio}\n", titulo);
        return;
    }
    printf("%s == {", titulo);
    for(int i=0;i<c->n;i++){
        if(i) printf(" ");
        printf("%d", c->v[i]);
    }
    printf("}\n");
}

int main(void){
    Conjunto A = cria_conjunto_da_entrada();
    Conjunto B = cria_conjunto_da_entrada();
    Conjunto U = uniao(&A, &B);
    Conjunto I = intersecao(&A, &B);
    imprime_conjunto("A união B", &U);
    imprime_conjunto("A interseção B", &I);
    libera(&A); libera(&B); libera(&U); libera(&I);
    return 0;
}