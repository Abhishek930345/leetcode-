// class Solution {
// public:
//     string addBinary(string a, string b) {
        
//         int n = a.size();
//         int m = b.size();
//         int l=n-1;
//         int r=m-1;
//         int carry=0;
//         vector<int> add;
//         string res="";

//         while(r>=0 && ){
//             if(a[l]=='1' && b[r]=='1'){
//                 add=carry+0;
//             }
//         }
//     }
// };

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            ans += char('0' + sum % 2);
            carry = sum / 2;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
