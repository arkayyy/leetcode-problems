class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        for(int i = 1; i<=9; i++)
            q.push(i);
        
        vector<int> ans;
        
        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            if(t>high) break;
            
            if(t>=low) ans.push_back(t); 
            
            int lastDigit = t%10; //extracting last digit
            if(lastDigit<9) //if last digit is =9, then on doing 9+1 we get 10 which can't be accomodated in sinle digit space
                q.push((t*10)+(lastDigit+1)); //storing element for next sequence
        }
        
        return ans;
    }
};