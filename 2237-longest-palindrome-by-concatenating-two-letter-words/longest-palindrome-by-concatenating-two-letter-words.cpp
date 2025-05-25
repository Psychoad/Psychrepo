class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> count;
        int result = 0;
        bool hasMiddle = false;
        for (auto& word : words) {
            string rev = word;
            reverse(rev.begin(), rev.end());
            if (count[rev] > 0) {
                result += 4;
                count[rev]--;
            } else {
                count[word]++;
            }
        }
        for (auto& [word, cnt] : count) {
            if (word[0] == word[1] && cnt > 0) {
                hasMiddle = true;
                break;
            }
        }
        if (hasMiddle) result += 2;
        return result;
    }
};