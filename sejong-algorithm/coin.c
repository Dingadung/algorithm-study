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
    int coins[] = {8, 3, 9, 5, 2}; // 동전의 단위 무게
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount = 10; // 거스름돈 액수, 무게 한도

    coinChange(coins, n, amount);
    return 0;
}
