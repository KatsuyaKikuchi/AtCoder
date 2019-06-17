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

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    sort(A, A + N);
    ll m = 0;
    vector<pll> ans;

    if (A[0] * A[N - 1] < 0)
    {
        //! 絶対値の和になる
        REP(i, N)
        {
            m += abs(A[i]);
        }

        vector<ll> x, y;
        REP(i, N)
        {
            if (A[i] >= 0)
                x.push_back(A[i]);
            else
                y.push_back(A[i]);
        }

        ll P = x[x.size() - 1];
        ll M = y[y.size() - 1];
        x.pop_back();
        y.pop_back();
        REP(i, x.size())
        {
            ans.push_back(pll(M, x[i]));
            M -= abs(x[i]);
        }
        REP(i, y.size())
        {
            ans.push_back(pll(P, y[i]));
            P += abs(y[i]);
        }
        ans.push_back(pll(P, M));
    }
    else
    {
        ll min = INF;
        REP(i, N)
        {
            m += abs(A[i]);
            min = std::min(min, abs(A[i]));
        }
        m -= 2 * min;
        ll s = A[0];
        if (A[0] < 0)
        {
            s = A[N - 1];
            REP(i, N - 1)
            {
                ans.push_back(pll(s, A[i]));
                s += abs(A[i]);
            }
        }
        else
        {
            REP(i, N - 2)
            {
                ans.push_back(pll(s, A[N - 1 - i]));
                s -= abs(A[N - i - 1]);
            }
            ans.push_back(pll(A[1], s));
        }
    }

    cout << m << endl;
    REP(i, N - 1)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}