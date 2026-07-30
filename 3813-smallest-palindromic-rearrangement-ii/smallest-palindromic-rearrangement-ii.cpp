class Solution {
private:
    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n - r) r = n - r;
        
        long long ans = 1;
        for (int i = 1; i <= r; i++) {
            if (ans > LLONG_MAX / (n - i + 1)) return LLONG_MAX;
            ans = ans * (n - i + 1) / i;
        }
        return ans;
    }

    long long countPermutations(const vector<int>& count) {
        int total = 0;
        for (int freq : count) total += freq;
        
        long long arrangements = 1;
        int remaining = total;
        
        for (int freq : count) {
            if (freq > 0) {
                long long ways = nCr(remaining, freq);
                if (ways == 0) return 0;
                if (arrangements > LLONG_MAX / ways) return LLONG_MAX;
                arrangements *= ways;
                remaining -= freq;
            }
        }
        return arrangements;
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        
        vector<int> halfCount(26, 0);
        string mid = "";
        int halfLen = 0;
        
        for (int i = 0; i < 26; i++) {
            halfCount[i] = freq[i] / 2;
            halfLen += halfCount[i];
            if (freq[i] % 2 != 0) {
                mid = string(1, (char)('a' + i));
            }
        }
        
        if (countPermutations(halfCount) < k) {
            return "";
        }
        
        string leftHalf = "";
        long long target = k;
        
        for (int pos = 0; pos < halfLen; pos++) {
            for (int i = 0; i < 26; i++) {
                if (halfCount[i] == 0) continue;
                
                halfCount[i]--;
                long long permCount = countPermutations(halfCount);
                
                if (permCount >= target) {
                    leftHalf += (char)('a' + i);
                    break;
                } else {
                    target -= permCount;
                    halfCount[i]++;
                }
            }
        }
        
        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());
        
        return leftHalf + mid + rightHalf;
    }
};