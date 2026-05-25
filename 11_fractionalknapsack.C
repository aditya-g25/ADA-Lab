#include <stdio.h>

struct Item {
    int weight, value;
    float ratio;
};

void sort(struct Item items[], int n) {
    struct Item temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (items[j].ratio < items[j + 1].ratio) {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter weights:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &items[i].weight);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &items[i].value);

    for (int i = 0; i < n; i++)
        items[i].ratio =
            (float)items[i].value / items[i].weight;

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    sort(items, n);

    float profit = 0.0;

    for (int i = 0; i < n; i++) {

        if (items[i].weight <= W) {
            profit += items[i].value;
            W -= items[i].weight;
        }

        else {
            profit += items[i].ratio * W;
            break;
        }
    }

    printf("Maximum profit = %.2f\n", profit);

    return 0;
}