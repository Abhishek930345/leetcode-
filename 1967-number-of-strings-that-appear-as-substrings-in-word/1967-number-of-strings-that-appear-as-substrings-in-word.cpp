class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int total=0;
        for(string str :patterns ){
        if (word.find(str) != string::npos)total++;
        }
        return total;
    }
};