#include <string>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int reverse(int x) {
        bool isNeg = false;
        if (x < 0) {
            isNeg = true;
            x = -x;
        }
        string xStr = to_string(x);
        std::reverse(xStr.begin(), xStr.end());
        long int xReversed = isNeg ? -stol(xStr) : stol(xStr);
        if (xReversed > INT_MAX || xReversed < INT_MIN) {
            return 0;
        }
        return xReversed;
    }
};

