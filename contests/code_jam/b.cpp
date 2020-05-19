#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define N 102
ll t;
string comp(string s, string s1, ll i1, ll i2)
{
    string ans;
    ll n = i2 - i1;
    if (n == 0)
    {
        ans += s1[i1];
        return ans;
    }
    for (ll i = i1; i < i2;)
    {
        ll j = i;
        while (j < i2)
        {
            if (s[j] == '0')
                break;
            else
            {
                s[j]--;
                j++;
            }
        }
        // cout << i << " " << j << "\n";
        if (i != j)
        {
            ans += "(" + comp(s, s1, i, j) + ")";
            i = j;
        }
        else
        {
            ans += comp(s, s1, i, j);
            i = j + 1;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        string s;
        cin >> s;
        ll n = s.size();
        string ans = comp(s, s, 0, n);
        cout << "Case #" << i + 1 << ": " << ans << endl;
    }
}