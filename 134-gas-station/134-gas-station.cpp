class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //INTUITION: We can check till which last index, the car can't start the circle because the extra gas in the car would be negative.
        //ALGO: We check for the last index at which the extra gas in the car becomes -ve. 
        //This means we can safely start from just next to this index in order to get a +ve extra gas value throughout the circle.
        
        int totalExtraGas = 0, extraGas = 0;
        int idx = 0;
        for(int i = 0; i<gas.size(); i++)
        {
           totalExtraGas += gas[i]-cost[i]; 
            extraGas += gas[i]-cost[i];
            if(extraGas<0){extraGas = 0; idx = i+1;} //if extra gas value goes -ve, we reset it and store the index
        }
        
        return totalExtraGas<0?-1:idx;// if the total gas < total cost, not possible to complete the circle anyhow
    }
};