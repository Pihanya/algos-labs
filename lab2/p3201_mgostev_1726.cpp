#include <iostream>

using namespace std;

int cmp(const void *x1, const void *x2) { return (*(long *) x1 - *(long *) x2); }

long long x[100000], y[100000];

int main() {
    long long n;
    cin >> n;

    for (long i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    qsort(x, n, sizeof(long long), cmp);
    qsort(y, n, sizeof(long long), cmp);

    long long sum_x = 0, sum_y = 0;
    for (long i = 1; i < n; ++i) {
        sum_x += (x[i] - x[i - 1]) * i * (n - i) * 2;
        sum_y += (y[i] - y[i - 1]) * i * (n - i) * 2;
    }

    cout << (sum_x + sum_y) / (n * (n - 1)) << '\n';
    return 0;
}

