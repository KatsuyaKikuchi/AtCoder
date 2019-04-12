#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int S[105];
bool U[105];

int main()
{
    int N, M;
    cin >> N >> M;
    memset(S, 0, sizeof(S));
    REP(i, N)
    {
        REP(j, M)
        {
            int a;
            cin >> a;
            S[j + 1] += a;
        }
    }

    REP(i, M)
    {
        int t = 0;
        FOR(j, M + 1, 1)
        {
            if (U[j])
                continue;
            if (S[j] > S[t])
                t = j;
        }
        cout << t;
        U[t] = true;
        if (i < M - 1)
            cout << " ";
    }
    cout << endl;
    return 0;
}