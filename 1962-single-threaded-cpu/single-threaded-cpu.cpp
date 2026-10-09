class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        // {enqueueTime, processingTime, originalIndex}
        vector<array<int, 3>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({tasks[i][0], tasks[i][1], i});
        }

        sort(arr.begin(), arr.end());

        // Min heap: {processingTime, originalIndex}
        priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> ans;
        long long time = 0;
        int i = 0;

        while (i < n || !pq.empty()) {
            // If no task is available, jump to the next enqueue time
            if (pq.empty() && time < arr[i][0]) {
                time = arr[i][0];
            }

            // Add every task available at the current time
            while (i < n && arr[i][0] <= time) {
                pq.push({arr[i][1], arr[i][2]});
                i++;
            }

            // Process the task with shortest processing time
            auto task = pq.top();
            pq.pop();

            ans.push_back(task.second);
            time += task.first;
        }

        return ans;
    }
};