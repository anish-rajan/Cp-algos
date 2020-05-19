#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 1002
#define N1 62 * 62
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
ll t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        v<ll> checked(n);
        checked = {0};
        string s;
        cin >> s;
        ll temp = n / k, temp1;
        ll moves = 0;
        for (ll i = 0; i < k; i++)
        {
            ll max1 = 0;
            v<ll> cnt(27);
            cnt = {0};
            char let = s[i];
            for (ll j = i; j < n; j += k)
            {
                if (!checked[j])
                {
                    checked[j] = 1;
                    cnt[s[j] - 'a']++;
                }
                if (!checked[n - j - 1])
                {
                    checked[n - j - 1] = 1;
                    cnt[s[n - j - 1] - 'a']++;
                }
                if (max1 < cnt[s[j] - 'a'])
                {
                    max1 = cnt[s[j] - 'a'];
                    let = s[j];
                }
                if (max1 < cnt[s[n - j - 1] - 'a'])
                {
                    max1 = cnt[s[n - j - 1] - 'a'];
                    let = s[n - j - 1];
                }
                // cout << j << " " << max1 << "\n";
            }
            for (ll j = i; j < n; j += k)
            {
                if (let != s[j])
                {
                    s[j] = let;
                    moves++;
                }
                if (let != s[n - j - 1])
                {
                    s[n - 1 - j] = let;
                    moves++;
                }
            }
            // cout << s << " " << moves << "\n";
        }
        cout << moves << "\n";
    }
}