class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() == B.size()) {
            int counter = 0;
            map<char, int> m;
            bool same = false;
            char a1 = '.';
            char b1 = '.';
            char a2 = '.';
            char b2 = '.';
            for (int i = 0; i < A.size(); i++) {
                if (A[i] != B[i]) {
                    counter++;
                    if (counter > 2) return false;
                    if (a1 == '.' && b1 == '.') {
                        a1 = A[i];
                        b1 = B[i];
                    } else if (a2 == '.' && b2 == '.') {
                        a2 = A[i];
                        b2 = B[i];
                    }
                } else {
                    if (m.find(A[i]) != m.end()) {
                        m[A[i]] = m[A[i]] + 1;
                        if (m[A[i]] >= 2) same = true;
                    } else {
                        m[A[i]] = 1;
                    }
                }
            }
            if (A == B && same) return true;
            if (counter != 2) return false;
            
            return (a1 == b2 && a2 == b1);
        }
        
        return false;
    }
};

