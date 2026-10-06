// class Solution {
// public:
//     int scoreOfParentheses(string s) {
//         int n = s.size();
//         int count=0;
//         int m=0;
//         int score=0;
//         for(int i=0;i<n;i++){
//             if(s[i]=='('){
//                 count++;
//                 m=1;
//             }
//             else if(m==1 && s[i]==')'){
//                 score+=1;
//                 m++;
//                 count--;
//             }
//             else{
//                 score=2*score;
//                 count--;
//                 m++;
//             }
//         }
//         return score;
//     }
// };

class Solution {
public:
    int scoreOfParentheses(string s) {
        int depth = 0;
        int score = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                depth++;
            }
            else {
                // Found "()"
                if (s[i - 1] == '(') {
                    score += (1 << (depth - 1));
                }

                depth--;
            }
        }

        return score;
    }
};