class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int n) {
        deque<int> dq;
    vector<int> ans;
    int i = 0, j = 0;
    while(j<a.size())
    {
        if(!dq.empty() && dq.front() == j-n) {dq.pop_front();}
        while(!dq.empty() && a[j]>a[dq.back()]) {dq.pop_back();}
        dq.push_back(j);
       
        if(j>=n-1) ans.emplace_back(a[dq.front()]);
         ++j;
    }
    return ans;
    }
};