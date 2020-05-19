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
#define N 200005
#define mod 1000000007
#define INF INT64_MAX
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
    for (ll i = 1; i <= t; i++)
    {
        ll r, c;
        cin >> r >> c;
        v<string> wall(r);
        set<char> lets;
        v<ll> let;
        for (ll i = 0; i < r; i++)
        {
            cin >> wall[i];
            for (ll j = 0; j < wall[i].size(); j++)
                lets.insert(wall[i][j]);
        }
        for (auto itr = lets.begin(); itr != lets.end(); itr++)
            let.pb(*itr);
        ll n = let.size();
        v<v<ll>> built(r, v<ll>(c));
        string ans;
        ll poss;
        for (ll i = 0; i < n; i++)
        {
            poss = 0;
            for (ll j = 0; j < let.size(); j++)
            {
                char p = let[j];
                ll f = 1;
                v<v<ll>> temp = built;
                for (ll k = r - 1; k >= 0; k--)
                {
                    for (ll l = 0; l < c; l++)
                    {
                        if (wall[k][l] == p)
                        {
                            if (k != r - 1)
                            {
                                if (temp[k + 1][l] == 1)
                                    temp[k][l] = 1;
                                else
                                    f = 0;
                            }
                            else
                                temp[k][l] = 1;
                        }
                    }
                }
                if (f == 1)
                {
                    poss = 1;
                    ans += p;
                    let.erase(let.begin() + j);
                    built = temp;
                    break;
                }
            }
            if (poss == 0)
                break;
        }
        if (poss == 0)
            cout << "Case #" << i << ": " << -1 << "\n";
        else
            cout << "Case #" << i << ": " << ans << "\n";
    }
}