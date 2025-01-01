
class Solution {
 public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {

   if(envelopes.empty()){
    return 0;
  }

  sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
   if(a[0] == b[0]) {
    return a[1] > b[1]; 
}
return a[0] < b[0]; 

  });

  vector<int> heights;
  for(const auto& env : envelopes) {
   heights.push_back(env[1]);
  }

   vector<int> dp;
  for(int height : heights) {
    auto it = lower_bound(dp.begin(), dp.end(), height);
    if(it == dp.end()){
       dp.push_back(height);
    } else{
        *it = height;
    }
  }

  return dp.size();
  }
};

