#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll N, M;
ll A[305][305];
ll B[305];
ll C[305];
bool U[305];

bool solve(ll n)
{
    memset(B, 0, sizeof(B));
    memset(U, 0, sizeof(U));
    while (true)
    {
        memset(C, 0, sizeof(C));
        REP(i, N)
        {
            C[A[i][B[i]]]++;
        }
        bool e = true;
        REP(i, M)
        {
            if (C[i] > n)
            {
                U[i] = true;
                e = false;
            }
        }
        if (e)
            return true;
        REP(i, N)
        {
            while (B[i] < M && U[A[i][B[i]]])
                B[i]++;
            if (B[i] >= M)
                return false;
        }
    }
    return false;
}

int main()
{
    cin >> N >> M;
    REP(i, N)
    {
        REP(j, M)
        {
            cin >> A[i][j];
            A[i][j]--;
        }
    }

    ll ok = N, ng = 0;
    while (abs(ok - ng) > 1)
    {
        ll mid = (ok + ng) / 2;
        if (solve(mid))
            ok = mid;
        else
            ng = mid;
    }
    cout << ok << endl;
    return 0;
}