# define M_PI        3.14159265358979323846

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Angle {
    double angle;
    int number;

    friend bool operator>(const Angle &l, const Angle &r) {
        return l.angle > r.angle;
    }

    friend bool operator<(const Angle &l, const Angle &r) {
        return l.angle < r.angle;
    }

    friend bool operator==(const Angle &l, const Angle &r) {
        return l.angle == r.angle;
    }
};

int main() {
    int N;
    long long x0, y0;
    long long x, y;

    cin >> N;
    cin >> x0 >> y0;

    vector<Angle> angles(N - 1);
    for (int i = 0; i < N - 1; ++i) {
        cin >> x >> y;

        x -= x0;
        y -= y0;

        Angle a{};
        a.number = (i + 2);

        if (y >= 0) {
            a.angle = acos(((double) x) / sqrt(x * x + y * y));
        } else {
            a.angle = M_PI + acos(((-1) * (double) x) / sqrt(x * x + y * y));
        }

        angles[i] = a;
    }

    sort(angles.begin(), angles.end());

    for (int i = 0; i < angles.size(); ++i) {

        int points = 0;

        double left = angles[i].angle;

        double right = M_PI + angles[i].angle;
        if (right >= 2 * M_PI) right -= 2 * M_PI;

        if (left > right)swap(left, right);

        for (int j = 0; j < angles.size(); ++j) {
            if (j == i) {
                continue;
            }

            double angle = angles[j].angle;
            if (angle >= left && angle <= right) {
                ++points;
            }
        }

        if (points == angles.size() / 2) {
            cout << "1 " << angles[i].number << '\n';
            exit(0);
        }
    }
}