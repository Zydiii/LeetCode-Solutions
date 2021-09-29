#include <iostream>

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string ip, segIp;
        helper(result, s, ip, segIp, 0, 0);
        return result;
    }

    void helper(vector<string> &result, string s, string ip, string segIp, int segNum, int index)
    {
        if(index == s.length() && segNum == 3 && isValidIp(segIp))
        {
            ip += segIp;
            result.push_back(ip);
        }
        else if(index < s.length() && segNum < 4)
        {
            if(isValidIp(segIp + s[index]))
                helper(result, s, ip, segIp + s[index], segNum, index + 1);
            if(segIp.length() > 0)
                helper(result, s, ip + segIp + ".", s.substr(index, 1), segNum + 1, index + 1);
        }
    }

    bool isValidIp(string ip)
    {
        stringstream degree(ip);
        int x = 0;
        degree >> x;

        return x <= 255 && (ip == "0" || ip[0] != '0');
    }


};