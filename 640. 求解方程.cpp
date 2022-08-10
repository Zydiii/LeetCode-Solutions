class Solution {
public:
    string solveEquation(string equation) {
        int left = 1, xNum = 0, constanNum = 0, flag = 1, num = 0, valid = 0;
        for(auto &c : equation){
            if(c == '='){
                if(num != 0)
                    constanNum -= flag * num * left;
                left = -1;
                num = 0;
                flag = 1;
                valid = 0;
            }
            else if(c == 'x'){
                if(valid)
                    xNum += num * left * flag;
                else
                    xNum += left * flag;
                num = 0;
            }
            else if(c == '+'){
                constanNum -= flag * num * left;
                flag = 1;
                num = 0;
                valid = 0;
            }
            else if(c == '-'){
                constanNum -= flag * num * left;
                flag = -1;
                num = 0;
                valid = 0;
            }
            else{
                num = num * 10 + (c - '0');
                valid = 1;
            }
        }
        if(equation[equation.size() - 1] == 'x'){
            xNum += num * left * flag; 
        }
        else{
            constanNum -= flag * num * left;
        }
        if(xNum == 0){
            if(constanNum == 0)
                return "Infinite solutions";
            return "No solution";
        }
        return "x=" + to_string(constanNum / xNum);
    }
};