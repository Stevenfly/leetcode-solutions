class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        
        int maxLeft = height[left];
        int maxRight = height[right];
        
        int max = (right - left) * min(maxLeft, maxRight);
        
        while (left < right) {
            if (height[left] < height[right]) {
                left++;
                if (height[left] > maxLeft) {
                    maxLeft = height[left];
                    int area = (right - left) * min(maxLeft, maxRight);
                    if (area > max) {
                        max = area;
                    }
                }
            } else {
                right--;
                if (height[right] > maxRight) {
                    maxRight = height[right];
                    int area = (right - left) * min(maxLeft, maxRight);
                    if (area > max) {
                        max = area;
                    }
                }
            }
        }
        
        return max;
    }
};

