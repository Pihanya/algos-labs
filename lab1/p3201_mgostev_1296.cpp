#include <iostream>
#include <vector>

using namespace std;

int main() {
    size_t N;
    cin >> N;

    vector<int> potentials = vector<int>(N);
    int sum = 0, result = 0, p;
    for(int i =0; i < N; ++i) {
        cin >> p;
        sum = max(0, sum + p);
        result = max(sum, result);
    }

    cout << result;

    return 0;
}