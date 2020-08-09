#include <iostream>
using namespace std;

int RodCuttingAux(int length, int prices[], int memo[]) {
    if (length == 0) {
        return 0;
    } else if (memo[length - 1] != 0) {
        return memo[length - 1];
    } else if (length == 1) {
        memo[0] = prices[0];
        return memo[0];
    }
    for (int i = 0; i < length; i++) {
        int val = prices[i] + RodCuttingAux(length - i - 1, prices, memo);
        if (val > memo[length - 1]) {
            memo[length - 1] = val;
        }
    }
    return memo[length - 1];
}

int RodCuttiing(int length, int prices[]) {
    int memo[length];
    for (int i = 0; i < length; i++) {
        memo[i] = 0;
    }
    return RodCuttingAux(length, prices, memo);
}

int main() {
    int p[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    for (int l = 1; l <= 10; l++) {
            cout << "Max value of length " << l << ": " << RodCuttiing(l, p) << "\n";
    }
}
