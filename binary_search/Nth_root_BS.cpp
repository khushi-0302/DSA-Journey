#include <iostream>
using namespace std;

int NthRoot(int n, int m) {
    int low = 1, high = m;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long prod = 1;   // har iteration reset

        for (int i = 1; i <= n; i++) {
            prod *= mid;

            if (prod > m) {
                break;
            }
        }

        if (prod == m) {
            return mid;
        }
        else if (prod > m) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return -1;
}

int main() {
    int n, m;

    cout << "Enter n and m: ";
    cin >> n >> m;

    int ans = NthRoot(n, m);
    cout << ans << endl;

    return 0;
}