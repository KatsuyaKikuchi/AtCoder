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

bool check(ll n)
{
    ll m = 1;
    ll k = 0;
    FOR(i, N, 1)
    {
        if (A[i] == A[i - 1])
            m++;
        else
            m = 1;
        if (m > n)
        {
            i++;
            m = 1;
            k++;
        }
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

    ll ok = N, ng = 0;
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