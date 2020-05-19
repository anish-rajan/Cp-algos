#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    string s;
    cin>>s;
    vector<ll> cum(s.size());
    cum[0] = 0;
    for(ll i=1;i<s.size();i++)
    {
        cum[i] = cum[i-1];
        if(s[i]==s[i-1])
            cum[i]++;
    }
    ll m;
    cin>>m;
    for(ll i=0;i<m;i++)
    {
        ll l,r;
        cin>>l>>r;
        l--,r--;
        if(l==0)
        {
            cout<<cum[r]<<"\n";
        }
        else
        {
            if(s[l]==s[l-1])
            cout<<cum[r]-cum[l-1]-1<<"\n";
            else
            cout<<cum[r]-cum[l-1]<<"\n";
        }
    }
}