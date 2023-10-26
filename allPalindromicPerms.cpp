//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool isPalidromic(string S){
      int i=0;
      int j=S.size()-1;
      while(i<j){
          if(S[i++]!=S[j--])
          return false;
      }
      return true;
  }
  void solve(string S,vector<vector<string>>&res,int idx,vector<string>curr){
      if(idx==S.size())
      { res.push_back(curr);
          return;
          
      }
          string temp;
          for(int i=idx;i<S.size();i++){
              temp.push_back(S[i]);
              if(isPalidromic(temp)){
              curr.push_back(temp);
              solve(S,res,i+1,curr);
              curr.pop_back();
          }          
              
          }
          
  }
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
    vector<vector<string>>res;
    vector<string>curr;
   
    solve(S,res,0,curr);
    return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
