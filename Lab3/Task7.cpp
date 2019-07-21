// Question : given an string, tokenize them, make hash, and search a word in it and its count

#include<bits/stdc++.h>
using namespace std;
struct node{
    pair<long long,long long> pr;
    string word;
    int cnt=1;
    node(pair<long long,long long> pp,string w)
    {
        pr=pp;
        word=w;
        cnt=1;
    }
    bool operator==(const node& a) const
    {
        return (pr == a.pr);
    }
    bool operator<(const node& a) const
    {
        return (pr < a.pr);
    }
};
pair<long long,long long> hash(string s)
{
    long long mod1=1000000+3,mod2=691871;
    long long sum1=0,sum2=0;
    for(auto x:s)
    {
        sum1+=(sum1*base+x)%mod1;
        sum1%=mod1;

        sum2+=(sum2*base+x)%mod2;
        sum2%=mod2;
    }
    return {sum1,sum2};
}

vector<node> v;

void make_count()
{
    vector<node> vv;
    v.push_back(node({-1,-1},"test"));
    for(int i=0;i+1<v.size();i++)
    {
        if(v[i]==v[i+1])v[i+1].cnt=v[i].cnt+1;
        else
        {
            vv.push_back(v[i]);
        }
    }
    v=vv;
}

int main()
{
    int base=26;
    string s,a;
    getline(cin,s);

    for(auto &x:s)if(x==',' || x=='.' || x=='-')x=' ';

    stringstream ss(s);

    while(ss>>a)
    {
        pair<long long,long long> p=hash(a);
        node temp(p,a);
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    make_count();
    cin>>s;

}
