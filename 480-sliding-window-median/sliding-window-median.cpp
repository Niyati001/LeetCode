class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> left;
        multiset<int> right;

        vector<double> ans;

        auto add= [&](int x){
            if(left.empty() || x<= *left.rbegin()){
                left.insert(x);
            }
            else
                right.insert(x);

            if(left.size()> right.size()+1){
                auto it= prev(left.end());
                right.insert(*it);
                left.erase(it);
            }
            else if(right.size()> left.size()){
                auto it= right.begin();
                left.insert(*it);
                right.erase(it);
            }
        };

        auto remove= [&](int x){
            if(left.find(x)!= left.end()){
                left.erase(left.find(x));
            }
            else
                right.erase(right.find(x));

            if(left.size() > right.size() + 1) {
                auto it = prev(left.end());
                right.insert(*it);
                left.erase(it);
            }

            else if(right.size() > left.size()) {
                auto it = right.begin();
                left.insert(*it);
                right.erase(it);
            }
        };

        for(int i=0; i<k; i++){
            add(nums[i]);
        }

        if(k%2==1){
            ans.push_back(*left.rbegin());
        }
        else{
            ans.push_back(((double)*left.rbegin()+ *right.begin())/2.0);
        }

        for(int i=k; i<nums.size(); i++){
            remove(nums[i-k]);
            add(nums[i]);

            if(k%2==1){
                ans.push_back(*left.rbegin());
            }
            else{
                ans.push_back(((double)*left.rbegin()+ *right.begin())/ 2.0);
            }
        }
        return ans;
    }
};