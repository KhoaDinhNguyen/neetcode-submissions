class Twitter {
public:
    unordered_map<int, set<int>> followMap;
    unordered_map<int, int> tweet;
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq; // {time, tweetId}
    int time = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[tweetId] = userId;
        pq.push({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        set<int> userIDs = followMap[userId];
        userIDs.insert(userId);

        priority_queue<pair<int, int>, vector<pair<int, int>>> temp;

        while (ans.size() < 10 && pq.size() > 0) {
            pair<int, int> top = pq.top();
            pq.pop();
            temp.push(top);

            int tweetId = top.second, authorTweet = tweet[tweetId];

            if (userIDs.count(authorTweet)) ans.push_back(tweetId);
        }

        while (!temp.empty()) {
            pq.push(temp.top());
            temp.pop();
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
