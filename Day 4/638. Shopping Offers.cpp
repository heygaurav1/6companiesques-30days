class Solution {
public:
int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    int n = price.size();
    map<vector<int>, int> dp;

    function<int(vector<int>)> solve = [&](vector<int> currentNeeds) {
        if (dp.count(currentNeeds)) {
            return dp[currentNeeds];
        }

        int minPrice = 0;
        for (int i = 0; i < n; ++i) {
            minPrice += currentNeeds[i] * price[i];
        }

        for (const auto& offer : special) {
            vector<int> nextNeeds = currentNeeds;
            bool validOffer = true;
            for (int i = 0; i < n; ++i) {
                if (nextNeeds[i] < offer[i]) {
                    validOffer = false;
                    break;
                }
                nextNeeds[i] -= offer[i];
            }

            if (validOffer) {
                minPrice = min(minPrice, offer[n] + solve(nextNeeds));
            }
        }

        return dp[currentNeeds] = minPrice;
    };

    return solve(needs);

    }
};