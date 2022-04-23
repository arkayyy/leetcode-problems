class Twitter {
    private:
    vector<pair<int,int>>posts;
    unordered_map<int, unordered_map<int, int>>follows;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_back(make_pair(userId, tweetId));
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>res;
        int n = 0;
        for(int i = posts.size() - 1; i >= 0 && n < 10; i--)
            if(posts[i].first == userId || follows[userId][posts[i].first])
                res.push_back(posts[i].second), n++;
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId][followeeId] = 1;
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId][followeeId] = 0;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */