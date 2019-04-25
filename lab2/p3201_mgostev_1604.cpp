#define MIN_VAL -2147483647
#define MAX_VAL 2147483647

#include <iostream>

using namespace std;

typedef struct {
    long count;
    long index;
} Sign;

Sign S[10000];
long k, min_c = MAX_VAL, max_c = MIN_VAL;
long signs_amount, first_sign, second_sign;

int main() {
    cin >> k;

    for (long i = 0; i < k; ++i) {
        cin >> S[i].count;
        S[i].index = i + 1;
        signs_amount += S[i].count;

        if (S[i].count >= max_c) {
            max_c = S[i].count;
            second_sign = i;
        }

        if (S[i].count < min_c && i != second_sign) {
            min_c = S[i].count;
            first_sign = i;
        }
    }

    while (signs_amount > 0) {
        if (S[second_sign].count > 0) {
            cout << S[second_sign].index << " ";
            S[second_sign].count--;
            signs_amount--;
        }

        if (S[first_sign].count > 0) {
            cout << S[first_sign].index << " ";
            S[first_sign].count--;
            signs_amount--;
        }

        min_c = MAX_VAL;
        max_c = MIN_VAL;
        for (long i = 0; i < k; ++i)
            if (S[i].count > 0) {
                if (S[i].count >= max_c) {
                    max_c = S[i].count;
                    second_sign = i;
                }

                if (S[i].count < min_c) {
                    min_c = S[i].count;
                    first_sign = i;
                }
            }
    }

    return 0;
}
