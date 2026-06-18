class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // frequency count
        vector<int> freq(26,0);
        for(char c: tasks){
            freq[c- 'A']++;
        }
        //max heap
        priority_queue<int> pq;
        for(int f: freq){
            if(f>0) pq.push(f);
        }
        //cooldown queue (remaining_freq, available_time)
        queue<pair<int, int>> q;
        int time=0;
        
        while(!pq.empty() || !q.empty()) {
            time++;
        
            // release from cooldown
            if(!q.empty() && q.front().second== time){
                pq.push(q.front().first);
                q.pop();
            }
        
            //execute task if available
            if(!pq.empty()){
                int f= pq.top();
                pq.pop();

                f--; //used once

            if(f>0){
                q.push({f, time+n+1});
            }
        }
    }
    return time;
    }
};