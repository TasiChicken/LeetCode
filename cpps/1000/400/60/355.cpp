#include <vector>
#include <unordered_set>

using namespace std;

    class Twitter {
        vector<pair<int, int>> user_posts[500];
        unordered_set<int> user_follows[500];
        int time = 0;

        int getNewestPoster(int userID){
            int id = -1, postTime = -1;
            if(!user_posts[userID].empty())
                id = userID, postTime = user_posts[userID].back().second;
            for(int f : user_follows[userID])
                if(!user_posts[f].empty() && user_posts[f].back().second > postTime)
                    id = f, postTime = user_posts[f].back().second;
            return id;
        }
    public:
        Twitter() {
            
        }
        
        void postTweet(int userId, int tweetId) {
            user_posts[userId - 1].emplace_back(tweetId, time++);
        }
            
        vector<int> getNewsFeed(int userId){
            userId--;

            vector<int> ans, ids, times;
            for(int i = 0; i < 10; i++){
                int id = getNewestPoster(userId);
                if(id == -1) break;

                ids.push_back(id);
                ans.push_back(user_posts[id].back().first);
                times.push_back(user_posts[id].back().second);
                user_posts[id].pop_back();
            }
            for(int i = ans.size() - 1; i >= 0; i--)
                user_posts[ids[i]].emplace_back(ans[i], times[i]);
            return ans;
        }
        
        void follow(int followerId, int followeeId) {
            user_follows[followerId - 1].insert(followeeId - 1);
        }
        
        void unfollow(int followerId, int followeeId) {
            user_follows[followerId - 1].erase(followeeId - 1);
        }
    };