class Solution {
public:
    int findTheWinner(int n, int k) {

    list<int> friends;
       
       for(int i=1; i<=n; ++i) {
        friends.push_back(i);
    }

    auto current = friends.begin();

    while(friends.size() > 1) {
        for(int i=1; i<k; ++i) {
            current++;
            if(current == friends.end()) {
                current = friends.begin();
            }
        }
        
        auto toRemove = current;
        current++;
        if(current == friends.end()){
            current = friends.begin();
        }

        friends.erase(toRemove);
    }
    return friends.front();
    }
};

    // Time Complexity --> O(N * K)
    // Space Complexity --> O(N)