class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        if(wordSet.find(endWord)==wordSet.end()) return {};
        
        queue<pair<string,int>> q;  //contains word and the level associated with it
        q.push({beginWord,1});
        
        unordered_set<string> visited;//contains visited words in a level ONLY
        
        int level = 1; //initially globally we are present at level 1
        
        while(!q.empty())
        {
            string last = q.front().first; //last word
            
            int currLevel = q.front().second; 
            q.pop();
            if(currLevel>level)
            {
                for(auto w: visited) wordSet.erase(w);
                visited.clear();
               // if(currLevel>minLevel) break;
                level = currLevel;
            }
            //We keep swapping each character in last word to any one from 'a' to 'z' one by one
            for(int i = 0;i<last.size(); i++)
            {
                string news = last;
                for(char c = 'a'; c<='z'; c++)
                {
                    news[i] = c;
                    if(wordSet.find(news)!=wordSet.end()) //if new reformed word is yet to be found
                    {
                        visited.insert(news);
                        if(news==endWord) //the first time we reach the target word will always be by shortest/min path itself...BFS RULE!!!
                            return currLevel+1; 
                        else
                            q.push({news,currLevel+1}); //otherwise storing new word for next level
                    }
                }
            }
        }
        return 0;
        
    }
};