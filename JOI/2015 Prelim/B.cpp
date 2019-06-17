#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[105];
ll X[105];

int main()
{
    memset(X, 0, sizeof(X));
    ll N, M;
    cin >> N >> M;
    REP(i, M)
    {
        cin >> A[i];
        A[i]--;
    }
    REP(i, M)
    {
        ll t = 0;
        REP(j, N)
        {
            int b;
            cin >> b;
            b--;
            if (A[i] == b)
                X[j]++;
            else
                t++;
        }
        X[A[i]] += t;
    }
    REP(i, N)
    {
        cout << X[i] << endl;
    }
    return 0;
}