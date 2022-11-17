class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int i = 0, j = 0, n = a.size();
        while(j<n)
        {
            //int curr = a[j];
            if(j>0 && a[j]==a[j-1]) while(j<n && a[j]==a[j-1]) ++j;
            else a[i++] = a[j++];
        }
        return i==0?1:i;
    }
};