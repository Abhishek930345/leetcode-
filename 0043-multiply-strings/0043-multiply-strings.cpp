// class Solution {
// public:
//     string multiply(string num1, string num2) {

//         string ans="";
//         string add="";
//         for(int i=num2.size();i>=0;i--){
//             for(int j=num1.size()-1;j>=0;j--){

//                 add+=num2[i]*num1[j];
//             }
//             for(int k=0;k<i;k++){
//                 add+='0';
//             }
//             ans+=add;
//             add="";
//         }
//         return ans;
        
//     }
// };

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int n = num1.size();
        int m = num2.size();

        vector<int> res(n + m, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');

                int sum = mul + res[i + j + 1];

                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }

        string ans = "";
        int i = 0;

        while (i < res.size() && res[i] == 0) {
            i++;
        }

        while (i < res.size()) {
            ans += to_string(res[i]);
            i++;
        }

        return ans;
    }
};
