class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int num1Pos = num1.find('+');
        int num1A = stoi(num1.substr(0, num1Pos));
        int num1B = stoi(num1.substr(num1Pos + 1, num1.size() - 2 - num1Pos));
        int num2Pos = num2.find('+');
        int num2A = stoi(num2.substr(0, num2Pos));
        int num2B = stoi(num2.substr(num2Pos + 1, num2.size() - 2 - num2Pos));
        return to_string(num1A * num2A - num1B * num2B) + '+' + to_string(num1A * num2B + num1B * num2A) + 'i';
    }
};