#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[1005];

int main()
{
    ll N, K;
    cin >> N >> K;
    REP(i, N)
    {
        cin >> A[i];
    }
    vector<ll> v;
    REP(i, N)
    {
        ll s = 0;
        FOR(j, N, i)
        {
            s += A[j];
            v.push_back(s);
        }
    }

    for (int n = 60; n >= 0; --n)
    {
        vector<ll> t;
        REP(i, v.size())
        {
            if (((v[i] >> n) & 1) == 1)
                t.push_back(v[i]);
        }

        if (t.size() >= K)
            v = t;
    }

    ll ans = v[0];
    REP(i, v.size())
    {
        ans &= v[i];
    }
    cout << ans << endl;
    return 0;
}