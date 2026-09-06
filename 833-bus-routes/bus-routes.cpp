class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source== target) return 0;

        int n= routes.size();

        // stop-> buses having that stop
        unordered_map<int, vector<int>> stopToBus;

        for(int i=0; i<n; i++){
            for(int stop: routes[i])
                stopToBus[stop].push_back(i);
        }

        queue<int> q;
        vector<bool> visitedBus(n, false);

        for(int bus: stopToBus[source]){
            q.push(bus);
            visitedBus[bus]= true;
        }

        int busTaken=1;

        while(!q.empty()){
            int size= q.size();

            while(size--){
                int bus= q.front();
                q.pop();

                for(int stop: routes[bus]){
                    if(stop== target)
                        return busTaken;
                    
                    for(int nextBus: stopToBus[stop]){
                        if(!visitedBus[nextBus]){
                            visitedBus[nextBus]= true;
                            q.push(nextBus);
                        }
                    }
                }
            }
            busTaken++;
        }
        return -1;
    }
};