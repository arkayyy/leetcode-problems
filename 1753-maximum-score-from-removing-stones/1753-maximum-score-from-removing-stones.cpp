class Solution {
public:
    //INTUITION: If the sum of two smaller elements is smaller than the maximum element, that means all of the two small numbers can be used to make pairs of removal
    //Otherwise, if sum of 2 smaller numbers is greater than max element, then all of max element will be used up for pairs of removal
    //say c is the max element, so first (a+b-c)/2 pairs will be removed, followed by c pairs (leftover of the ex-max element). So in total a+b+c/2
    int maximumScore(int a, int b, int c) {
        // int maxi = max({a,b,c});
        // int total = a+b+c;
        // int othersSum = total - maxi;
        // return maxi>=othersSum?othersSum:(total/2);
        
        //can also be solved by priority queue
        priority_queue<int> pq; pq.push(a);pq.push(b);pq.push(c);
        int score = 0;
        while(pq.size()>=2)
        {
            int t1 = pq.top(); pq.pop();
            int t2 = pq.top(); pq.pop();
            --t1,--t2;
            ++score;
            if(t1) pq.push(t1); 
            if(t2) pq.push(t2);
        }
        return score;
    }
};