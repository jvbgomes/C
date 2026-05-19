#include <stdio.h>

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int trocou = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                trocou = 1;
            }
        }
        if (!trocou) break;
    }
}

void imprimir_vetor(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int arr[] = {90, 10, 50, 30, 20, 70, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Antes:  ");
    imprimir_vetor(arr, n);

    bubble_sort(arr, n);

    printf("Depois: ");
    imprimir_vetor(arr, n);

    return 0;
}
