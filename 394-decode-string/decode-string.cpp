class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> strs;
        string curr = "";
        int num = 0;

        for(char c : s){
            if(isdigit(c)){
                num = num * 10 + (c - '0');
            }
            else if(c == '['){
                nums.push(num);
                strs.push(curr);
                curr = "";
                num = 0;
            }
            else if(c == ']'){
                string temp = curr;
                curr = strs.top(); strs.pop();
                int k = nums.top(); nums.pop();
                while(k--) curr += temp;
            }
            else{
                curr += c;
            }
        }
        return curr;
    }
};