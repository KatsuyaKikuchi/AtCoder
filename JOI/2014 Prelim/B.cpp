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
ll B[1005];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, N)
    {
        cin >> A[i];
    }
    REP(i, M)
    {
        ll a;
        cin >> a;
        REP(j, N)
        {
            if (A[j] <= a)
            {
                B[j]++;
                break;
            }
        }
    }

    ll ans = 0;
    REP(i, N)
    {
        if (B[ans] < B[i])
            ans = i;
    }
    cout << ans + 1 << endl;
    return 0;
}