#include "common.h"

int max_set_bit_distance(int a)
{
    int i, max = -1, s = -1;

    for (i = 0; a; i++) {
        if (a & 1) {
            if (s > -1) {
                int d = i - s - 1;

                if (d > max) {
                    max = d;
                }
            }
            s = i;
        }
        a >>= 1;
    }

    return max;
}

int is_prime23(int q)
{
    static const int primes23[] = {
        2, 3, 5, 7, 11, 13, 17, 19, 23
    };
    int cnt = 9, idx, left = 0, right = 8;

    if (q > 23) {
        return -1;
    }

    while (left <= right) {
        idx = ((left + right + 1) >> 1);
        //printf("left idx right: %d - %d - %d\n", left, idx, right);

        if (q > primes23[idx]) {
            left = idx + 1;
        }
        else if (q < primes23[idx]) {
            right = idx - 1;
        }
        else {
            return 1;
        }
    }
    return 0;
}

int count_set_bits(int a)
{
    int cnt = 0;

    if (a == 0) {
        return 0;
    }
    else if ((a & (a - 1)) == 0) {
        return 1;
    }

    while (a) {
        if (a & 1) {
            cnt++;
        }
        a >>= 1;
    }

    return cnt;
}
