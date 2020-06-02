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
#define N 6
#define mod 1000000007
#define INF INT_MAX

ll n, k;
multiset<ll> p;

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
    cin >> n >> k;
    ll power = 0;
    while (n > 0)
    {
        if (n % 2)
            p.insert(power);
        n /= 2;
        power++;
    }
    if (k < p.size())
    {
        cout << "No\n";
        return 0;
    }
    ll nos = p.size();
    while (nos < k)
    {
        auto itr = p.end();
        itr--;
        auto temp = *itr;
        ll temp1 = p.count(temp);
        if (temp1 + nos <= k)
        {
            p.erase(temp);
            while (temp1)
            {
                p.insert(temp - 1);
                p.insert(temp - 1);
                nos++;
                temp1--;
            }
        }
        else
            break;
    }
    while (nos < k)
    {
        auto itr = p.begin();
        auto temp = *itr;
        p.erase(itr);
        p.insert(temp - 1);
        p.insert(temp - 1);
        nos++;
    }
    cout << "Yes\n";
    v<ll> ans;
    for (auto itr = p.begin(); itr != p.end(); itr++)
        ans.pb(*itr);
    reverse(ans.begin(), ans.end());
    for (ll i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << "\n";
}