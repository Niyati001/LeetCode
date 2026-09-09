class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // height descending k ascending
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b){
            if(a[0]== b[0])
                return a[1]< b[1];
            
            return a[0]> b[0];
        });

        vector<vector<int>> queue;

        for(auto person: people){
            int k= person[1];

            queue.insert(queue.begin()+ k, person);
        }
        return queue;
    }
};