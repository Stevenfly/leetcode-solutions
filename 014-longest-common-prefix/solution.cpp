class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp = "";
        bool first = true;
        for (string s: strs) {
            if (first) lcp = s;
            else {
                if (lcp == "") return "";
                for (int i = 0; i < lcp.size(); i++) {
                    if (s[i] != lcp[i]) {
                        lcp = lcp.substr(0, i);
                        break;
                    }
                }   
            }
            first = false;
        }
        return lcp;
    }
};

