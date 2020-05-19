#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define N 200005
#define N1 62 * 62
#define mp make_pair
#define v vector
#define pb push_back
#define fi first
#define se second
#define ALL(v) v.begin(), v.end()
ll k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> k;
    ll temp = (ll)log2(k);
    ll temp1 = (ll)pow(2, temp + 1);
    if (k == 0)
    {
        cout << 1 << " " << 1 << "\n";
        cout << 300 << "\n";
    }
    else
    {
        cout << 3 << " " << 3 << "\n";
        cout << temp1 + k << " " << temp1 << " " << temp1 << "\n";
        cout << k << " " << temp1 << " " << temp1 << "\n";
        cout << k << " " << temp1 + k << " " << k << "\n";
    }
}