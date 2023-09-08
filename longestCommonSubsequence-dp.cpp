class Solution {
public:
// Recursion
int solve(string &a,string &b,int i,int j){
    if(i==a.length())
    return 0;
    if(j==b.length())
    return 0;
    int ans=0;
    if(a[i]==b[j]){
        ans=1+solve(a,b,i+1,j+1);
    }
    else{
        ans=max(solve(a,b,i+1,j),solve(a,b,i,j+1));
    }
    return ans;
}
// Memoization
int solveMem(string &a,string &b,int i,int j,vector<vector<int>>&dp){
    if(i==a.length())
    return 0;
    if(j==b.length())
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int ans=0;
    if(a[i]==b[j]){
        ans=1+solveMem(a,b,i+1,j+1,dp);
    }
    else{
        ans=max(solveMem(a,b,i+1,j,dp),solveMem(a,b,i,j+1,dp));
    }
    return dp[i][j]=ans;
}
// Tabulation
int solveTab(string &a,string &b){
    int s1=a.size();
     int s2=b.size();   
     vector<vector<int>>dp(s1+1,vector<int>(s2+1,0));
    dp[s1][s2]=0;
      for(int i=s1-1;i>=0;i--){
    for(int j=s2-1;j>=0;j--){
    int ans=0;
    if(a[i]==b[j]){
        ans=1+dp[i+1][j+1];
    }
    else{
        ans=max(dp[i+1][j],dp[i][j+1]);
    }
    dp[i][j]=ans;
     }
    }
    return dp[0][0];
}
// Space optimaization
int solveSO(string &a,string &b){
    int s1=a.size();
     int s2=b.size();   
    vector<int>curr(s2+1,0);
    vector<int>next(s2+1,0);
    for(int i=s1-1;i>=0;i--){
    for(int j=s2-1;j>=0;j--){
     int ans=0;
    if(a[i]==b[j]){
        ans=1+next[j+1];
    }
    else{
        ans=max(next[j],curr[j+1]);
    }
    curr[j]=ans;
    }
    next=curr;
    }
    return next[0];
}

    int longestCommonSubsequence(string text1, string text2) {
    //  return solve(text1,text2,0,0);
    //  int s1=text1.size();
    //  int s2=text2.size();   
    //  vector<vector<int>>dp(s1,vector<int>(s2,-1));
    // return solveMem(text1,text2,0,0,dp);   
    // return solveTab(text1,text2);
    return solveSO(text1,text2);
   
    }
};
