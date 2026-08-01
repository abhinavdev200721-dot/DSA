#include <vector>
#include <algorithm>

class Solution {
private:
    int getMaxScoreDifference(int i, int j, const std::vector<int>& nums, std::vector<std::vector<int>>& memo) {
        if (i == j) {
            return nums[i];
        }
        
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        int pickLeft = nums[i] - getMaxScoreDifference(i + 1, j, nums, memo);
        int pickRight = nums[j] - getMaxScoreDifference(i, j - 1, nums, memo);
        
        return memo[i][j] = std::max(pickLeft, pickRight);
    }

public:
    bool predictTheWinner(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::vector<int>> memo(n, std::vector<int>(n, -1));
        return getMaxScoreDifference(0, n - 1, nums, memo) >= 0;
    }
};
