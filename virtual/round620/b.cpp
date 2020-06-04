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
#define N 100005
#define mod 1000000007
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

v<ll> fact(N);

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

void init_fact()
{
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

ll C(ll n, ll r)
{
    if (n < r)
        return 0;
    ll temp = fact[n] * powmod(fact[r], mod - 2, mod) % mod;
    temp *= powmod(fact[n - r], mod - 2, mod);
    temp %= mod;
    return temp;
}

/////////////////////////////////////START CODE HERE////////////////////////////////////////////
ll n, m;
map<string, ll> a;
v<string> b;
v<ll> marked(102);

string pal(string s)
{
    for (ll i = 0; i < s.size() / 2; i++)
    {
        char temp = s[i];
        s[i] = s[s.size() - i - 1];
        s[s.size() - i - 1] = temp;
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // init_fact();
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        a[s] = i - 1;
        b.pb(s);
    }
    ll count = 0;
    string ans;
    for (ll i = 0; i < n; i++)
    {
        string p = pal(b[i]);
        if (p != b[i] && !marked[a[b[i]]])
        {
            if (a.find(p) != a.end())
                count++, marked[a[b[i]]] = 1, marked[a[p]] = 1, ans += b[i];
        }
    }
    string ans1;
    count *= 2;
    // cout << ans << "\n";
    for (ll i = ans.size() - m; i >= 0; i -= m)
    {
        // cout << pal(ans.substr(i, m)) << " ";
        ans1 += pal(ans.substr(i, m));
    }
    for (ll i = 0; i < n; i++)
    {
        if (pal(b[i]) == b[i])
        {
            count++;
            ans += b[i];
            break;
        }
    }
    ans += ans1;
    cout << count * m << "\n";
    cout << ans << "\n";
}