class Solution {
public:
    int mirrorReflection(int p, int q) {
        int counter = 0;
        int height = 0;
        
        while (true) {
            counter++;
            height += q;
            
            if (counter % 2 == 0) { // even
                if (height % p == 0) return 2;
            } else {
                if (height % p == 0 && (height / p) % 2 != 0) return 1;
                if (height % p == 0 && (height / p) % 2 == 0) return 0;
            }
        }
        
        return -1;
    }
};

