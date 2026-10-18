class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        for (auto& row : board) {
            for (int x : row) {
                start += char('0' + x);
            }
        }

        string target = "123450";

        // Adjacent positions for each index in the 2 x 3 board
        vector<vector<int>> adj = {{1, 3},{0, 2, 4},{1, 5},{0, 4},{1, 3, 5},{2, 4}};

        queue<string> q;
        unordered_set<string> visited;

        q.push(start);
        visited.insert(start);

        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                string curr = q.front();
                q.pop();

                if (curr == target)
                    return moves;

                int zero = curr.find('0');

                for (int next : adj[zero]) {
                    string nxt = curr;
                    swap(nxt[zero], nxt[next]);

                    if (!visited.count(nxt)) {
                        visited.insert(nxt);
                        q.push(nxt);
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};
