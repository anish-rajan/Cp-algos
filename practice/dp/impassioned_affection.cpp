#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll q;
    cin >> q;
    while (q--)
    {
        ll m;
        cin >> m;
        char c;
        cin >> c;

        ll ans = m;
        ll i = 0, j = 0, counter = m, cnt = 0;
        while (i < n && j < n)
        {
            while (counter > 0 && j < n)
            {
                if (s[j] != c)
                {
                    counter--;
                }
                j++;
            }
            while (s[j] == c)
                j++;
            ans = max(ans, j - i);
            if (s[i] != c)
                counter++;
            i++;
        }
        cout << ans << "\n";
    }
}