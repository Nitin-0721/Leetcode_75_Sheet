class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;

        for(int i=0;i<=n;i++){
            int currentNumber = i;
            int count = 0;
            while(currentNumber > 0){
                if(currentNumber % 2 == 1){
                    count++;
                }
                currentNumber = currentNumber / 2;
            }
            ans.push_back(count);
        }
        return ans;
    }
};