#include <iostream>
#include <vector>

using namespace std;

class Gamers {
private:
    int N;
    int size;

    vector<vector<int>> *matrix;

    void add_figure(int x, int y) {
        int remainder_x = x % 2;
        int remainder_y = y % 2;

        if (remainder_x == 1 && remainder_y == 1) {
            (*matrix)[x - 1][y - 1] = (*matrix)[x - 1][y] = (*matrix)[x][y - 1] = N++;
        } else if (remainder_x == 0 && remainder_y == 0) {
            (*matrix)[x + 1][y + 1] = (*matrix)[x + 1][y] = (*matrix)[x][y + 1] = N++;
        } else if (remainder_x == 0 && remainder_y == 1) {
            (*matrix)[x + 1][y] = (*matrix)[x][y - 1] = (*matrix)[x + 1][y - 1] = N++;
        } else if (remainder_x == 1 && remainder_y == 0) {
            (*matrix)[x - 1][y] = (*matrix)[x][y + 1] = (*matrix)[x - 1][y + 1] = N++;
        }
    }

    void main_solve(int rows_start, int cols_start, int i, int j, int size) {
        if (size == 2) {
            add_figure(rows_start + i % 2, cols_start + j % 2);
            return;
        }

        int new_size = size / 2;

        if (i >= new_size && j >= new_size) {
            main_solve(rows_start + new_size, cols_start + new_size, i - new_size, j - new_size, new_size);

            (*matrix)[rows_start + new_size - 1][cols_start + new_size - 1] =
            (*matrix)[rows_start + new_size][cols_start + new_size - 1] =
            (*matrix)[rows_start + new_size - 1][cols_start + new_size] = N++;

            main_solve(rows_start, cols_start + new_size, new_size - 1, 0, new_size);
            main_solve(rows_start, cols_start, new_size - 1, new_size - 1, new_size);
            main_solve(rows_start + new_size, cols_start, 0, new_size - 1, new_size);

        } else if (i < new_size && j < new_size) {
            main_solve(rows_start, cols_start, i, j, new_size);

            (*matrix)[rows_start + new_size][cols_start + new_size] =
            (*matrix)[rows_start + new_size][cols_start + new_size - 1] =
            (*matrix)[rows_start + new_size - 1][cols_start + new_size] = N++;

            main_solve(rows_start + new_size, cols_start + new_size, 0, 0, new_size);
            main_solve(rows_start, cols_start + new_size, new_size - 1, 0, new_size);
            main_solve(rows_start + new_size, cols_start, 0, new_size - 1, new_size);

        } else if (i < new_size && j >= new_size) {
            main_solve(rows_start, cols_start + new_size, i, j - new_size, new_size);

            (*matrix)[rows_start + new_size][cols_start + new_size] =
            (*matrix)[rows_start + new_size][cols_start + new_size - 1] =
            (*matrix)[rows_start + new_size - 1][cols_start + new_size - 1] = N++;

            main_solve(rows_start, cols_start, new_size - 1, new_size - 1, new_size);
            main_solve(rows_start + new_size, cols_start + new_size, 0, 0, new_size);
            main_solve(rows_start + new_size, cols_start, 0, new_size - 1, new_size);

        } else {
            main_solve(rows_start + new_size, cols_start, i - new_size, j, new_size);

            (*matrix)[rows_start + new_size][cols_start + new_size] =
            (*matrix)[rows_start + new_size - 1][cols_start + new_size] =
            (*matrix)[rows_start + new_size - 1][cols_start + new_size - 1] = N++;

            main_solve(rows_start, cols_start, new_size - 1, new_size - 1, new_size);
            main_solve(rows_start + new_size, cols_start + new_size, 0, 0, new_size);
            main_solve(rows_start, cols_start + new_size, new_size - 1, 0, new_size);
        }
    }

public:
    Gamers(vector<vector<int>> *matrix, int size) {
        this->matrix = matrix;
        this->size = size;
        N = 1;
    }

    void solve(int i, int j) {
        main_solve(0, 0, i, j, size);
    }
};

int main() {
    unsigned int power = 0, x = 0, y = 0;
    cin >> power >> x >> y;

    unsigned int count = (1 << power);
    vector<vector<int>> matrix = vector<vector<int>>(count, vector<int>(count, 0));

    Gamers gamers(&matrix, count);
    gamers.solve(x - 1, y - 1);

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}
