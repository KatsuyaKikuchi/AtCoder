#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll N, K;
ll A[200005];
ll F[200005];

bool check(ll n)
{
    ll k = 0;
    REP(i, N)
    {
        if (A[i] * F[i] - n < 0)
            continue;
        ll m = (A[i] * F[i] - n + (F[i] - 1)) / F[i];
        k += m;
    }
    return k <= K;
}

int main()
{
    cin >> N >> K;
    REP(i, N)
    {
        cin >> A[i];
    }
    REP(i, N)
    {
        cin >> F[i];
    }
    sort(A, A + N, [](ll a, ll b) { return a > b; });
    sort(F, F + N);

    ll ok = INF, ng = -1;
    while (abs(ok - ng) > 1)
    {
        ll mid = (ok + ng) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }
    cout << ok << endl;
    return 0;
}