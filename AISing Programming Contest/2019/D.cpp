#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll N, Q;
ll A[100005];
ll X[100005];

//! でかいほうから交互に取った場合の累積和
ll B[100005];
//! 累積和
ll C[100005];

//! 青木がxを選んだ時の高橋の取得点数
ll calc(ll x)
{
    //! 青木が最初にとるindex
    int s = 0;
    {
        int ok = N - 1, ng = -1;
        while (abs(ok - ng) > 1)
        {
            int mid = (ok + ng) / 2;
            if (x <= A[mid])
                ok = mid;
            else
                ng = mid;
        }
        s = ok;
        if (ok - 1 >= 0 && abs(A[ok - 1] - x) <= abs(A[ok] - x))
            s = ok - 1;
    }

    if (s == N - 1)
    {
        //! 青木が最初に取る予定のものが一番大きいなら、どうせ交互になっていく
        return B[N];
    }

    ll sum = 0;
    //! 高橋が連続して取れる個数を求める
    {
        int ok = 1, ng = N / 2 + 1;
        if (N % 2 == 1)
            ng++;
        while (abs(ok - ng) > 1)
        {
            int mid = (ok + ng) / 2;

            //! 高橋が連続して取る最後のindex
            int li = N - mid;
            if (li - s >= mid)
            {
                ok = mid;
                continue;
            }
            if (li <= s)
            {
                ng = mid;
                continue;
            }
            if (abs(A[li - mid + 1] - x) <= abs(A[li] - x))
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }

        //! 高橋はN-1からliまでとり、青木はli-1からli-okまで連続で取る
        //! その後は交互にとっていく
        sum = (C[N] - C[N - ok]) + B[std::max(N - ok - ok, (ll)0)];
    }
    return sum;
}

int main()
{
    cin >> N >> Q;
    B[0] = C[0] = 0;
    REP(i, N)
    {
        cin >> A[i];
        C[i + 1] = A[i];
        C[i + 1] += C[i];
        if (N % 2 != i % 2)
            B[i + 1] = A[i];
        B[i + 1] += B[i];
    }
    REP(i, Q)
    {
        ll x;
        cin >> x;
        X[i] = calc(x);
    }
    REP(i, Q)
    {
        cout << X[i] << endl;
    }
    return 0;
}