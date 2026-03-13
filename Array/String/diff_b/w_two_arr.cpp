class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

        vector<vector<int>> result(2);

         for(int i = 0; i < nums1.size(); i++) {

            bool found = false;

            for(int j = 0; j < nums2.size(); j++) {
                if(nums1[i] == nums2[j]) {
                    found = true;
                    break;
                }
            }

            if(!found) {

                bool duplicate = false;

                for(int k = 0; k < result[0].size(); k++) {
                    if(result[0][k] == nums1[i]) {
                        duplicate = true;
                        break;
                    }
                }

                if(!duplicate) {
                    result[0].push_back(nums1[i]);
                }
            }
        }

         for(int i = 0; i < nums2.size(); i++) {

            bool found = false;

            for(int j = 0; j < nums1.size(); j++) {
                if(nums2[i] == nums1[j]) {
                    found = true;
                    break;
                }
            }

            if(!found) {

                bool duplicate = false;

                for(int k = 0; k < result[1].size(); k++) {
                    if(result[1][k] == nums2[i]) {
                        duplicate = true;
                        break;
                    }
                }

                if(!duplicate) {
                    result[1].push_back(nums2[i]);
                }
            }
        }

        return result;
    }
};