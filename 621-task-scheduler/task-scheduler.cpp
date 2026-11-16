class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for(char c: tasks)
            freq[c- 'A']++;

        priority_queue<int> pq;

        for(int f: freq){
            if(f>0)
                pq.push(f);
        }

        queue<pair<int, int>> q;

        int time=0;

        while(!pq.empty() || !q.empty()){
            time++;

            if(!q.empty() && q.front().second== time){
                pq.push(q.front().first);
                q.pop();
            }

            if(!pq.empty()){
                int f= pq.top();
                pq.pop();

                f--;

                if(f>0){
                    q.push({f, time+n+1});
                }
            }
        }
        return time;
    }
};