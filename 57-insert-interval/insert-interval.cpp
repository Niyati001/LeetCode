class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;

        int i=0;
        int n= intervals.size();

        // part1
        while(i<n && intervals[i][1]< newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        // part 2
        while(i<n && intervals[i][0]<= newInterval[1]){
            newInterval[0]= min(intervals[i][0], newInterval[0]);
            newInterval[1]= max(intervals[i][1], newInterval[1]);
            i++;
        }
        ans.push_back(newInterval);

        //part3
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};