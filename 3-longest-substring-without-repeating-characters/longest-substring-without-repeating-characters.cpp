class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charIndex(128, -1);
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char current_char = s[right];
            
            if (charIndex[current_char] >= left) {
                left = charIndex[current_char] + 1;
            }
            charIndex[current_char] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
