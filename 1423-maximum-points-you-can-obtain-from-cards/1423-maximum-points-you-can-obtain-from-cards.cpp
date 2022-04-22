class Solution {
public:
    //INTUITION: Take first k elements, because at most k elements can be taken at a stretch from the starting.
    //Then one by one removing one element backwards from the k-1 th index element, and adding one element from the last from n-1 th index element
    //The max score encountered within this process will be the answer
    int maxScore(vector<int>& cardPoints, int k) {
        int score = 0, maxScore = 0, n = cardPoints.size();
        for(int i=0; i<k;i++)
            score+=cardPoints[i];
        maxScore = max(maxScore,score);
        for(int i = 0; i<k;i++)
        {
            score-=cardPoints[k-i-1]; score+=cardPoints[n-1-i];
            maxScore = max(score,maxScore);
        }
        return maxScore;
    }
};