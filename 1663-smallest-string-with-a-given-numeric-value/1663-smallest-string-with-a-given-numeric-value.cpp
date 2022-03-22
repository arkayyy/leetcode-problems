class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans =  "";
        for(int i = 0; i<n; i++)
        {
            ans+="a";
        }
        int curr = n;
        int idx = n-1;
        while(curr<k)
        {
            //cout<<curr<<" "<<ans<<endl;
            if(ans[idx]-'a'==25)
                {idx--; }
            else
            {
                ans[idx]++;
                curr++;
            }
        }
         return ans;  
    }
};