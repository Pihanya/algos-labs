#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, C;

int main() {
    cin >> N;

    vector<bool> tmp(N, false);
    vector<vector<bool>> graph(N, tmp);

    for (size_t i = 0; i < N; ++i) {
        while (cin >> C && C) {
            --C;
            graph[i][C] = true;
            graph[C][i] = true;
        }
    }

    queue<int> q;
    q.push(0);

    vector<int> color(N, -1);
    color[0] = 0;

    bool flag = true;
    while (!q.empty() && flag) {
        int node = q.front();
        q.pop();

        for (size_t i = 0; i < N; ++i) {

            if (color[i] == color[node] && graph[node][i]) {
                flag = false;
                break;
            }

            if (color[i] == -1 && graph[node][i]) {
                color[i] = (color[node] + 1) % 2; // Производим инвертирование цвета
                q.push(i); // Кладем номер элемента в очередь для рассмотрения
            }

        }
    }

    if (flag) {
        for (int i = 0; i < N; ++i) {
            cout << color[i];
        }
    } else {
        cout << -1;
    }
    return 0;
}