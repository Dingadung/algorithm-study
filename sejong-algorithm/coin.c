#include <stdio.h>

void coinChange(int coins[], int n, int amount) {
    int coinCount[n];
    for (int i = 0; i < n; i++) {
        coinCount[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (amount >= coins[i]) {
            coinCount[i] = amount / coins[i];
            amount = amount % coins[i];
        }
    }

    printf("Coin Change Solution:\n");
    for (int i = 0; i < n; i++) {
        if (coinCount[i] != 0) {
            printf("%d coin(s) of %d\n", coinCount[i], coins[i]);
        }
    }
}

int main() {
    int coins[] = {25, 10, 5, 1}; // 동전의 단위
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount = 68; // 거스름돈 액수

    coinChange(coins, n, amount);
    return 0;
}
