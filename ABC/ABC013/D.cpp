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
ll X[100005];
pll Y[100005];
bool U[100005];

int main()
{
    ll N, M, D;
    cin >> N >> M >> D;
    REP(i, N)
    {
        A[i] = i;
    }
    REP(i, M)
    {
        int a;
        cin >> a;
        swap(A[a - 1], A[a]);
    }

    REP(i, N)
    {
        if (U[i])
            continue;
        U[i] = true;
        int j = A[i];
        int n = 1;
        for (; A[j] != A[i]; ++n, j = A[j])
            U[j] = true;

        //! s個先が巨大あみだくじの行き着く場所
        int s = D % n;
        j = i;
        while (s-- > 0)
            j = A[j];

        //! X[i]=jである
        int ni = i, nj = j;
        do
        {
            X[ni] = nj;
            ni = A[ni];
            nj = A[nj];
        } while (ni != i);
    }

    REP(i, N)
    {
        Y[i].first = X[i];
        Y[i].second = i + 1;
    }
    sort(Y, Y + N, [](pll a, pll b) { return a.first < b.first; });
    REP(i, N)
    {
        cout << Y[i].second << endl;
    }
    return 0;
}