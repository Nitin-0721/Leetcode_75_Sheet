class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;

        while (c != 0 || a != 0 || b != 0) {
            int cSetBit = 1 & c;
            c = c >> 1;
            int aSetBit = 1 & a;
            a = a >> 1;
            int bSetBit = 1 & b;
            b = b >> 1;
            if (cSetBit == 1) {
                if (aSetBit == 0 && bSetBit == 0)
                    cnt++;
            } else {
                if (aSetBit == 1 && bSetBit == 1)
                    cnt += 2;
                else if (aSetBit == 1 || bSetBit == 1)
                    cnt++;
            }
        }
        return cnt;
    }
};