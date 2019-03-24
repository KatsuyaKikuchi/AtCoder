#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int N, M;
int C[205];

void cut(int k)
{
    int T[205];
    REP(i, 2 * N)
    {
        T[i] = C[i];
    }
    if (k == 0)
    {
        REP(i, N)
        {
            T[2 * i] = C[i];
            T[2 * i + 1] = C[i + N];
        }
    }
    else
    {
        FOR(i, 2 * N, k)
        {
            T[i - k] = C[i];
        }
        REP(i, k)
        {
            T[2 * N - k + i] = C[i];
        }
    }

    REP(i, 2 * N)
    {
        C[i] = T[i];
    }
}

int main()
{
    cin >> N >> M;
    REP(i, 2 * N)
    {
        C[i] = i + 1;
    }
    REP(i, M)
    {
        int k;
        cin >> k;
        cut(k);
    }

    REP(i, 2 * N)
    {
        cout << C[i] << endl;
    }
    return 0;
}