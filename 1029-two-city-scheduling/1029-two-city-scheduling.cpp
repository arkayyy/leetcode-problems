class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        //INTUITION: If we sort the costs based upon increasing profit caused if B was selected instead of A. 
        //We can then say that for the first n costs, its better to take A, since less profit for selecting B will mean more profit in selecting A.
        //And for the next n costs, taking B will cause more profit than A, so we take B's cost.
        
        //ALGO: Sorting based upon the difference between cost to A and cost to B for every pair in costs vector.
        //and then adding A's cost in first n costs, and adding B's cost for next n costs.
        
        sort(costs.begin(),costs.end(), [](const vector<int>&a, const vector<int>&b){
            return (a[0]-a[1])<(b[0]-b[1]);
        });
        int total = 0;
        for(int i = 0; i< (costs.size()>>1); i++)
            total += costs[i][0];
        for(int i = (costs.size()>>1); i<costs.size(); i++)
            total += costs[i][1];
        
        return total;
    }
};