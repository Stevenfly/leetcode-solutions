class Solution {   
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> solutions;
        
        for (int k = 0; k < nums.size(); k++) {
            int target = nums[k];
            
            // reduce unnecessary works
            if (target > 0) {
                break;
            } else if (k > 0 && target == nums[k-1]) {
                continue;
            }
            
            // 2 sum
            int i = k + 1;
            int j = nums.size() - 1;
            
            while (i < j) {
                int first = nums[i];
                int second = nums[j];
                
                // reduce unnecessary works
                if (i > k + 1 && first == nums[i-1]) {
                    i++;
                    continue;
                }
                if (j < nums.size() - 1 && second == nums[j+1]) {
                    j--;
                    continue;
                }
                
                if (first + second + target == 0) {
                    solutions.push_back({target, first, second});
                    i++;
                    j--;
                } else if (first + second + target < 0) {
                    i++;
                } else {
                    j--;
                }
            }
        }
        
        return solutions;
    }
};

