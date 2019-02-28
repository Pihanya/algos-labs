
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int split_into_heaps(const vector<int> *weights, int i, int first_heap, int second_heap);

int main() {
    size_t n;
    cin >> n;

    vector<int> weights = vector<int>(n);
    for (size_t i = 0; i < n; cin >> weights[i], ++i);

    cout << split_into_heaps(&weights, 0, 0, 0);;
}

int split_into_heaps(const vector<int> *weights, int i, int first_heap, int second_heap) {
    if (i == weights->size()) {
        return abs(first_heap - second_heap);
    } else {
        return min(split_into_heaps(weights, i + 1, first_heap + (*weights)[i], second_heap),
                   split_into_heaps(weights, i + 1, first_heap, second_heap + (*weights)[i]));
    }
}