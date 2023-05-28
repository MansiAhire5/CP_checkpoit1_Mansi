#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool isPossible(const vector<int>& arr, int n, int k, int maxSum) {
    int count = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxSum) {
            return false;
        }

        sum += arr[i];

        if (sum > maxSum) {
            count++;
            sum = arr[i];
        }
    }

    count++;

    return count <= k;
}

int divideArray(const vector<int>& arr, int n, int k) {
    int left = *max_element(arr.begin(), arr.end());
    int right = accumulate(arr.begin(), arr.end(), 0);
    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isPossible(arr, n, k, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxSum = divideArray(arr, n, k);
    cout << maxSum << endl;

    return 0;
}
