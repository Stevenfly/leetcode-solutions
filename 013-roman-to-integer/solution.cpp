class Solution {
    
const int I = 1;
const int V = 5;
const int X = 10;
const int L = 50;
const int C = 100;
const int D = 500;
const int M = 1000;
    
public:
    int romanToInt(string s) {
        int result = 0;
        char last = ' ';
        
        for (char c: s) {
            if (c == 'I') {
                result += I;
            } else if (c == 'V') {
                result += V;
                if (last == 'I') result -= 2 * I;
            } else if (c == 'X') {
                result += X;
                if (last == 'I') result -= 2 * I;
            } else if (c == 'L') {
                result += L;
                if (last == 'X') result -= 2 * X;
            } else if (c == 'C') {
                result += C;
                if (last == 'X') result -= 2 * X;
            } else if (c == 'D') {
                result += D;
                if (last == 'C') result -= 2 * C;
            } else if (c == 'M') {
                result += M;
                if (last == 'C') result -= 2 * C;
            }
            
            last = c;
        }
        
        return result;
    }
};

