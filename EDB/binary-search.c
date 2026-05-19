#include <stdio.h>

// iterativa - O(log n)
int binary_search(int arr[], int n, int alvo) {
    int esq = 0, dir = n - 1;
    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2;
        if (arr[meio] == alvo) return meio;
        if (arr[meio] < alvo) esq = meio + 1;
        else dir = meio - 1;
    }
    return -1;
}

// recursiva - O(log n)
int binary_search_rec(int arr[], int esq, int dir, int alvo) {
    if (esq > dir) return -1;
    int meio = esq + (dir - esq) / 2;
    if (arr[meio] == alvo) return meio;
    if (arr[meio] < alvo) return binary_search_rec(arr, meio + 1, dir, alvo);
    return binary_search_rec(arr, esq, meio - 1, alvo);
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 44, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);

    int alvo = 23;
    int idx = binary_search(arr, n, alvo);
    printf("Busca iterativa por %d: indice %d\n", alvo, idx);

    alvo = 100;
    idx = binary_search_rec(arr, 0, n - 1, alvo);
    printf("Busca recursiva por %d: indice %d\n", alvo, idx);

    alvo = 56;
    idx = binary_search(arr, n, alvo);
    printf("Busca iterativa por %d: indice %d\n", alvo, idx);

    return 0;
}
