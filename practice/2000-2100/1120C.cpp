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
#define N 5005
#define mod 1000000007
#define INF INT_MAX

ll n, a, b;
string s;
v<ll> dp(N);

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

vector<long long int> prefix_function(string s, ll ind)
{
    reverse(s.begin(), s.end());
    long long int n = (long long int)s.length();
    vector<long long int> pi(n);
    vector<ll> pi1(n);
    for (long long int i = 1; i < n; i++)
    {
        long long int j = pi[i - 1];
        ll j1 = pi1[i - 1];
        if (j > (i - 1) / 2)
            j = pi1[j - 1];
        while (j > 0 && s[i] != s[j])
        {
            j = pi1[j - 1];
        }
        while (j1 > 0 && s[i] != s[j1])
            j1 = pi1[j1 - 1];
        if (s[i] == s[j])
            j++;
        if (s[i] == s[j1])
            j1++;
        pi[i] = j;
        pi1[i] = j1;
        dp[ind] = min(dp[ind], min(dp[ind - pi[i]] + (a * pi[i]), dp[ind - pi[i]] + b));
    }
    // cout << dp[ind] << " ";
    return pi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> a >> b;
    cin >> s;
    dp[0] = a;
    for (ll i = 1; i < n; i++)
    {
        dp[i] = dp[i - 1] + a;
        prefix_function(s.substr(0, i + 1), i);
    }
    cout << dp[n - 1] << "\n";
}