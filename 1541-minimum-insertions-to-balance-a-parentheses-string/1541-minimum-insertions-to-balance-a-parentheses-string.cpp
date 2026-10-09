// class Solution {
// public:
//     int minInsertions(string s) {
//         int n=s.size();
//         int l=0;
//         int r=0;
//         for(int i=0;i<n;i++){
//             if(s[i]=='('){
//                 l+=2;
//             }
//             else if(l==0 && s[i]==')'){
//                 r++;
//                 l++;
//             }
//             else{
//                 r++;
//             }
//         }
//         int result=abs(l-r);
//         int ans=result;
//         if(l>r){
//             result=2*result;
//             return ans+result;
//         }else{
//             return result;
//         }

//     }
// };


class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int need = 0;

        for (char c : s) {
            if (c == '(') {
                // An opening parenthesis needs two ')'
                need += 2;

                // If need is odd, the previous ')' was unmatched
                if (need % 2 == 1) {
                    ans++;
                    need--;
                }
            }
            else {
                need--;

                // No opening parenthesis is available
                if (need < 0) {
                    ans++;
                    need = 1;
                }
            }
        }

        return ans + need;
    }
};