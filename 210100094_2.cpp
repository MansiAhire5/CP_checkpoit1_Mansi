#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int k = 1; k <= n; k++) {
        long long num_ways = (long long)k * k * (k * k - 1) / 2 - 4 * (k - 1) * (k - 2);
        cout << num_ways << " ";}
    return 0;
}
