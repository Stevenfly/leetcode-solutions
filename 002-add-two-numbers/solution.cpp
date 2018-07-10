/*
 * Time: ~ 1hr
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

/*
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newList = nullptr;
        ListNode* temp = nullptr;
        ListNode* newNode = nullptr;
        
        ListNode* curl1 = l1;
        ListNode* curl2 = l2;
        
        bool offset = false;
        
        while (curl1 || curl2 ) {
            int val1 = 0, val2 = 0;
            int sum = 0;
            int value = 0;
            
            if (curl1) {
                val1 = curl1->val;
                sum += val1;
                curl1 = curl1->next;
            }
            
            if (curl2) {
                val2 = curl2->val;
                sum += val2;
                curl2 = curl2->next;
            }
            
            if (offset) {
                sum++;
                offset = false;
            }
            
            if (sum < 10) {
                value += sum;
            } else {
                value += sum % 10;
                offset = true;
            }
            
            newNode = new ListNode(value);
            
            if (newList == NULL) {
                newList = newNode;
                temp = newList;
            } else {
                temp->next = newNode;
                temp = temp->next;
            }
        }
        
        return newList;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        
        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
