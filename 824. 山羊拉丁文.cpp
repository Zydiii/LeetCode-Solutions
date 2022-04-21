class Solution {
public:
    string toGoatLatin(string sentence) {
        int index = 1;
        string word, result;
        set<char> yuanyin {'a', 'e', 'i', 'o', 'u'};
        for(int i = 0; i < sentence.size(); i++) {
            if(sentence[i] == ' ') {
                if(yuanyin.count(tolower(word[0])) == 0) {
                    word += word[0];
                    word = word.substr(1, word.size() - 1);
                }
                word += "ma";
                for(int j = 0; j < index; j++) {
                    word += "a";
                }
                result += word;
                result += " ";
                word = "";
                index++;
            }
            else {
                word += sentence[i];
            }
        }

        if(word != "") {
            if(yuanyin.count(tolower(word[0])) == 0) {
                    word += word[0];
                    word = word.substr(1, word.size() - 1);
            }
            word += "ma";
            for(int j = 0; j < index; j++) {
                word += "a";
            }
            result += word;
        }

        return result;
    }
};