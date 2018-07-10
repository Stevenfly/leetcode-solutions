// my original solution is pretty similar to expandAroundCenter method from the solution,
//   but the string takes too much time, instead we can just play around with indices,
//   this is an optimized solution based on both my solution and expandAroundCenter.

class Solution {
private:
    int getPalinLen(string s, int left, int right) {
        int L = left;
        int R = right;
        
        while (L >= 0 && R < s.size()) {
            if (s[L] == s[R]) {
                L--;
                R++;
            } else {
                break;
            }
        }
        
        return R - L - 1;
    }
    
public:
    string longestPalindrome(string s) {
        int start = 0;
        int len = 1;
        
        for (int i = 0; i < s.size(); i++) {
            int len1 = getPalinLen(s, i-1, i);
            int len2 = getPalinLen(s, i, i);
            int maxLen = max(len1, len2);
            if (maxLen >= len) {
                len = maxLen;
                start = i - maxLen/2;
            }
        }
        
        return s.substr(start, len);
    }
};

