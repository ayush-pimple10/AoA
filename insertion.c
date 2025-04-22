
#include <stdio.h>

int main() {
    int A[] = {12, 11, 13, 5, 6};
    int n = 5;
    int i, temp, j;

    for (i = 1; i < n; i++) {
        temp = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > temp) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
    }

    for (i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}
