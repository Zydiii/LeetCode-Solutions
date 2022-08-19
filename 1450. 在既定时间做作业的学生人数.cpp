class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int result = 0;
        for(int i{0}; i < startTime.size(); ++i){
            result = startTime[i] <= queryTime && endTime[i] >= queryTime ? result + 1 : result;
        }
        return result;
    }
};