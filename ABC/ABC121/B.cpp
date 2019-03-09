#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll B[30];

int main()
{
    int N, M, C;
    cin >> N >> M >> C;
    REP(i, M)
    {
        cin >> B[i];
    }
    ll sum = 0;
    REP(i, N)
    {
        int s = 0;
        REP(j, M)
        {
            ll a;
            cin >> a;
            s += a * B[j];
        }
        if (s + C > 0)
            sum++;
    }
    cout << sum << endl;
    return 0;
}