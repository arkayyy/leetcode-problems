class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        if(wordSet.find(endWord)==wordSet.end()) return {};
        
        queue<pair<string,int>> q;  //contains word and the level associated with it
        q.push({beginWord,1});
        unordered_set<string> visited;
        
        int level = 1;
        // int minLevel = INT_MAX;
        
        while(!q.empty())
        {
            string last = q.front().first;
            int currLevel = q.front().second;
            q.pop();
            if(currLevel>level)
            {
                for(auto w: visited) wordSet.erase(w);
                visited.clear();
               // if(currLevel>minLevel) break;
                level = currLevel;
            }
            for(int i = 0;i<last.size(); i++)
            {
                string news = last;
                for(char c = 'a'; c<='z'; c++)
                {
                    news[i] = c;
                    if(wordSet.find(news)!=wordSet.end())
                    {
                        visited.insert(news);
                        if(news==endWord)
                        {return currLevel+1;}
                        else
                            q.push({news,currLevel+1});
                    }
                }
            }
        }
        return 0;
        
    }
};