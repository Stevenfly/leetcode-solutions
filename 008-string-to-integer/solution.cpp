class Solution {
public:
    int myAtoi(string str) {
        int sign = 1;   // 1 for '+', -1 for '-'
        
        for (char c: str) {
            if (c != ' ') {
                if (c == '-') sign = -1;
                break;
            }
        }

        int result = 0;
        
        try {
            result = stoi(str);
        } catch (std::out_of_range& e) {
            if (sign == 1) {
                return INT_MAX;
            } else {
                return INT_MIN;
            }
        } catch (...) {
            return 0;
        }
        
        return result;
    }
};

