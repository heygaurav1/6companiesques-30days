class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int median;
        if (n % 2 == 0) {
           median = (nums[n/2 - 1] + nums[n/2]) / 2;
        }else {
             median = nums[n/2];
        }

        long long moves = 0;
        for(int num : nums) {
            moves += abs(num - median);
        }
       return (int) moves;

    
    }
};

   // Time Complexity --> O(N log N)
   // Space Complexity --> O(1)