class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        //BFS of paths...
        unordered_set<string> wordSet(wordList.begin(), wordList.end());//will contain only those words which have not been visited yet
        //wordSet.insert(endWord);
        
        queue<vector<string>> q; // will store levels/paths
        q.push({beginWord}); //first level consists only of beginWord
        wordSet.erase(beginWord); //since it is counted, we remove it from the desrired words list
        
        int level = 1; //indicating current level of operation
        int minLevel = INT_MAX; //minimum levels to reach beginword->endWord (recorded instantaneously)
     
        unordered_set<string> levelVisited; //will contain visited words level by level...visited word in a level must not be visited in an upcoming level, as that won't be the shortest path
        while(!q.empty())
        {
            vector<string> path = q.front(); //intermediate path
            q.pop();
            if(path.size()>level) //means we have reached a new level
            {
                for(auto word: levelVisited) wordSet.erase(word); //erasing all words that have already been visited
                levelVisited.clear(); //making visited array ready for the next new level
                if(path.size()>minLevel)
                    break;
                else
                    level = path.size(); //updating current level number for future use
            }
            string last = path.back();
            //finding next words in wordSet by changing one character (at a time) (picking each character and swapping it with each character from 'a' to 'z' one by one)
            for(int i = 0; i<last.size(); i++)
            {
                string news = last; 
                for(char c = 'a'; c<='z'; c++)
                {
                    news[i] = c;
                    if(wordSet.find(news)!=wordSet.end()) // next word in the path is found, so we proceed to adding it to the current path
                    {
                        vector<string> newpath = path;
                        newpath.push_back(news);
                        levelVisited.insert(news);
                        if(news==endWord) //reached target word
                        {
                            minLevel = level; //will update minLevel only when we reach target..in BFS the first time that we reach target is always by the minimum/shortest path covered..so only once minLevel will be set.
                            ans.push_back(newpath); 
                        }
                        else //if not reached target yet, we add this intermediate path(level) to the queue for further processing
                            q.push(newpath);
                    }
                }
            }
        }
        
        return ans;
    }
};