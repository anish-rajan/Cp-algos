#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
typedef int ll;
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
#define N 35
#define mod 1000000009
#define INF INT64_MAX

//////////////////////////IMPORTANT FUNCTIONS/////////////////////////////////////////////

/* Guidlines berfore submitting solution
1. Check N value before submitting
2. Check all constant kind of values you are using. Might give WA. Think
3. Check mod value
*/

// v<ll> fact(N);
// v<ll> prime_check(1e7 + 2);
// v<ll> primes;

// long long powmod(long long x, long long y, long long m)
// {
//     long long res = 1LL;
//     while (y)
//     {
//         if (y & 1)
//             res = (res * x) % m;
//         x = (x * x) % m;
//         y /= 2;
//     }
//     return res;
// }

// void init_fact()
// {
//     fact[0] = 1;
//     for (ll i = 1; i < N; i++)
//     {
//         fact[i] = (fact[i - 1] * i) % mod;
//     }
// }

// ll C(ll n, ll r)
// {
//     if (n < r)
//         return 0;
//     ll temp = fact[n] * powmod(fact[r], mod - 2, mod) % mod;
//     temp *= powmod(fact[n - r], mod - 2, mod);
//     temp %= mod;
//     return temp;
// }

// void Sieve()
// {
//     for (ll i = 2; i <= 1e7 + 1; i++)
//     {
//         if (prime_check[i])
//             continue;
//         primes.pb(i);
//         for (ll j = 2 * i; j <= 1e7 + 1; j += i)
//             prime_check[j] = i;
//     }
// }
// ll phi(ll n)
// {
//     ll i, res = n;
//     for (i = 2; i * i <= n; i++)
//         if (n % i == 0)
//         {
//             while (n % i == 0)
//                 n /= i;
//             res -= res / i;
//         }
//     if (n > 1)
//         res -= res / n;
//     return res;
// }

struct Int
{
    static const int base = 1000000000;
    static const int BaseDigit = 9;
    vector<int> a;
    int sign;
    int size()
    {
        if (a.empty())
            return 0;
        int ans = (a.size() - 1) * BaseDigit;
        int ca = a.back();
        while (ca)
            ans++, ca /= 10;
        return ans;
    }
    Int operator^(const Int &vv)
    {
        Int ans = 1, aa = *this, b = vv;
        while (!b.isZero())
        {
            if (b % 2)
                ans *= aa;
            aa *= aa, b /= 2;
        }
        return ans;
    }
    string to_string()
    {
        stringstream ss;
        ss << *this;
        string s;
        ss >> s;
        return s;
    }
    int sumof()
    {
        string s = to_string();
        int ans = 0;
        for (auto c : s)
            ans += c - '0';
        return ans;
    }
    Int() : sign(1)
    {
    }
    Int(long long vv)
    {
        *this = vv;
    }
    Int(const string &s)
    {
        read(s);
    }
    void operator=(const Int &vv)
    {
        sign = vv.sign;
        a = vv.a;
    }
    void operator=(long long vv)
    {
        sign = 1;
        a.clear();
        if (vv < 0)
            sign = -1, vv = -vv;
        for (; vv > 0; vv = vv / base)
            a.push_back(vv % base);
    }
    Int operator+(const Int &vv) const
    {
        if (sign == vv.sign)
        {
            Int res = vv;
            for (int i = 0, carry = 0; i < (int)max(a.size(), vv.a.size()) || carry; ++i)
            {
                if (i == (int)res.a.size())
                    res.a.push_back(0);
                res.a[i] += carry + (i < (int)a.size() ? a[i] : 0);
                carry = res.a[i] >= base;
                if (carry)
                    res.a[i] -= base;
            }
            return res;
        }
        return *this - (-vv);
    }
    Int operator-(const Int &vv) const
    {
        if (sign == vv.sign)
        {
            if (abs() >= vv.abs())
            {
                Int res = *this;
                for (int i = 0, carry = 0; i < (int)vv.a.size() || carry; ++i)
                {
                    res.a[i] -= carry + (i < (int)vv.a.size() ? vv.a[i] : 0);
                    carry = res.a[i] < 0;
                    if (carry)
                        res.a[i] += base;
                }
                res.trim();
                return res;
            }
            return -(vv - *this);
        }
        return *this + (-vv);
    }
    void operator*=(int vv)
    {
        if (vv < 0)
            sign = -sign, vv = -vv;
        for (int i = 0, carry = 0; i < (int)a.size() || carry; ++i)
        {
            if (i == (int)a.size())
                a.push_back(0);
            long long cur = a[i] * (long long)vv + carry;
            carry = (int)(cur / base);
            a[i] = (int)(cur % base);
        }
        trim();
    }

    Int operator*(int vv) const
    {
        Int res = *this;
        res *= vv;
        return res;
    }
    void operator*=(long long vv)
    {
        if (vv < 0)
            sign = -sign, vv = -vv;
        for (int i = 0, carry = 0; i < (int)a.size() || carry; ++i)
        {
            if (i == (int)a.size())
                a.push_back(0);
            long long cur = a[i] * (long long)vv + carry;
            carry = (int)(cur / base);
            a[i] = (int)(cur % base);
        }
        trim();
    }
    Int operator*(long long vv) const
    {
        Int res = *this;
        res *= vv;
        return res;
    }
    friend pair<Int, Int> divmod(const Int &a1, const Int &b1)
    {
        int norm = base / (b1.a.back() + 1);
        Int a = a1.abs() * norm;
        Int b = b1.abs() * norm;
        Int q, r;
        q.a.resize(a.a.size());
        for (int i = a.a.size() - 1; i >= 0; i--)
        {
            r *= base;
            r += a.a[i];
            int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            int d = ((long long)base * s1 + s2) / b.a.back();
            r -= b * d;
            while (r < 0)
                r += b, --d;
            q.a[i] = d;
        }
        q.sign = a1.sign * b1.sign;
        r.sign = a1.sign;
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }
    Int operator/(const Int &vv) const
    {
        return divmod(*this, vv).first;
    }
    Int operator%(const Int &vv) const
    {
        return divmod(*this, vv).second;
    }
    void operator/=(int vv)
    {
        if (vv < 0)
            sign = -sign, vv = -vv;
        for (int i = (int)a.size() - 1, rem = 0; i >= 0; --i)
        {
            long long cur = a[i] + rem * (long long)base;
            a[i] = (int)(cur / vv);
            rem = (int)(cur % vv);
        }
        trim();
    }
    Int operator/(int vv) const
    {
        Int res = *this;
        res /= vv;
        return res;
    }

    int operator%(int vv) const
    {
        if (vv < 0)
            vv = -vv;
        int m = 0;
        for (int i = a.size() - 1; i >= 0; --i)
            m = (a[i] + m * (long long)base) % vv;
        return m * sign;
    }
    void operator+=(const Int &vv)
    {
        *this = *this + vv;
    }
    void operator-=(const Int &vv)
    {
        *this = *this - vv;
    }
    void operator*=(const Int &vv)
    {
        *this = *this * vv;
    }
    void operator/=(const Int &vv)
    {
        *this = *this / vv;
    }
    Int operator++()
    {
        *this += 1;
        return *this;
    }
    Int operator++(int)
    {
        Int temp = *this;
        *this += 1;
        return temp;
    }
    Int operator--()
    {
        *this -= 1;
        return *this;
    }
    Int operator--(int)
    {
        Int temp = *this;
        *this -= 1;
        return temp;
    }
    bool operator<(const Int &vv) const
    {
        if (sign != vv.sign)
            return sign < vv.sign;
        if (a.size() != vv.a.size())
            return a.size() * sign < vv.a.size() * vv.sign;
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != vv.a[i])
                return a[i] * sign < vv.a[i] * sign;
        return false;
    }
    bool operator>(const Int &vv) const
    {
        return vv < *this;
    }
    bool operator<=(const Int &vv) const
    {
        return !(vv < *this);
    }
    bool operator>=(const Int &vv) const
    {
        return !(*this < vv);
    }
    bool operator==(const Int &vv) const
    {
        return !(*this < vv) && !(vv < *this);
    }
    bool operator!=(const Int &vv) const
    {
        return *this < vv || vv < *this;
    }
    void trim()
    {
        while (!a.empty() && !a.back())
            a.pop_back();
        if (a.empty())
            sign = 1;
    }
    bool isZero() const
    {
        return a.empty() || (a.size() == 1 && !a[0]);
    }
    Int operator-() const
    {
        Int res = *this;
        res.sign = -sign;
        return res;
    }
    Int abs() const
    {
        Int res = *this;
        res.sign *= res.sign;
        return res;
    }
    long long longValue() const
    {
        long long res = 0;
        for (int i = a.size() - 1; i >= 0; i--)
            res = res * base + a[i];
        return res * sign;
    }
    friend Int gcd(const Int &a, const Int &b)
    {
        return b.isZero() ? a : gcd(b, a % b);
    }
    friend Int lcm(const Int &a, const Int &b)
    {
        return a / gcd(a, b) * b;
    }
    void read(const string &s)
    {
        sign = 1;
        a.clear();
        int pos = 0;
        while (pos < (int)s.size() && (s[pos] == '-' || s[pos] == '+'))
        {
            if (s[pos] == '-')
                sign = -sign;
            ++pos;
        }
        for (int i = s.size() - 1; i >= pos; i -= BaseDigit)
        {
            int x = 0;
            for (int j = max(pos, i - BaseDigit + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }
    friend istream &operator>>(istream &stream, Int &vv)
    {
        string s;
        stream >> s;
        vv.read(s);
        return stream;
    }
    friend ostream &operator<<(ostream &stream, const Int &vv)
    {
        if (vv.sign == -1)
            stream << '-';
        stream << (vv.a.empty() ? 0 : vv.a.back());
        for (int i = (int)vv.a.size() - 2; i >= 0; --i)
            stream << setw(BaseDigit) << setfill('0') << vv.a[i];
        return stream;
    }
    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits)
    {
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int)p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int)a.size(); i++)
        {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits)
            {
                res.push_back(int(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int)cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }
    typedef vector<long long> vll;
    static vll karatsubaMultiply(const vll &a, const vll &b)
    {
        int n = a.size();
        vll res(n + n);
        if (n <= 32)
        {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }
        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());
        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);
        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];
        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int)a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (int i = 0; i < (int)a2b2.size(); i++)
            r[i] -= a2b2[i];
        for (int i = 0; i < (int)r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < (int)a1b1.size(); i++)
            res[i] += a1b1[i];
        for (int i = 0; i < (int)a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }
    Int operator*(const Int &vv) const
    {
        vector<int> a6 = convert_base(this->a, BaseDigit, 6);
        vector<int> b6 = convert_base(vv.a, BaseDigit, 6);

        vll a(a6.begin(), a6.end());
        vll b(b6.begin(), b6.end());

        while (a.size() < b.size())
            a.push_back(0);
        while (b.size() < a.size())
            b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);
        vll c = karatsubaMultiply(a, b);
        Int res;
        res.sign = sign * vv.sign;
        for (int i = 0, carry = 0; i < (int)c.size(); i++)
        {
            long long cur = c[i] + carry;
            res.a.push_back((int)(cur % 1000000));
            carry = (int)(cur / 1000000);
        }
        res.a = convert_base(res.a, 6, BaseDigit);
        res.trim();
        return res;
    }
    friend Int max(const Int &a, const Int &b)
    {
        if (a < b)
        {
            return a;
        }
        return b;
    }
    friend Int max(const Int &a, const int32_t &B)
    {
        Int b = B;
        return max(a, b);
    }
    friend Int max(const Int &a, const int64_t &B)
    {
        Int b = B;
        return max(a, b);
    }
    friend Int min(const Int &a, const Int &b)
    {
        if (a > b)
        {
            return b;
        }
        return a;
    }
    friend Int min(const Int &a, const int32_t &B)
    {
        Int b = B;
        return min(a, b);
    }
    friend Int min(const Int &a, const int64_t &B)
    {
        Int b = B;
        return min(a, b);
    }
    friend Int pow(const Int &a, const Int &b)
    {
        Int c = 1;
        for (Int i = 1; i <= b; i += 1)
        {
            c *= a;
        }
        return c;
    }
    friend Int pow(const Int &a, const int32_t &B)
    {
        Int b = B;
        return pow(a, b);
    }
    friend Int pow(const Int &a, const int64_t &B)
    {
        Int b = B;
        return pow(a, b);
    }
    friend Int sqrt(Int a)
    {
        Int x0 = a, x1 = (a + 1) / 2;
        while (x1 < x0)
        {
            x0 = x1;
            x1 = (x1 + a / x1) / 2;
        }
        return x0;
    }
};

/////////////////////////////////////START CODE HERE/////////////////////////////////////////////

Int n, p;
ll m, masksz;

void multiply(Int **a, Int **b)
{
    Int mul[masksz][masksz];
    for (ll i = 0; i < masksz; i++)
    {
        for (ll j = 0; j < masksz; j++)
        {
            mul[i][j] = 0;
            for (ll k = 0; k < 3; k++)
                mul[i][j] += a[i][k] * b[k][j];
        }
    }

    for (ll i = 0; i < masksz; i++)
        for (ll j = 0; j < masksz; j++)
            a[i][j] = mul[i][j];
}

Int power(Int **F, Int **M, Int n)
{

    if (n == 1)
        return F[0][0] + F[0][1];

    power(F, M, n / 2);

    multiply(F, F);

    if (n % 2 != 0)
        multiply(F, M);

    return F[0][0] + F[0][1];
}

bool checkcnt(ll x, ll type)
{
    ll last = -1;
    while (m--)
    {
        ll temp = x % 2;
        if (last == temp && last == type)
            return false;
        last = temp;
        x /= 2;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);
    // init_fact();
    // Sieve();
    cin >> n >> m >> p;
    masksz = (1LL << m);
    Int s = m ^ 1;
    v<Int> a[masksz];
    for (ll i = 0; i < masksz; i++)
    {
        for (ll j = 0; j < masksz; j++)
        {
            if (checkcnt(i | j, 0) && checkcnt(i & j, 1))
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }
}