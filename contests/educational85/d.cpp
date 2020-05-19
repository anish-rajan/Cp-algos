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
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
#define N 505
ll t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        ll n, l, r;
        cin >> n >> l >> r;
        ll moves = (n * (n - 1)) + 1;
        // cout << moves << endl;
        ll f = r == moves ? 1 : 0;
        if (r == moves)
            r--;
        ll s = 1;
        ll pos = n - 1;
        for (ll i = n - 1; i >= 0; i--)
        {
            if (l >= s && l <= s + 2 * i - 1)
            {
                pos = i;
                break;
            }
            s += 2 * i;
        }
        ll no = n - pos;
        ll no1 = (l - s) / 2;
        no1 += no + 1;
        // cout << no << " " << no1 << " " << s << endl;

        for (ll i = l; i <= r; i++)
        {
            if (i % 2 == 1)
            {
                cout << no << " ";
            }
            else
            {
                cout << no1 << " ";
                no1++;
                if (i == s + 2 * (n - no) - 1)
                {
                    s += 2 * (n - no);
                    no++;
                    no1 = no + 1;
                }
            }
        }
        if (f == 1)
            cout << 1;
        cout << "\n";
    }
}