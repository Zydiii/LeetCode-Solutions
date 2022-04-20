class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.size();
        int pos = 0, result = 0;
        vector<int> level(n + 1);
        while(pos < n) {
            int depth = 1;
            while(pos < n && input[pos] == '\t') {
                pos++;
                depth++;
            }
            int len = 0;
            bool isFile = false;
            while(pos < n && input[pos] != '\n') {
                if(input[pos] == '.')
                    isFile = true;
                len++;
                pos++;
            }
            pos++;
            if(depth > 1)
                len += level[depth - 1] + 1;
            if(isFile)
                result = max(result, len);
            else
                level[depth] = len;
        }

        return result;
    }
};
