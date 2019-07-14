// Question : Take  a string Find out the unique word count

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int base=26;
    string s,a;
    getline(cin,s);

    for(auto &x:s)if(x==',' || x=='.' || x=='-')x=' ';

    stringstream ss(s);
    long long mod1=1000000+3,mod2=691871;
    vector<pair<long long,long long>> v;
    while(ss>>a)
    {
        long long sum1=0,sum2=0;
        for(auto x:a)
        {
            sum1+=(sum1*base+x)%mod1;
            sum1%=mod1;

            sum2+=(sum2*base+x)%mod2;
            sum2%=mod2;
        }
        v.push_back({sum1,sum2});
    }
    sort(v.begin(),v.end());
    int cnt=1;
    for(int i=1;i<v.size();i++)
    {
        if(v[i]!=v[i-1])cnt++;
    }
    cout<<cnt<<endl;
}
