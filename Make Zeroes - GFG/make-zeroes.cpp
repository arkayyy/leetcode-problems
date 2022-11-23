//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void MakeZeros(vector<vector<int> >& matrix) {
        vector<vector<int>> matrix1 (matrix.begin(),matrix.end());
        for(int i = 0; i<matrix.size(); ++i)
            for(int j = 0; j<matrix[0].size(); ++j)
                if(matrix1[i][j]==0) 
                {
                    if(i+1<matrix.size())
                    {
                        matrix[i+1][j] = 0;
                        matrix[i][j] += matrix1[i+1][j];
                    }
                    if(i-1>=0)
                    {
                        matrix[i-1][j] = 0;
                        matrix[i][j] += matrix1[i-1][j];
                    }
                    if(j+1<matrix[0].size())
                    {
                        matrix[i][j+1] = 0;
                        matrix[i][j] += matrix1[i][j+1];
                    }
                    if(j-1>=0)
                    {
                        matrix[i][j-1] = 0;
                        matrix[i][j] += matrix1[i][j-1];
                    }
                }
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.MakeZeros(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends