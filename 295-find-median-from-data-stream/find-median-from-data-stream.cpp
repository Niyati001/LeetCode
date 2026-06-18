class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {}
    
    void addNum(int num) {
        //step1: add into left first
        left.push(num);

        //step2: balance: move largest left to right
        right.push(left.top());
        left.pop();

        //step3: ensure left has 1 more or equal elements as right
        if(right.size()> left.size()){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        //odd number of elements
        if(left.size()> right.size()) return left.top();

        //even number of elements
        return (left.top()+ right.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */