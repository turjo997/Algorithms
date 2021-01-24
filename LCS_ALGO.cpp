#include<bits/stdc++.h>
using namespace std;

int main()
{
    string x,y,s,s1,lcs;
    int n,n1;

    cin>>x>>y;

    n= x.size();
    n1= y.size();

    if(n<n1){
        s = y;
        s1 = x;
    }else{
        s = x;
        s1=y;
    }

    int a[s1.size()+2][s.size()+2];

    for(int i=0;i<=s1.size()+1;++i){
        for(int j=0;j<=s.size()+1;++j){
          a[i][j]=0;
        }
    }

    for(int i=0;i<s1.size();i++){
        for(int j=0;j<s.size();j++){
            if(s1[i]==s[j]){

                a[i+1][j+1] = a[i][j] + 1;
            }else{
                a[i+1][j+1] = max(a[i+1][j],a[i][j+1]);
            }
        }

    }


    for(int i=0;i<=s1.size();++i){

        for(int j=0;j<=s.size();++j){

          cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }



    int i= s1.size(),j=s.size();

   while(i>0 && j>0){

        if(s1[i-1] == s[j-1]){
            lcs+=s1[i-1];
             --i;
             --j;
        }
        else if(a[i-1][j] > a[i][j-1]){
            --i;
        }else{
           --j;
        }

   }


    reverse(lcs.begin(),lcs.end());



    cout<<"The longest Common Subsequence is :  "<<endl;
    cout<<lcs<<endl;




    return 0;
}
