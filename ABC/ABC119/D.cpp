#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A, B, Q;
ll S[100005];
ll T[100005];

ll solve(ll x)
{
    //! x以上の神社の最大index
    int s = A, us = -1;
    while (abs(us - s) > 1)
    {
        int mid = (s + us) / 2;
        if (S[mid] >= x)
            s = mid;
        else
            us = mid;
    }

    //! x以上の寺の最大index
    int t = B, ut = -1;
    while (abs(ut - t) > 1)
    {
        int mid = (t + ut) / 2;
        if (T[mid] >= x)
            t = mid;
        else
            ut = mid;
    }

    ll min = INF;
    //! t,t-1,s,s-1を訪れる組み合わせで一番距離が短いもの
    for (int i = 0; i <= 1; ++i)
    {
        for (int j = 0; j <= 1; ++j)
        {
            //! 神社index
            int si = std::min(std::max(0, s - i), (int)A - 1);
            int ti = std::min(std::max(0, t - j), (int)B - 1);
            //! 寺→神社の順番
            ll sum0 = abs(S[si] - x) + abs(T[ti] - S[si]);
            ll sum1 = abs(T[ti] - x) + abs(S[si] - T[ti]);
            min = std::min(min, std::min(sum0, sum1));
        }
    }
    return min;
}

int main()
{
    cin >> A >> B >> Q;
    REP(i, A)
    {
        cin >> S[i];
    }
    S[A] = INF;
    REP(i, B)
    {
        cin >> T[i];
    }
    T[B] = INF;
    REP(i, Q)
    {
        ll x;
        cin >> x;
        cout << solve(x) << endl;
    }
    return 0;
}