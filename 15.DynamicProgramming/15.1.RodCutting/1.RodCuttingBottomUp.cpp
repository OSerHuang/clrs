#include <iostream>
using namespace std;

int RotCutting(int length, int prices[]) {
    int results[length + 1];
    results[0] = 0;
    for (int i = 1; i <= length; i++) {
        results[i] = 0;
        for (int j = 1; j <= i; j++) {
            int val = prices[j - 1] + results[i - j];
            if (results[i] < val) {
                results[i] = val;
            }
        }
    }
    return results[length];
}

int main() {
    int p[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    for (int l = 1; l <= 10; l++) {
            cout << "Max value of length " << l << ": " << RodCuttiing(l, p) << "\n";
    }
}
