#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[1005][1005];

int main()
{
    ll H, W, D;
    cin >> H >> W >> D;
    ll max = 0;
    REP(i, H)
    {
        REP(j, W)
        {
            ll a;
            cin >> a;
            int s = i + j;
            if (s <= D && s % 2 == D % 2)
                max = std::max(max, a);
        }
    }
    cout << max << endl;
    return 0;
}