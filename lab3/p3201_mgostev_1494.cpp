#include <iostream>

using namespace std;

size_t N;
long x[100001], stack[100001];

int main() {
    cin >> N;
    for (size_t i = 0; i < N; ++i) {
        cin >> x[i];
    }

    bool flag = true;
    int pos = 0, pos2 = 0, sz = 0;

    while (flag && pos < N) {
        if (sz > 0 && stack[sz - 1] == x[pos]) {
            --sz;
            ++pos;
        } else if (pos2 < N) {
            stack[sz] = ++pos2;
            ++sz;
        } else {
            flag = false;
        }
    }

    if (flag) {
        cout << "Not a proof" << endl;
    } else {
        cout << "Cheater" << endl;
    }
    return 0;
}
