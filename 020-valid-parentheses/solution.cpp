class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        for (char c: s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else {
                if (stack.size() == 0) return false;
                int top = stack.top();
                stack.pop();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        return stack.size() == 0;
    }
};

