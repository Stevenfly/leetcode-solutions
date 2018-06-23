class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        bool even = false;
        double result = 0;
        
        int size1 = nums1.size();
        int size2 = nums2.size();
        
        int total_size = size1 + size2;
        
        if (total_size % 2 == 0) {
            even = true;
        }
        
        int half_size = total_size / 2;
        
        int i = 0;
        int j = 0;
        
        int counter = 0;
        
        while (true) {
            int curNum;
            
            if (i < size1 && j < size2) {
                if (nums1[i] <= nums2[j]) {
                    curNum = nums1[i];
                    i++;
                } else {
                    curNum = nums2[j];
                    j++;
                }
            } else if (i < size1) {
                curNum = nums1[i];
                i++;
            } else if (j < size2) {
                curNum = nums2[j];
                j++;
            } else {
                break;
            }
            
            if (even && counter == half_size - 1) {
                result += curNum;
            }
            
            if (counter == half_size) {
                result += curNum;
                if (even) result /= 2;
                break;
            }
            
            counter++;
        }
        
        return result;
    }
};

