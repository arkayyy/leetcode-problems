// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // SEE PEPCODING VIDEO FOR REFERENCE:---- https://www.youtube.com/watch?v=3YILP-PdEJA
    int maxProfit(int K, int N, int A[])
    {
        int dp[K + 1][N];

        for (int i = 0; i <= K; i++)
            dp[i][0] = 0;
        for (int j = 0; j < N; j++)
            dp[0][j] = 0;

        for (int i = 1; i <= K; i++)
        {
            int maxDiff = INT_MIN;
            for (int j = 1; j < N; j++)
            {

                maxDiff = max(maxDiff, dp[i - 1][j - 1] - A[j - 1]);
                dp[i][j] = max(maxDiff + A[j], dp[i][j - 1]);
            }
        }

        return dp[K][N - 1];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
} // } Driver Code Ends