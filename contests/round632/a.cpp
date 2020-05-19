#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 200005
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
#define UN(v) sort((v).begin(), (v).end()), v.erase(unique(v.begin(), v.end()), v.end())
ll t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        for (ll i = 1; i < n; i++)
        {
            for (ll j = 1; j <= m; j++)
            {
                cout << 'B';
            }
            cout << endl;
        }
        cout << "B";
        for (ll i = 2; i <= m; i++)
        {
            cout << "W";
        }
        cout << endl;
    }
}