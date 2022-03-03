class Solution {
public:
    string nearestPalindromic(string n) {
        vector<unsigned long long> candidates = getCandidates(n);
        unsigned long long result = -1;
        unsigned long long num = stoull(n);
        for(unsigned long long c : candidates)
        {
            if(c != num)
            {
                if(result == -1 || llabs(result - num) > llabs(c - num) || (llabs(result - num) == llabs(c - num) && c < result))
                    result = c;
            }
        }
        return to_string(result);
    }

    vector<unsigned long long> getCandidates(string n)
    {
        int size = n.size();
        vector<unsigned long long> candidates = {(unsigned long long)pow(10, size) + 1, (unsigned long long)pow(10, size - 1) - 1};
        unsigned long long prefix = stoull(n.substr(0, (size + 1) / 2));
        for(int i : {prefix - 1, prefix, prefix + 1})
        {
            string pre = to_string(i);
            string c = pre + string(pre.rbegin() + size % 2, pre.rend());
            candidates.push_back(stoull(c));
        }
        return candidates;
    }
};