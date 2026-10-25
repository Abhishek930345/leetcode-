class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int dept=0;
        int maxi=0;
        for(char ch : s){
            if(ch=='('){
                dept++;
                maxi=max(maxi,dept);
            }
            if(ch==')'){
                dept--;
            }
        }
        return maxi;
        
    }
};