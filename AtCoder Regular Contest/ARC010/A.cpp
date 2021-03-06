#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll C[1005];

int main()
{
    ll N, M, A, B;
    cin >> N >> M >> A >> B;
    REP(i, M)
    {
        cin >> C[i];
    }

    REP(i, M)
    {
        if (N <= A)
            N += B;
        N -= C[i];
        if (N < 0)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << "complete" << endl;
    return 0;
}