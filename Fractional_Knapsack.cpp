#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,w;
    cin>>n>>w;


    vector<float> pro(n),wei(n);
    vector<pair<double,int> > rat;

    for(int i=0;i<n;++i){
        cin>>pro[i]>>wei[i];
    }

    for(int i=0;i<n;++i){
     rat.push_back(make_pair(pro[i]/wei[i],i));
    }


    sort(rat.begin(),rat.end());

    double maxpro=0.0;

    for(int i=n-1;i>=0 && w>0;--i){
       if(wei[rat[i].second]<=w){
        w-=wei[rat[i].second];

        maxpro+=pro[rat[i].second];

       }else{
         double x1=wei[rat[i].second];
         double x=min(double(w),double(x1));

         w-=x;
         maxpro+=pro[rat[i].second] * (x/wei[rat[i].second]);

       }
       //cout<<rat[i].first<<" ";
    }

    cout<<maxpro<<endl;






    return 0;
}
/*

7 15
5
1
10 3
15 5
7 4
8 1
9 3
4 2


*/
