#include <iostream>
#include <vector>

using namespace std;

int find_max_potential(const vector<int> *potentials, size_t N);

int main() {
    size_t N;
    cin >> N;

    vector<int> potentials = vector<int>(N);
    for (int i = 0; i < N; cin >> potentials[i], ++i);

    cout << find_max_potential(&potentials, N);

    return 0;
}

int find_max_potential(const vector<int> *potentials, size_t N) {
    int sum = 0, result = 0;
    for (int i = 0; i < N; ++i) {
        sum = max(0, sum + (*potentials)[i]);
        result = max(sum, result);
    }

    return result;
}