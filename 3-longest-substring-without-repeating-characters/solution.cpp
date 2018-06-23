class Solution {
public:
    int lengthOfLongestSubstring(string s) {   
        int maxLen = 0;
        queue<char> d;
        queue<char> temp;
        
        for (char c: s) {
            temp = d;
            bool found = false;
            
            while (d.size() > 0) {
                int e = d.front();
                d.pop();
                
                if (c == e) {
                    found = true;
                    break;
                }
            }
            
            if (!found) d = temp;
            
            d.push(c);
            
            if (d.size() > maxLen) maxLen = d.size();
        }
              
        return maxLen;
    }
};

