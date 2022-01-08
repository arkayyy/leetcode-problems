class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int i=0;
        int maxLen = INT_MIN;
        while(i<arr.size()-1)
        {
            if(arr[i]<arr[i+1]) //condition for the beginning of uprising side of a mountain...
            {
                int startMountain = i;
                bool validMountain = false;
                
                while(i<arr.size()-1 && arr[i]<arr[i+1]) //for the uprising side of the mountain
                    i++;
                
                while(i<arr.size()-1 && arr[i]>arr[i+1]) //for the downgoing side of the mountain
                    {i++; validMountain = true;} //we are making the validMountain indicator true, since a mountain can be valid only if it as both an uprising and a downgoing side.
                
                int endMountain = i;
                
                int len = endMountain - startMountain +1;
                
                if(validMountain)
                    maxLen = max(maxLen, len); //updating maximum length of mountain stretch found till now
                
                continue;
            }
            i++;
        }
        return (maxLen==INT_MIN)?0:maxLen; //if maxLen not updated, it means no valid mountain stretch was found
    }
};