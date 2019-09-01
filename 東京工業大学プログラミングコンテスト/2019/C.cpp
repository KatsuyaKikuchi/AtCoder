#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[500005];

int main()
{
    ll N, X;
    cin >> N >> X;
    ll x = 0;
    ll n = 0;
    REP(i, N)
    {
        cin >> A[i];
        if (A[i] >= 0)
            x ^= A[i];
        else
            n++;
    }

    bool e = true;
    if (n == 0)
    {
        if (x != X)
            e = false;
    }
    else if (n == 1)
    {
        if ((x ^ X) > X)
            e = false;
        REP(i, N)
        {
            if (A[i] < 0)
                A[i] = (x ^ X);
        }
    }
    else
    {
        ll m = 0;
        REP(i, 40)
        {
            if (((X >> i) & 1) == 1)
                m = i;
        }
        ll a = (((x >> m) & 1) == 1) ? 0 : (1LL << m);
        ll b = (x ^ X) & (~a);
        if (a > X || b > X)
            e = false;
        REP(i, N)
        {
            if (A[i] >= 0)
                continue;
            A[i] = a;
            a = b;
            b = 0;
        }
    }

    if (e)
    {
        REP(i, N)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}