#include <stdio.h>

#define LEFT -1
#define RIGHT 1

typedef struct {
    int value;
    int dir;
} Element;

void printPermutation(Element a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i].value);
    printf("\n");
}

int getMobile(Element a[], int n) {
    int mobile = 0, mobileIndex = -1;

    for (int i = 0; i < n; i++) {

        if (a[i].dir == LEFT && i != 0 &&
            a[i].value > a[i - 1].value &&
            a[i].value > mobile) {

            mobile = a[i].value;
            mobileIndex = i;
        }

        if (a[i].dir == RIGHT && i != n - 1 &&
            a[i].value > a[i + 1].value &&
            a[i].value > mobile) {

            mobile = a[i].value;
            mobileIndex = i;
        }
    }

    return mobileIndex;
}

void johnsonTrotter(int n) {

    Element a[n];

    for (int i = 0; i < n; i++) {
        a[i].value = i + 1;
        a[i].dir = LEFT;
    }

    printPermutation(a, n);

    while (1) {

        int mobileIndex = getMobile(a, n);

        if (mobileIndex == -1)
            break;

        int swapIndex;

        if (a[mobileIndex].dir == LEFT)
            swapIndex = mobileIndex - 1;
        else
            swapIndex = mobileIndex + 1;

        Element temp = a[mobileIndex];
        a[mobileIndex] = a[swapIndex];
        a[swapIndex] = temp;

        mobileIndex = swapIndex;

        for (int i = 0; i < n; i++) {
            if (a[i].value > a[mobileIndex].value) {
                a[i].dir *= -1;
            }
        }

        printPermutation(a, n);
    }
}

int main() {

    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}