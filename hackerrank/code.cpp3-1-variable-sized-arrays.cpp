#include <iostream>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    // Array of arrays
    int** arrays = new int*[N]();

    // Building sequences
    for (int i = 0 ; i < N ; i++) {
        int k;
        cin >> k;
        arrays[i] = new int[k]();

        int s;
        for (int j = 0 ; j < k ; j++) {
            cin >> s;
            arrays[i][j] = s;
        }
    }

    // Running Queries
    for (int i = 0 ; i < Q ; i++) {
        int a, b;
        cin >> a >> b;
        cout << arrays[a][b] << endl;
    }

    return 0;
}
