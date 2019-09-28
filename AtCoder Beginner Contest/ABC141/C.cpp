#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[100005];
ll M[100005];

int main()
{
    ll N, K, Q;
    cin >> N >> K >> Q;
    memset(M, 0, sizeof(M));
    REP(i, Q)
    {
        cin >> A[i];
        M[A[i] - 1]++;
    }

    REP(i, N)
    {
        if (K - (Q - M[i]) > 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}