class Solution {
public:
    vector<int> prefix;
    int total=0;

    Solution(vector<int>& w) {
        total=0;

        for(int weight: w){
            total+= weight;
            prefix.push_back(total);
        }
    }
    
    int pickIndex() {
        int target= rand() % total+1;

        int left=0, right= prefix.size()-1;

        while(left< right){
            int mid= left+ (right- left)/2;

            if(prefix[mid]>= target)
                right= mid;
            else
                left= mid+1;
        }
        return left;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */