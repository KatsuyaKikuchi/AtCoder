#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll N, M, K;
ll A[100005], B[100005];
bool U[100005];

//! 実力差nのチームが組めるか
bool check(ll n)
{
    memset(U, 0, sizeof(U));
    int num = 0;
    REP(i, N)
    {
        //! A[i]-n以上で最小のBのindexを見つける
        ll ok = M, ng = -1;
        while (abs(ok - ng) > 1)
        {
            ll mid = (ok + ng) / 2;
            if (B[mid] >= A[i] - n && !U[mid])
                ok = mid;
            else
                ng = mid;
        }

        if (ok < M && B[ok] <= A[i] + n)
        {
            num++;
            U[ok] = true;
        }
    }
    return num >= K;
}

int main()
{
    cin >> N >> M >> K;
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

    ll ok = 1e9, ng = -1;
    while (abs(ok - ng) > 1)
    {
        ll mid = (ok + ng) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }
    cout << ok << endl;
    return 0;
}