#include <iostream>
using namespace std;

void print_array(long long n, long long k, long long b, long long s) {
    long long max_value = (s + n - 1) / n; // Round up s/n to nearest integer
    if (max_value * k < b) {
        cout << -1 << endl; // No array satisfying the conditions
        return;
    }

    long long remaining = n - b;
    for (long long i = 0; i < remaining; i++) {
        cout << max_value << " ";
    }

    long long remaining_sum = s - (max_value * remaining);
    long long quotient = remaining_sum / b;
    long long remainder = remaining_sum % b;

    for (long long i = 0; i < b; i++) {
        cout << quotient + (i < remainder ? 1 : 0) << " ";
    }

    cout << endl;
}

int main() {
    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        long long n, k, b;
        long long s;
        cin >> n >> k >> b >> s;

        print_array(n, k, b, s);
    }

    return 0;
}
