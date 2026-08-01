class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> events;
        for(auto &x: trips){
            events.push_back({x[1], x[0]});
            events.push_back({x[2], -x[0]});
        }

        sort(events.begin(), events.end(), [](auto &a, auto &b){
            if(a.first== b.first)
                return a.second< b.second;
            return a.first< b.first;
        });

        int passengers=0;

        for(auto &e: events){
            passengers+= e.second;

            if(passengers> capacity){
                return false;
            }
        }
        return true;
    }
};