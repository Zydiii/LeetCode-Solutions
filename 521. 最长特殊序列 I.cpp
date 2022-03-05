class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a.size() == b.size())
            return a == b ? -1 : a.size();
        return a.size() > b.size() ? a.size() : b.size();
    }
};