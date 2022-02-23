class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        long long ans = 0;
        long long p = pow(26,n-1);
        for(int i = 0; i<n; i++)
        {
            ans+= (p*(columnTitle[i]-'A'+1));
            p/=26;
        }
        
        return ans;
    }
};