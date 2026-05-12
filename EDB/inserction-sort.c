#include <stdio.h>

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
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
    int arr[] = {5, 4, 3, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Antes:  ");
    imprimir_vetor(arr, n);

    insertion_sort(arr, n);

    printf("Depois: ");
    imprimir_vetor(arr, n);

    return 0;
}