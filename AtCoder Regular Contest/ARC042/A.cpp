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
bool U[100005];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, M)
    {
        cin >> A[i];
    }
    vector<ll> v;
    for (int i = M - 1; i >= 0; --i)
    {
        if (U[A[i]])
            continue;
        U[A[i]] = true;
        v.push_back(A[i]);
    }
    FOR(i, N + 1, 1)
    {
        if (U[i])
            continue;
        v.push_back(i);
    }
    REP(i, v.size())
    {
        cout << v[i] << endl;
    }
    return 0;
}