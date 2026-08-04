class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> result;
        for (size_t i = 0; i < nums.size() - 1; ++i) {
            for (int v = nums[i] + 1; v < nums[i + 1]; ++v) {
                result.push_back(v);
            }
        }
        return result;
    }
};
