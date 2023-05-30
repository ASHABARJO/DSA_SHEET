bool isPossible(vector<int>boards,int n,int k,int mid){
    int  CountPainter=1;
    int boardsSum=0;
    for(int i=0;i<n;i++){
        if(boards[i]+boardsSum<=mid)
        boardsSum+=boards[i];
else{
    CountPainter++;
    if(CountPainter>k || boards[i]>mid)
    return false;
    
    boardsSum=boards[i];
}
    }
return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{int ans=-1;
    //    Write your code here.
    int n=boards.size();
    int sum=0;
    int s=0;
    for (int i = 0; i < n; i++) {
      sum += boards[i];
    }
    int e=sum;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(isPossible(boards,n,k,mid)){
ans=mid;
e=mid-1;
        } else {
          s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    
    
return ans;
}
