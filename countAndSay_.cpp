class Solution {
public:
    string countAndSay(int n) {
     if(n==1) return "1";
        string temp = countAndSay(n-1);
        string ans="";
        for(int i=0;i<temp.size();) {
            char ch = temp[i];
            int cnt=0;
            while(temp[i]==ch && i<temp.size()) {
                cnt++;
                i++;
            }
            ans.push_back(cnt+'0');
            ans.push_back(temp[i-1]);
        }
        return ans;
        }
};
