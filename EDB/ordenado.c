#include <stdio.h>
#include <stdlib.h>

// quadratic time complexity --> O(n) * O(n) = O(n^2)
bool ordenado (int *v, int n) {
    for (int ii = 0; ii < n; ii++) {
        for (int jj = 0; jj < n; jj++) {
            if (ii >= jj && v[ii] < v[jj]) {
                return false;
            }
        }
    }
    return true;
}

// linear time complexity --> 0(n) * O(1) = O(n)
bool ordenado2 (int *v, int n) {
    for (int ii = 0; ii < n - 1; ii++) {
        if (v[ii] > v[ii + 1]) {
            return false;
        }
    }
    return true;
}

// recursive version of the linear time complexity algorithm
bool ordenado3 (int *v, int n) {
    if (n <= 1) {
        return true;
    }
    if (v[0] > v[1]) {
        return false;
    }
    return ordenado3(v+1, n-1);
}

int main () {
    int n;
    scanf("%d", &n);
    int *v = (int *) malloc(n * sizeof(int));
    for (int ii = 0; ii < n; ii++) {
        scanf("%d", &v[ii]);
    }
    if (ordenado(v, n)) {
        printf("SIM\n");
    } else {
        printf("NAO\n");
    }
    free(v);
    return 0;
}