class Solution {
public:
    //XXXXX - DFS WON'T WORK HERE, since all paths produce different min. value of steps needed
    //Even along with DP, the minimum value won't be memoized always, so we won't get correct answers by using wrongly memoized values...
    
    //Explanation: https://leetcode.com/problems/open-the-lock/discuss/110230/BFS-solution-C%2B%2B
    
    //Therefore, we use level order traversal using BFS. Every next level will store all the neighboring string combinations that have not already been visited or not a deadend...
    int openLock(vector<string>& deadends, string target) {
        int steps = 0;
        if(target=="0000") return 0;
        unordered_set<string> s(deadends.begin(),deadends.end());
        unordered_set<string> visited;
        
        //We are performing level order traversal using DFS...
        queue<string> q;
        q.push("0000");
        if(s.find("0000")!=s.end()) return -1; //if initial state is only a dead-end
        visited.insert("0000");
        
        while(!q.empty())
        {
            int len = q.size();
            for(int i = 0; i<len;i++)
            {
                string t = q.front();
                q.pop();
                vector<string> nbrs =getNeighbors(t); //getting all neighboring combinations of current combination
                for(auto nbr: nbrs)
                {
                    if(nbr==target) return ++steps; //if target reached
                    if(s.find(nbr)!=s.end()) //if current combination found in deadends, we simply go to the next combination that's all, we don't need to do anything else.
                    {
                        continue;
                    }
                    if(visited.find(nbr)==visited.end()) //only if current combination not already visited earlier
                    {
                        visited.insert(nbr); q.push(nbr);
                    }
                    
                }
                nbrs.clear();//freeing unnecessary memory
            }
            steps++;
        }
        
        return -1; //if target is never formed
        
        
    }
    
    vector<string> getNeighbors(string s)
    {//using simple maths
        vector<string> ans;
        for(int i=0; i<4;i++)
        {
            string temp = s;
            temp[i] = (char)((s[i] - '0' + 1) % 10 + '0');
            ans.push_back(temp);
            temp[i] = (char)((s[i] - '0' - 1 + 10) % 10 + '0');
            ans.push_back(temp);
        }
        return ans;
    }
};