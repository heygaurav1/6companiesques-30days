class Solution {
public:
   string getHint(string secret, string guess) {
    int bulls = 0;
    int cows = 0;
    int n = secret.length();

    vector<int> secretCounts(10, 0);
    vector<int> guessCounts(10, 0);

    // First, count bulls and populate the counts
    for (int i = 0; i < n; ++i) {
        if (secret[i] == guess[i]) {
            bulls++;
        } else {
            secretCounts[secret[i] - '0']++;
            guessCounts[guess[i] - '0']++;
        }
    }

    // Then, count cows based on the remaining unmatched digits
    for (int i = 0; i < 10; ++i) {
        cows += min(secretCounts[i], guessCounts[i]);
    }

    return to_string(bulls) + "A" + to_string(cows) + "B";
}
};