class Solution {
public:
    int uniquePaths(int m, int n) { 
        int total = m+n-2;
        int d = m-1;
        double ans = 1;
        for(int i = 1; i<=d; i++)
        {
            ans = ans*(total-d+i)/i;
        }
        return (int)ans;
    }
};