#define sqr(x) ((x) * (x))

#include <iostream>

using namespace std;

long long solve(int n, int k) {
    int m = n / k; // Average amount of mates per team
    int r = n % k; // Remainder

    return sqr(m + 1) * r * (r - 1) / 2 + sqr(m) * (k - r) * (k - r - 1) / 2 + (m + 1) * m * (k - r) * r;
}

int main() {
    size_t T;
    cin >> T;

    int k, n;
    for (size_t t = 0; t < T; ++t) {
        cin >> n >> k;
        cout << solve(n, k) << '\n';
    }

    return 0;
}
