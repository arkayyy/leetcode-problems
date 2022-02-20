class Solution {
public:
    //INTUITION: If we keep the value of seats at both the start and end index of an interval, and initially all values between them are 0.
    //While printing the final answer, we can print all the values in between these 2 indexes by adding the same seats value.
    //We  can use the prefix sum method to get the final result vector...
	//Algo called: SWEEP LINE ALGORITHM
	
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n+1,0);
        for(auto b: bookings)
        {
            //NOTE:We are using 0 based indexing in our result vector..that's why changing value of index b[0]-1 and not b[0]..it will be useful in doing prefix sum tho..
            
            ans[b[0]-1] += b[2]; //adding the value of seats before the starting interval so that when prefix sum is done(i.e.ans[i]+=ans[i-1]), the number of seats gets included in the starting index
            ans[b[1]] -= b[2]; //subtracting the value because when we come after doing prefix sums till this index, at this index it will become 0 after getting neutralised (previous interval seats eliminated)
        }
        for(int i=1; i<=n; i++)
           ans[i]+=ans[i-1];//doing prefix sum
        return {ans.begin(),ans.end()-1};
    }
};