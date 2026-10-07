// class Solution {
// public:
//     vector<string> removeInvalidParentheses(string s) {
//         int n = s.size();
//         stack<char>st;
//         string ans = "";
//         int l=0,r=0;
//         for(int i=0;i<n;i++){
//             if(s[i]=='('){
//                 st.push(s[i]);
//                 l++;
//             }
//             else if(l==0 && s[i]==')'){
//                 r=0;
//                 }
//             else if(l!=0 && s[i]==')'){
//                     r++;
//             }

//             else if(l==r){
//                 ans.push_back(st.top());
//                 ans.push_back(s[i]);
//                 st.pop();
//             }

//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {

        vector<string> ans;

        int n = s.size();
        stack<int> st;

        int l = 0, r = 0;

        // Find invalid '(' and ')'
        for (int i = 0; i < n; i++) {

            if (s[i] == '(') {
                st.push(i);
                l++;
            }

            else if (s[i] == ')') {

                if (!st.empty()) {
                    st.pop();
                    l--;
                }
                else {
                    r++;
                }
            }
        }

        // l = extra '('
        // r = extra ')'

        // Backtracking to remove them
        function<void(string, int, int, int)> solve =
            [&](string str, int index, int left, int right) {

                if (left == 0 && right == 0) {

                    int balance = 0;

                    for (char c : str) {

                        if (c == '(')
                            balance++;

                        else if (c == ')') {
                            balance--;

                            if (balance < 0)
                                return;
                        }
                    }

                    if (balance == 0)
                        ans.push_back(str);

                    return;
                }

                for (int i = index; i < str.size(); i++) {

                    // Avoid duplicate results
                    if (i > index && str[i] == str[i - 1])
                        continue;

                    // Remove extra '('
                    if (left > 0 && str[i] == '(') {

                        string temp = str;
                        temp.erase(i, 1);

                        solve(temp, i, left - 1, right);
                    }

                    // Remove extra ')'
                    if (right > 0 && str[i] == ')') {

                        string temp = str;
                        temp.erase(i, 1);

                        solve(temp, i, left, right - 1);
                    }
                }
            };

        solve(s, 0, l, r);

        return ans;
    }
};