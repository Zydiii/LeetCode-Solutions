class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        if(timePoints.size() > 1440)
            return 0;
        vector<bool> maps(1440);
        for(int i = 0; i < timePoints.size(); i++)
        {
            string time = timePoints[i];
            int hour = stoi(time.substr(0, 2));
            int minute = stoi(time.substr(3, 2));
            int pos = hour * 60 + minute;
            if(maps[pos])
                return 0;
            maps[pos] = true;
        }

        int firstPos = -1;
        int lastPos = -1;
        int prev = -1;
        int minDiff = maps.size() - 1;
        for(int i = 0; i < maps.size(); i++)
        {
            if(maps[i])
            {
                if(prev != -1)
                {
                    minDiff = minDiff < i - prev ? minDiff : i - prev;
                }
                prev = i;
                if(firstPos == -1)
                    firstPos = i;
                lastPos = i;
            }
        }
        minDiff = minDiff < maps.size() - lastPos + firstPos ? minDiff : maps.size() - lastPos + firstPos;
        return minDiff;
    }
};