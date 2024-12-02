// LeetCode.cpp : Defines the entry point for the application.
//

#include "LeetCode.h"

using namespace std;

class Twitter {
    struct FeedCompare {
        bool operator()(const auto& tweet1, const auto& tweet2) {
            return tweet1.second > tweet2.second;
        }
    };

    static FeedCompare feedCompare;

    void fillFeedWithNewTweets(int userId, vector<pair<int, int>>& feed) {
        for (auto& tweet : m_tweets[userId]) {
            if (tweet.second > feed.front().second) {
                pop_heap(feed.begin(), feed.end(), feedCompare);
                feed.back() = tweet;
                push_heap(feed.begin(), feed.end(), feedCompare);
            } else {
                break;
            }
        }
    }
public:
    Twitter() : m_time(0) {

    }

    void postTweet(int userId, int tweetId) {
        auto& tweetsQueue = m_tweets[userId];

        tweetsQueue.emplace_front(tweetId, ++m_time);
        if (tweetsQueue.size() > 10) { tweetsQueue.pop_back(); }
    }

    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> feed(10);

        fillFeedWithNewTweets(userId, feed);
        for (int followee : m_followees[userId]) { fillFeedWithNewTweets(followee, feed); }

        sort(feed.begin(), feed.end(), [](const auto& tweet1, const auto& tweet2) { return tweet1.second > tweet2.second; });

        vector<int> result;
        for (auto& tweet : feed) {
            if (tweet.second > 0) { result.push_back(tweet.first); } else { break; }
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        m_followees[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        m_followees[followerId].erase(followeeId);
    }
private:
    unordered_map<int, deque<pair<int, int>>> m_tweets;
    unordered_map<int, set<int>> m_followees;
    int m_time;
};

int main()
 {
    INIT_TIME(timer);

    PRINT_ELAPSED(timer);
    return 0;
}