#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int main()
{
    string S, T;
    cin >> S >> T;
    int N = S.length();
    vector<ll> dp;
    dp.push_back(-1);
    REP(i, N + 1)
    {
        dp.push_back(INF);
    }
    REP(i, N)
    {
        vector<ll> dpt = dp;
        REP(j, N)
        {
            if (S[i] != T[j])
                continue;

            int index = lower_bound(dp.begin(), dp.end(), j) - dp.begin();
            dpt[index] = std::min(j, dpt[index]);
        }
        swap(dp, dpt);
    }
    cout << lower_bound(dp.begin(), dp.end(), INF) - dp.begin() << endl;
    return 0;
}