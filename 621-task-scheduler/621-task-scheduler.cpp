class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //INTUITION: Say we have 3 A, 2 B, 1 C tasks
        //We place the most frequent tasks first
        //A ? ? A ? ? A ... gap between two same tasks must be alteast n = 2 (let)
        //We place next most frequent now: A B ? A B ? A
        //Then finally: A B C A B ? A
        //Only one place left which will be idle
        
        //So if we calculate the total idle time, then total time = tasks.length()+idle time
        //ALGO: Find the maximum frequent letter and then accordingly calculate the number of elements in between them.
        
        vector<int> count(26,0);
        int max = 0, maxc = 0;
        for(auto t: tasks)
        {
            count[t-'A']++;
            if(max==count[t-'A'])
                maxc++;
            if(count[t-'A']>max)
            {
                max = count[t-'A'];
                maxc = 1;
            }
        }
        
        int gapCount = max - 1; // A ... A. ..A ..so gaps in between  = 3-1 = 2
        int gapLength = n - (maxc-1); // n is the minimum gap length between two similar elements. So if maxc no. of elements have the max frequency, the gap will be reduced.
        int slotsEmpty = gapCount * gapLength;
        int tasksAvailable = tasks.size() - (max * maxc); //tasks other than the most frequent tasks
        int idleSlots = (slotsEmpty - tasksAvailable)>0?(slotsEmpty - tasksAvailable):0;
        //if slotsEmpty < tasksAvailable by any chance, we know we can arrange all distinct letters in between, but no idle slots will be left
        
        return tasks.size() + idleSlots;
    }
};