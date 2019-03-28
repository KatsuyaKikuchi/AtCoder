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
ll B[100005];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, N)
    {
        cin >> A[i];
    }
    REP(i, M)
    {
        cin >> B[i];
    }
    sort(A, A + N);
    sort(B, B + M);
    int ai = 0, bi = 0;
    A[N] = INF;
    B[M] = INF;
    ll p = 0, q = 0;
    while (ai < N || bi < M)
    {
        if (A[ai] < B[bi])
        {
            q++;
            ai++;
        }
        else if (A[ai] > B[bi])
        {
            q++;
            bi++;
        }
        else
        {
            p++;
            q++;
            ai++;
            bi++;
        }
    }
    cout << OF64 << (double)p / (double)q << endl;
    return 0;
}