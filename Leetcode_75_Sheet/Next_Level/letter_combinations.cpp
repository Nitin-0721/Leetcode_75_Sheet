class Solution {
public:
vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};

    vector<string> mappings = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result = {""};  
    for (char digit : digits) {
        vector<string> temp;
        string letters = mappings[digit - '0'];
        
         for (string combination : result) {
             for (char l : letters) {
                temp.push_back(combination + l);
            }
        }
         result = temp;
    }

    return result;
}
};