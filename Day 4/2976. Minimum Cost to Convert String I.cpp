class Solution {
public:
 long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
    int n = source.length();
    if (n != target.length()) return -1;

    // Precompute all-pairs shortest paths for characters ONCE
    vector<vector<int>> dist(26, vector<int>(26, INT_MAX));
    for (int i = 0; i < 26; ++i) dist[i][i] = 0;

    for (int i = 0; i < original.size(); ++i) {
        dist[original[i] - 'a'][changed[i] - 'a'] = min(dist[original[i] - 'a'][changed[i] - 'a'], cost[i]); // Handle multiple edges
    }

    for (int k = 0; k < 26; ++k) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    long long totalCost = 0;
    for (int i = 0; i < n; ++i) {
        if (source[i] == target[i]) continue;

        int charCost = dist[source[i] - 'a'][target[i] - 'a'];
        if (charCost == INT_MAX) return -1;
        totalCost += charCost;
    }

    return totalCost;
}
};

//Time Complexity --> O(N^3)
//Space Complexity--> O(N)