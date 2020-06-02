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
#define N 505
#define N1 12
#define N2 100005
#define mod 1000000007
#define INF INT_MAX

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

string makes(ll l, ll r, string s)
{
    string t = s;
    for (ll i = l - 1; i <= r - 1; i++)
        t[i] = '1';
    return t;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    string s;
    for (ll i = 1; i <= n; i++)
        s += '0';
    ll inp, pos0 = 0, pos1 = 0, zerodist;
    cout << "? " << s << endl;
    cin >> inp;
    zerodist = inp;
    s.pop_back();
    s += '1';
    cout << "? " << s << endl;
    cin >> inp;
    s.pop_back();
    s += '0';
    if ((inp - zerodist + 1) / 2 == 0)
        pos1 = n;
    else
        pos0 = n;
    ll l = 1, r = n, lastham = zerodist;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        string temp = makes(l, mid, s);
        cout << "? " << temp << endl;
        cin >> inp;
        ll inp1 = (inp - lastham + (mid - l + 1)) / 2;
        // cout << inp1 << " ";
        if (inp1 == mid - l + 1)
        {
            if (!pos0)
            {
                pos0 = mid;
                break;
            }
            else
            {
                l = mid + 1;
            }
        }
        else if (inp1 == 0)
        {
            if (!pos1)
            {
                pos1 = mid;
                break;
            }
            else
            {
                l = mid + 1;
            }
        }
        else
        {
            r = mid;
        }
        // cout << lastham << " " << s << " " << l << " " << r << endl;
    }
    cout << "! " << pos0 << " " << pos1 << endl;
}