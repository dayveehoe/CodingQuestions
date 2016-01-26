#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Make a psuedo "set" which is a really big array
int pseudo_set[1 << (31 - 5)];

// place a mark in set
inline void mark(int X) {
    int index = X >> 5;
    int bit = 1 << (X & 31);
    pseudo_set[index] |= bit;
}

// Check if mark is set
inline int check_mark(int X) {
    int index = X >> 5;
    int bit = 1 << (X & 31);
    return (pseudo_set[index] & bit);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, S, P, Q;
    cin >> N >> S >> P >> Q;

    int unique_count = 0;
    long ai, ai1;

    // a0
    ai1 = S % (1 << 31);
    mark(ai1);
    unique_count++;

    // Loop
    for (int i = 1 ; i < N ; i++) {
        ai = (ai1 * P + Q) & 0x7FFFFFFF;
        ai1 = ai;

        if (check_mark(ai) == 0) {
            mark(ai);
            unique_count++;
        }
    }

    cout << unique_count << endl;
    return 0;
}

