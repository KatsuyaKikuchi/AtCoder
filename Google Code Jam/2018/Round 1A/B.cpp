#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = 9223372036854775806LL;

struct Cashier
{
    ll M;
    ll S;
    ll P;
};

ll R, C, B;
Cashier D[1005];

bool check(ll t)
{
    priority_queue<ll, vector<ll>> q;
    REP(i, C)
    {
        ll n = std::min(D[i].M, std::max(0LL, t - D[i].P) / D[i].S);
        q.push(n);
    }

    ll sum = 0;
    REP(i, R)
    {
        sum += q.top();
        q.pop();
    }
    return sum >= B;
}

int main()
{
    int T;
    cin >> T;
    REP(t, T)
    {
        cin >> R >> B >> C;
        REP(i, C)
        {
            cin >> D[i].M >> D[i].S >> D[i].P;
        }

        ll ok = INF, ng = 0;
        while (abs(ok - ng) > 1)
        {
            ll mid = (ok + ng) / 2;
            if (check(mid))
                ok = mid;
            else
                ng = mid;
        }

        cout << "Case #" << t + 1 << ": " << ok << endl;
    }
    return 0;
}