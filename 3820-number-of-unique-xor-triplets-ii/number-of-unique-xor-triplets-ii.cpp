class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int mx = (*max_element(nums.begin(), nums.end())) << 1;

        vector<bool> pairXor(mx + 1, false);
        vector<bool> ans(mx + 1, false);
        for (int a : nums) {
            for (int b : nums) {
                pairXor[a ^ b] = true;
            }
        }
        for (int x = 0; x <= mx; x++) {
            if (!pairXor[x]) continue;
            for (int c : nums) {
                ans[x ^ c] = true;
            }
        }

        int cnt = 0;
        for (bool x : ans)
            if (x) cnt++;

        return cnt;
    }
};