class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int index = 0, lastIndex = index, count = 0;
        while(index != string::npos){
            count++;
            lastIndex = index == 0 ? index : index + 1;
            index = sentence.find(' ', lastIndex);
            string s = sentence.substr(lastIndex, index - lastIndex);
            if(s.find(searchWord) == 0)
                return count;
        }
        return -1;
    }
};