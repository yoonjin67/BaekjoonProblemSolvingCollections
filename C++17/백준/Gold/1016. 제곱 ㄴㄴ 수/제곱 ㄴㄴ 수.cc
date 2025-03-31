#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main() {
    long long min, max;
    cin >> min >> max;

    vector<bool> v(max - min + 1, true);
    long long square_max = sqrt(max);

    for (long long i = 2; i <= square_max; i++) {
        long long iter_max = i * i;

        long long start = (min + iter_max - 1) / iter_max;
        for (long long j = start; iter_max * j <= max; j++) {
            long long n = iter_max * j;
            if (n >= min && n <= max) {
                v[n - min] = false;
            }
        }
    }

    int res = 0;
    for (auto c : v) {
        if (c) res++;
    }

    cout << res << endl;
    return 0;
}
