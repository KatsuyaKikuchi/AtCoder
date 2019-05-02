#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll gcd(ll a, ll b)
{
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

bool M[270000];

int main()
{
    ll A, B;
    cin >> A >> B;
    vector<ll> o, e;
    FOR(i, B + 1, A)
    {
        if (i % 2LL == 0)
            e.push_back(i);
        else
            o.push_back(i);
    }
    memset(M, 0, sizeof(M));
    ll p = pow(2LL, o.size());
    ll ans = 0;
    REP(i, p)
    {
        bool t = true;
        for (ll j = o.size() - 1; j >= 0; --j)
        {
            if (((1LL << j) & i) == 0)
                continue;
            if (!M[(~(1LL << j)) & i])
            {
                t = false;
                break;
            }
            REP(k, j)
            {
                if (((1LL << k) & i) == 0)
                    continue;
                if (gcd(o[j], o[k]) > 1)
                {
                    t = false;
                    break;
                }
            }
            break;
        }
        M[i] = t;
        if (t)
            ans++;
    }

    REP(i, p)
    {
        if (!M[i])
            continue;
        REP(j, e.size())
        {
            bool f = true;
            REP(k, o.size())
            {
                if (((1LL << k) & i) == 0)
                    continue;
                if (gcd(e[j], o[k]) > 1)
                {
                    f = false;
                    break;
                }
            }
            if (f)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}