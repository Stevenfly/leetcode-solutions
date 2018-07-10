class Solution {
public:
    string convert(string s, int numRows) {
        if (s.size() <= 1 || numRows == 1) return s;
        
        string result = "";
        
        int sectionSize = numRows * 2 - 2;
        
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < s.size() / sectionSize + 1; j++) {
                int firstIndex = j * sectionSize + i;
                int scondIndex = (j + 1) * sectionSize - i;
                
                if (firstIndex < s.size()) result += s[firstIndex];
                if (i > 0 && i < numRows - 1 && scondIndex < s.size()) result += s[scondIndex];
            }
        }
        
        return result;
    }
};

