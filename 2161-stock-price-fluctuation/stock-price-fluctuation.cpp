class StockPrice {
private:
    unordered_map<int, int> priceAtTime;
    multiset<int> prices;
    int latestTimestamp = 0;

public:
    StockPrice() {}

    void update(int timestamp, int price) {
        // Correct an existing timestamp
        if (priceAtTime.count(timestamp)) {
            auto it = prices.find(priceAtTime[timestamp]);
            prices.erase(it);
        }

        priceAtTime[timestamp] = price;
        prices.insert(price);

        latestTimestamp = max(latestTimestamp, timestamp);
    }

    int current() {
        return priceAtTime[latestTimestamp];
    }

    int maximum() {
        return *prices.rbegin();
    }

    int minimum() {
        return *prices.begin();
    }
};


/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */