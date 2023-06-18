//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&price){
    //Write your code here..
    int first_buy=INT_MIN;
    int first_sell=0;
    int second_buy=INT_MIN;
    int second_sell=0;
    
    for (int i=0;i<price.size();i++){
        first_buy=max(first_buy,-price[i]);
        first_sell=max(first_sell,first_buy+price[i]);
        second_buy=max(second_buy,first_sell-price[i]);
        second_sell=max(second_sell,second_buy+price[i]);
        
    }
    return second_sell;
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends
