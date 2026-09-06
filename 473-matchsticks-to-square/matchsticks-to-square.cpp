class Solution {
public:
    bool solve(vector<int>& sticks, vector<int>& sides,
               int index, int target) {

        if(index == sticks.size())
            return true;

        int x = sticks[index];

        for(int i = 0; i < 4; i++) {

            // Same side state -> same result
            if(i > 0 && sides[i] == sides[i - 1])
                continue;

            if(sides[i] + x > target)
                continue;

            sides[i] += x;

            if(solve(sticks, sides, index + 1, target))
                return true;

            sides[i] -= x;

            // If putting it in an empty side failed,
            // trying another empty side is identical.
            if(sides[i] == 0)
                break;
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;

        for(int x : matchsticks)
            sum += x;

        if(sum % 4 != 0)
            return false;

        int target = sum / 4;

        for(int x : matchsticks) {
            if(x > target)
                return false;
        }

        sort(matchsticks.rbegin(), matchsticks.rend());

        vector<int> sides(4, 0);

        return solve(matchsticks, sides, 0, target);
    }
};