class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        int mid, mid1;

        while(left < right)
        {
            mid = (left + right) / 2;
            mid1 = mid + 1;
            if(arr[mid] < arr[mid1])
                left = mid1;
            else
                right = mid;
        }

        return left;
    }
};