class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);

        // count characters in magazine
        for(char c : magazine) {
            freq[c - 'a']++;
        }

        // try to build ransomNote
        for(char c : ransomNote) {
            if(freq[c - 'a'] == 0) {
                return false;
            }
            freq[c - 'a']--;
        }

        return true;
    }
};