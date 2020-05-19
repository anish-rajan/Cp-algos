#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define inp_push(no, v) \
    ll no;              \
    cin >> no;          \
    v.push_back(no);
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 300005
#define mod 1000000007
ll t;
long long powmod(long long x, long long y, long long m)
{
    long long res = 1LL;
    while (y)
    {
        if (y & 1)
            res = (res * x) % m;
        // cout << x << " " << mod << "\n";
        x = (x * x) % m;
        y /= 2;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        v<ll> a(n+1);
        for(ll i=1;i<=n;i++)
            cin>>a[i];
        ll f=0,p=0;
        if(n==1 && a[1]==k)
            f=1;
        for(ll i=1;i<=n;i++)
        {
            if(a[i]==k)
                p=1;
            if(i<=n-1)
            {
            if(a[i]>=k && a[i+1]>=k)
                f=1;
            }
            if(i<=n-2)
            {
                if(a[i]>=k && a[i+2]>=k)
                    f=1;
            }
        }
        if(f==1 && p==1)
            cout<<"yes\n";
        else
            cout<<"no\n";

    }
}