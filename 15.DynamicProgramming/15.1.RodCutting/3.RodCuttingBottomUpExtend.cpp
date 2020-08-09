#include <iostream>
using namespace std;

void RotCutting(int length, int prices[], int* choices) {
    int results[length + 1];
    results[0] = 0;
    choices[0] = 0;
    for (int i = 1; i <= length; i++) {
        results[i] = 0;
        for (int j = 1; j <= i; j++) {
            int val = prices[j - 1] + results[i - j];
            if (results[i] < val) {
                results[i] = val;
                choices[i] = j;
            }
        }
    }
}

void PrintSolution(int length, int prices[]) {
    int choices[length + 1];
    RotCutting(length, prices, choices);
    while (length != 0) {
        cout << choices[length] << " ";
        length -= choices[length];
    }
}

int main() {
    int p[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    for (int l = 1; l <= 10; l++) {
            cout << "Cut solution of length " << l << ": ";
            PrintSolution(l, p);
            cout << "\n";
    }
}
