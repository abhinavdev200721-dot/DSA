class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        // dp[i] stores the length of the longest suffix of word2 
        // that is a subsequence of word1[i...]
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1];
            if (dp[i + 1] < m && word1[i] == word2[m - 1 - dp[i + 1]]) {
                dp[i] = dp[i + 1] + 1;
            }
        }
        
        vector<int> ans;
        int j = 0;
        bool changed = false;
        
        for (int i = 0; i < n && j < m; i++) {
            if (word1[i] == word2[j]) {
                if (changed && dp[i + 1] < m - 1 - j) {
                    continue;
                }
                ans.push_back(i);
                j++;
            } else {
                if (!changed && dp[i + 1] >= m - 1 - j) {
                    ans.push_back(i);
                    j++;
                    changed = true;
                }
            }
        }
        
        return ans.size() == m ? ans : vector<int>();
    }
};






// class Solution {
// public:
//     vector<int> validSequence(string word1, string word2) {
//         int n = word1.length();
//         int m = word2.length();
        
//         vector<int> dp(n + 1, 0);
//         for (int i = n - 1; i >= 0; i--) {
//             dp[i] = dp[i + 1];
//             if (dp[i + 1] < m && word1[i] == word2[m - 1 - dp[i + 1]]) {
//                 dp[i] = dp[i + 1] + 1;
//             }
//         }
        
//         vector<int> ans;
//         int j = 0;
//         bool changed = false;
        
//         for (int i = 0; i < n; i++) {
//             if (word1[i] == word2[j]) {
//                 if (changed && dp[i + 1] < m - 1 - j) continue;
//                 if (!changed && dp[i + 1] < m - 2 - j) continue;
//                 ans.push_back(i);
//                 j++;
//             } else {
//                 if (changed) continue;
//                 if (dp[i + 1] < m - 1 - j) continue;
//                 ans.push_back(i);
//                 j++;
//                 changed = true;
//             }
//             if (j == m) return ans;
//         }
        
//         return {};
//     }
// };
