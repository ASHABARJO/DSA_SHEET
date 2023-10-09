//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  string PrintString(string S,int start,int end){
     string ans="";
      for(int i=start;i<=end;i++){
   ans+=S[i];
  }
      return ans;
  }
    string longestPalin (string S) {
        // code here
         int start = 0; // Initialize start and end to 0
    int end = 0;
    int n = S.size();

    for (int i = 0; i < n; i++) {
        // Odd length palindrome
        int l = i;
        int h = i;
        while (l >= 0 && h < n && S[l] == S[h]) {
            if (h - l + 1 > end - start + 1) {
                start = l;
                end = h;
            }
            l--;
            h++;
        }

        // Even length palindrome
        l = i;
        h = i + 1;
        while (l >= 0 && h < n && S[l] == S[h]) {
            if (h - l + 1 > end - start + 1) {
                start = l;
                end = h;
            }
            l--;
            h++;
        }
    }

    return PrintString(S, start, end);

    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
