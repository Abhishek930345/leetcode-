// class Solution {
// public:
//     bool checkValidString(string s) {
//         int n = s.size();
//         if(n==1) return false;
//         if(s[0]==')') return false;
//         int r=0,l=0,str=0;
//         for(char c : s){
//             if(c == '(') r++;
//             else if(c=='*')str++;
//             else l++;
//         }
//         if(l==r) return true;
//         else if(l<r){
//             if(l+str==r) return true;
//             else false;
//         }
//         else {
//             if(r+str==l)return false;
//             else false;
//         }

//     }
// };

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            }
            else if (c == ')') {
                low--;
                high--;
            }
            else {  // '*'
                low--;
                high++;
            }

            if (high < 0)
                return false;

            if (low < 0)
                low = 0;
        }

        return low == 0;
    }
};