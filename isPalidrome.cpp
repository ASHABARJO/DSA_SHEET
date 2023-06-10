class Solution {
public:
  
  bool valid(char ch){
  if((ch>='a' && ch<='z') ||(ch>='A' && ch<='Z') ||(ch>='0' && ch<='9'))
  return true;
  
  return false;
  }
  char islower(char ch){
      if(ch>='a'|| ch<='z')
      return ch;
      return ch-'A'+'a';
  }
  bool checkPalidrome(string s){
      int st=0;
      int e=s.size()-1;
      while(st<=e){
          if(tolower(s[st])!=tolower(s[e]))
          return false;
          else{
              st++;
              e--;
          }

      }
return true;
  }
    bool isPalindrome(string s) {
     string t="";
     for(int i=0;i<s.size();i++){
         if(valid(s[i]))
  t.push_back(s[i]);
        
     }           

  for(int j=0;j<t.size();j++)
 { t[j]=tolower(t[j]);
 }
return checkPalidrome(t);
    }
};
