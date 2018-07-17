class Solution {
public:
    bool isMatch(string s, string p) {
        bool M[s.size() + 1][p.size() + 1] = { {false} };
        
        M[s.size()][p.size()] = true;
        
        for (int i = s.size(); i >= 0; i--) {
            for (int j = p.size(); j >= 0; j--) {
                if (i == s.size() && j == p.size()) continue;
                
                bool first_match = (s[i] == p[j] || p[j] == '.');
                
                if (j + 1 < p.size() && p[j + 1] == '*') {
                    M[i][j] = M[i][j+2] || i < s.size() && first_match && M[i+1][j];
                } else {
                    M[i][j] = first_match && i < s.size() && j < p.size() && M[i+1][j+1];
                }
            }
        }
        
        return M[0][0];
    }
};

