class Solution {
public:
    int longestPalindrome(string s) {
        // Frequency array for ASCII characters
        int count[128] = {0}; 
        
        // Count frequencies of each character
        for (char c : s) {
            count[c]++;
        }
        
        int length = 0;
        bool has_odd = false;
        
        // Calculate the maximum palindrome length
        for (int i = 0; i < 128; i++) {
            if (count[i] % 2 == 0) {
                length += count[i]; // Use all even frequencies
            } else {
                length += count[i] - 1; // Use the largest even part of an odd frequency
                has_odd = true; // Mark that we found at least one odd character
            }
        }
        
        // Place exactly one unique odd character in the center if available
        if (has_odd) {
            length += 1;
        }
        
        return length;
    }
};