#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[200005];
ll B[200005];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    memset(B, 0, sizeof(B));
    REP(i, N)
    {
        int n = N - 1 - i;
        ll m = A[n];
        ll s = 0;
        for (ll j = n; j < N; j += (n + 1))
        {
            s += B[j];
        }

        B[n] = abs(m - (s % 2));
    }
    vector<int> C;
    REP(i, N)
    {
        if (B[i] > 0)
            C.push_back(i + 1);
    }
    cout << C.size() << endl;
    REP(i, C.size())
    {
        cout << C[i] << endl;
    }
    return 0;
}