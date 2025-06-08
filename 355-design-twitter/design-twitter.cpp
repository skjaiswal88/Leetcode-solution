class Twitter {
private:
    int timestamp = 0; // simulate global time
    unordered_map<int, unordered_set<int>> followees;
    unordered_map<int, vector<pair<int, int>>> tweets; // userId -> list of {timestamp, tweetId}

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(timestamp++, tweetId);
    }

    vector<int> getNewsFeed(int userId) {
        // Min-heap to get top 10 tweets based on timestamp
        priority_queue<pair<int, int>> pq;

        // Include self in feed
        followees[userId].insert(userId);

        for (int followeeId : followees[userId]) {
            auto& tws = tweets[followeeId];
            // Traverse from back: most recent
            for (int i = (int)tws.size() - 1; i >= 0 && i >= (int)tws.size() - 10; --i) {
                pq.push(tws[i]);
            }
        }

        vector<int> res;
        for (int i = 0; i < 10 && !pq.empty(); ++i) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followees[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};
