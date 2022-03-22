class Solution {
public:
    string getSmallestString(int n, int k) {
        //INTUITION: We take an "aaa..." of length n (with initial numeric value = 1*n) string initially and start increasing each character from the end, till the total numeric value < k
        //This will make a lexicographically least string since we are increasing from the end
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