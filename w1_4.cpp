#include <iostream>
#include <vector>
#include <algorithm>

int largest_sum_of_squares(std::vector<int>& nums) {
    int n = nums.size();
    int max_sum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x = nums[i];
            int y = nums[j];

            // Perform the operation
            nums[i] = x & y;
            nums[j] = x | y;

            // Calculate the sum of squares
            int sum_of_squares = 0;
            for (int k = 0; k < n; k++) {
                sum_of_squares += nums[k] * nums[k];
            }

            // Update max_sum if necessary
            max_sum = std::max(max_sum, sum_of_squares);

            // Revert the operation
            nums[i] = x;
            nums[j] = y;
        }
    }

    return max_sum;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    // Call the function
    int result = largest_sum_of_squares(nums);

    // Print the result
    std::cout << result << std::endl;

    return 0;
}
