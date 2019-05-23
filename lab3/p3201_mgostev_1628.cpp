#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>

using namespace std;

long N, M, K, ans;

pair<int, int> cell[180000];
set<pair<int, int>> S;

bool compare_use_first(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

bool compare_use_second(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

int main() {
    cin >> N >> M >> K;
    for (size_t i = 0, x, y; i < K; ++i) {
        cin >> x >> y;
        cell[i] = make_pair(x, y);
    }

    // Добавление границ матрицы
    for (size_t i = 1; i <= M; ++i) {
        cell[K++] = make_pair(0, i);
        cell[K++] = make_pair(N + 1, i);
    }
    for (size_t i = 1; i <= N; ++i) {
        cell[K++] = make_pair(i, 0);
        cell[K++] = make_pair(i, M + 1);
    }

    sort(cell, cell + K, compare_use_first);
    for (size_t i = 0; i + 1 < K; ++i) {
        int diff = cell[i + 1].second - cell[i].second;

        if (cell[i].first == cell[i + 1].first && diff >= 2) {
            if (diff == 2) S.insert(make_pair(cell[i].first, cell[i].second + 1));
            else ++ans;
        }

    }

    sort(cell, cell + K, compare_use_second);
    for (size_t i = 0; i + 1 < K; ++i) {
        int diff = cell[i + 1].first - cell[i].first;

        if (cell[i].second == cell[i + 1].second && diff >= 2) {

            if (diff == 2) {

                if (S.find(make_pair(cell[i].first + 1, cell[i].second)) != S.end()) {
                    ++ans;
                }

            } else {
                ++ans;
            }

        }

    }

    cout << ans << '\n';
    return 0;
}