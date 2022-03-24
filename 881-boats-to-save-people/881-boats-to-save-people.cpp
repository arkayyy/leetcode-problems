class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        //INTUITION: If we sort the people in terms of increasing weight, we can try to:
        //(i) pair one heaviest with one lightest if possible
        //(ii) OR include only the heaviest on the boat
        //Since all weights are <=limit so this approach will work perfectly.
        
        //ALGO: 2-pointer approach after sorting
        sort(people.begin(), people.end());
        int i = 0, j = people.size()-1;
        while(i<=j)
        {
            if(people[i]+people[j]<=limit)
                ++i;
            --j;// j pointer will decrement always
            //if pair is formed both i will incr and j will decr 
            //otherwise only j pointer element will go on boat and j will decr
        }
        return people.size()-1-j; //since j always decremented, denoting number of boats needed irrespective of paired or not
        //Therefore (last index - j) would give the total boats needed
    }
};