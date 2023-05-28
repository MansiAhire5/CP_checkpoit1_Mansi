#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> machines(n);
    for (int i = 0; i < n; ++i) {
        cin >> machines[i];
    }

    // Sort the machines in ascending order of their production time
    sort(machines.begin(), machines.end());

    // Binary search to find the minimum time needed
    long long st = 1, en = static_cast<long long>(machines[n - 1]) * t;
    long long ans = en;

    while (st<= en) {
        long long mid = (st + en) / 2;
        long long products = 0;

        // Calculate the total number of products that can be produced within 'mid' time
        for (int i = 0; i < n; ++i) {
            products += mid / machines[i];

            // If the total number of products exceeds 't', reduce the upper bound
            if (products >= t) {
                ans = min(ans, mid);
                en = mid - 1;
                break;
            }
        }

        // If the total number of products is less than 't', increase the lower bound
        if (products < t) {
            st = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
