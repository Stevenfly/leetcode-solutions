class Solution {  
public:
    string intToRoman(int num) {
        map<int, string> romanValues;
        
        romanValues[1] = "I";
        romanValues[4] = "IV";
        romanValues[5] = "V";
        romanValues[9] = "IX";
        romanValues[10] = "X";
        romanValues[40] = "XL";
        romanValues[50] = "L";
        romanValues[90] = "XC";
        romanValues[100] = "C";
        romanValues[400] = "CD";
        romanValues[500] = "D";
        romanValues[900] = "CM";
        romanValues[1000] = "M";

        string result = "";
        int temp;
        
        map<int, string>::reverse_iterator rit;
        for (rit = romanValues.rbegin(); rit != romanValues.rend(); ++rit) {
            temp = num / rit->first;
            if (temp > 0) {
                for (int i = 0; i < temp; i++) {
                    result += rit->second;
                }
                num %= rit->first;
            }
        }
        
        return result;
    }
};

