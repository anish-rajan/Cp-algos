#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double ld;
#define N 100005
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
string s;
bool is_pal(string s)
{
    bool pos = true;
    ll n = s.size();
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] != s[n - i - 1])
            pos = false;
    }
    return pos;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << 1 << "\n";

    cin >> s;
    ll n = s.size();
    ll temp = n;
    bool pos = false;
    for (ll i = 0; i < n / 2 - 1; i++)
    {
        if (s[i] != s[i + 1])
            pos = true;
    }
    if (pos == false)
    {
        cout << "Impossible\n";
        return 0;
    }
    for (ll i = 1; i < n - 1; i++)
    {
        string t = s.substr(i, n - i) + s.substr(0, i);
        if (t == s)
            continue;
        else if (is_pal(t))
        {
            cout << 1 << "\n";
            return 0;
        }
    }
    cout << 2 << "\n";
    return 0;
}