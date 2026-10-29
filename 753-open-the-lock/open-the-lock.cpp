class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());

        if(dead.count("0000"))
            return -1;

        queue<pair<string, int>> q;
        unordered_set<string> visited;

        q.push({"0000", 0});
        visited.insert("0000");

        while(!q.empty()){
            auto [curr, turns]= q.front();
            q.pop();

            if(curr== target)
                return turns;

            for(int i=0; i<4; i++){
                for(int move: {-1, 1}){
                    string next= curr;

                    int digit= curr[i]-'0';
                    digit= (digit+move+10)% 10;

                    next[i]= char('0'+ digit);

                    if(!dead.count(next) && !visited.count(next)){
                        visited.insert(next);
                        q.push({next, turns+1});
                    }
                }
            }
        }
        return -1;
    }
};