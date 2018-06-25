class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> stack;
        
        for (char c: S) {
            if (c == '(') {
                stack.push(-1);
            } else {
                int num = 0;
                
                int first = stack.top();
                stack.pop();
                
                if (first == -1) {
                    num = 1;
                } else {
                    num = 2 * first;
                    stack.pop();
                }
                
                int second = -2;
                if (stack.size() > 0) {
                    second = stack.top();
                }
                if (second > 0) {
                    num += second;
                    stack.pop();
                }
                
                stack.push(num);
            }
        }
        
        if (stack.size() > 0) {
            return stack.top();
        } else {
            return 0;
        }
    }
};

