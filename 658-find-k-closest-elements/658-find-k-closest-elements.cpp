class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //Using inbuilt sort function:-
        // sort(arr.begin(), arr.end(), [&](int &a, int &b){
        //     if(abs(a-x)==abs(b-x)) return a<b;
        //     return abs(a-x)<abs(b-x);
        // });
        // vector<int> ans(arr.begin(), arr.begin()+k);
        // sort(ans.begin(),ans.end());
        // return ans;
        
        //Using Priority Queue:-
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto n:arr)
            pq.push({abs(n-x),n});
        vector<int> ans;
        for(int i = 0; i<k;i++)
            {ans.push_back(pq.top().second); pq.pop();}
        sort(ans.begin(),ans.end());
        return ans;
    }
};