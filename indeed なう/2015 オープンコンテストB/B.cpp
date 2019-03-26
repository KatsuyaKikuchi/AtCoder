#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

struct Time
{
    ll s;
    ll t;
    int i;
};

Time T[100005];
int C[100005];

int main()
{
    int N;
    cin >> N;
    REP(i, N)
    {
        cin >> T[i].s >> T[i].t;
        T[i].i = i;
        C[i] = 0;
    }
    sort(T, T + N, [](Time a, Time b) { return a.s > b.s; });
    REP(i, N)
    {
        Time t = T[i];
        int ok = i, ng = -1;
        while (abs(ok - ng) > 1)
        {
            ll mid = (ok + ng) / 2;
            if (T[mid].s < t.t)
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }
        C[t.i] = i - ok;
    }
    REP(i, N)
    {
        cout << C[i] << endl;
    }
    return 0;
}