class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int i=0;
        int maxLen = INT_MIN;
        while(i<arr.size()-1)
        {
            if(arr[i]<arr[i+1])
            {
                int startMountain = i;
                bool validMountain = false;
                while(i<arr.size()-1 && arr[i]<arr[i+1])
                    i++;
                while(i<arr.size()-1 && arr[i]>arr[i+1])
                    {i++; validMountain = true;}
                int endMountain = i;
                int len = endMountain - startMountain +1;
                if(validMountain)
                    maxLen = max(maxLen, len);
                continue;
            }
            i++;
        }
        return (maxLen==INT_MIN)?0:maxLen;
    }
};