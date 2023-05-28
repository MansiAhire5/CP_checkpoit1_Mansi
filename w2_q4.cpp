class Solution {
public:
int countPairs(const std::vector<int>& nums, int target) {
    int count = 0;
    int left = 0;
    for (int right = 0; right < nums.size(); right++) {
        while (nums[right] - nums[left] > target)
            left++;
        count += right - left;
    }
    return count;
}

    int smallestDistancePair(vector<int>& nums, int k) {
          std::vector<int> sortedNums(nums);
    std::sort(sortedNums.begin(), sortedNums.end());

    int n = nums.size();
    int left = 0;
    int right = sortedNums[n - 1] - sortedNums[0];

    while (left < right) {
        int mid = left + (right - left) / 2;
        int pairsCount = countPairs(sortedNums, mid);
        if (pairsCount < k)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
    }
};
