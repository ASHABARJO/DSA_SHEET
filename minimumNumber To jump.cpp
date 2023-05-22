int jump=0;
    int pos=0;
    int des=0;
    for(int i=0;i<n-1;i++){
        des=max(des,arr[i]+i);
        
        if(pos==i)
        {
         pos=des;
         jump++;
        }
    }
     return jump;
