class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n= quality.size();

        vector<pair<double, int>> workers;

        for(int i=0; i<n; i++){
            double ratio= (double) wage[i]/ quality[i];
            workers.push_back({ratio, quality[i]});
        }

        sort(workers.begin(), workers.end());

        priority_queue<int> pq;

        long long sumQuality=0;
        double ans= DBL_MAX;

        for(auto worker: workers){
            double ratio= worker.first;
            int q= worker.second;

            pq.push(q);
            sumQuality+= q;

            if(pq.size()> k){
                sumQuality-= pq.top();
                pq.pop();
            }

            if(pq.size()== k){
                double cost= ratio* sumQuality;
                ans= min(ans, cost);
            }
        }
        return ans;
    }
};