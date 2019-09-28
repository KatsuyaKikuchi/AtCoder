#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll N;
ll A[100005];
ll B[100005];
pll C[100005];

string solve(ll n)
{
    ll ok = 0, ng = N + 1;
    while (abs(ok - ng) > 1)
    {
        ll mid = (ok + ng) / 2;
        if (C[mid].first <= n)
            ok = mid;
        else
            ng = mid;
    }

    if (C[ok].second < n)
        return "kame";
    else if (C[ok].second > n)
        return "usagi";
    return "draw";
}

int main()
{
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    REP(i, N)
    {
        cin >> B[i];
    }
    ll m = 0;
    ll t = 0;
    C[0] = pll(0, 0);
    REP(i, N)
    {
        t += A[i];
        m += B[i];
        C[i + 1] = pll(t, m);
    }

    ll Q;
    cin >> Q;
    REP(i, Q)
    {
        ll n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}