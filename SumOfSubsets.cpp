#include<bits/stdc++.h>
using namespace std;

vector<int> v;

int n,x[1000],m;

int cnt=0;
bool ok=false;
void printSet(int k)
{
    cout<<"Solution of Subset "<<++cnt<<endl;
    for(int i=0; i<=k; i++)
    {
        if(x[i]==1)
            cout<<v[i]<<" ";
    }
    cout<<endl;

}

bool SumOfSub(int s,int k,int r)
{

    x[k]=1;
    if(s+v[k]==m)
    {
        printSet(k);
        ok=true;
    }
    else if(s+v[k]+v[k+1]<=m)
    {
        SumOfSub(s+v[k],k+1,r-v[k]);
    }
    if( (s+r-v[k]>=m) && (s+v[k+1])<=m)
    {
        x[k]=0;
        SumOfSub(s,k+1,r-v[k]);
    }
    else
    {
        return ok;
    }

}

int main()
{

    int s=0;

    cin>>n;


    for(int i=0; i<n; i++){
          int x ; cin>>x;

          v.push_back(x);

          s+=v[i];
    }


    cin>>m;

    sort(v.begin(),v.end());

    bool res=SumOfSub(0,0,s);

    if(res==false)
        cout<<"no required subset found"<<endl;






    return 0;
}
