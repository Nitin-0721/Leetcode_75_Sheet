class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>stack;
        for(int asteroid : asteroids){
            bool alive = true;
            while(alive && !stack.empty()&&stack.back()>0 && asteroid < 0){
                if(stack.back()<-asteroid){
                    stack.pop_back();
                }else if(stack.back() == -asteroid){
                    stack.pop_back();
                    alive = false;
                }else{
                    alive = false;
                }
            }
            if(alive){
                stack.push_back(asteroid);
            }
        }
        return stack;
    }
};