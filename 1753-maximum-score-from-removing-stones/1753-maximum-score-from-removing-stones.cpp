class Solution {
public:
    //INTUITION: If the sum of two smaller elements is smaller than the maximum element, that means all of the two small numbers can be used to make pairs of removal
    //Otherwise, if sum of 2 smaller numbers is greater than max element, then all of max element will be used up for pairs of removal
    //say c is the max element, so first (a+b-c)/2 pairs will be removed, followed by c pairs (leftover of the ex-max element)
    int maximumScore(int a, int b, int c) {
        int maxi = max({a,b,c});
        int total = a+b+c;
        int othersSum = total - maxi;
        return maxi>=othersSum?othersSum:(total/2);
    }
};