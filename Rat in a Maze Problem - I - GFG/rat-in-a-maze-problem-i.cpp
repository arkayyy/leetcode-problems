// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    int dx[4]= {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    void util(int i,int j,string&curr, vector<vector<int>>&visited, vector<vector<int>>&m, vector<string>&ans, unordered_map<int,char>&mp)
    {
        if(i==m.size()-1 && j==m[0].size()-1) {ans.push_back(curr); return;}
        for(int t = 0; t<4; ++t)
        {
            int xx = i+dx[t], yy = j+dy[t];
            if(xx>=0 && xx<m.size() && yy>=0 && yy<m[0].size() && !visited[xx][yy] && m[xx][yy]!=0)
            {
                visited[xx][yy] = true;
                curr+=mp[t];
                util(xx,yy,curr,visited,m,ans,mp);
                curr.pop_back();
                visited[xx][yy] = false;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0]==0) return {};
        unordered_map<int,char> mp;
        mp[0] = 'D', mp[1] = 'U', mp[2] = 'R', mp[3] = 'L';
        vector<string> ans;
        string curr = "";
        vector<vector<int>>visited(m.size(),vector<int>(m[0].size(),0));
        visited[0][0]=true;
        util(0,0,curr,visited,m,ans,mp);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends