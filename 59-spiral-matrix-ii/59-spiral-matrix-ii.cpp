class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int c=0;
        int leftlim = 0, rightlim = n-1, toplim = 0, botlim = n-1;
       
            while(c<= (n*n) )
            {
                for(int i = leftlim;i<=rightlim; i++)
                    {ans[toplim][i]=++c;}
                toplim++;
                
                if(c>=(n*n))
                    break;
                
                for(int i= toplim; i<=botlim;i++)
                    {ans[i][rightlim]=++c;}
                rightlim--;
                
                if(c>=(n*n))
                    break;
                
                for(int i= rightlim; i>=leftlim; i--)
                    {ans[botlim][i]=++c;}
                botlim--;
                
                if(c>=(n*n))
                    break;
                
                for(int i=botlim; i>=toplim; i--)
                    {ans[i][leftlim]=++c;}
                leftlim++;
            }
        
        return ans;
        
        
    }
};