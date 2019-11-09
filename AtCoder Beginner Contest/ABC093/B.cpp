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
    ll A, B, K;
    cin >> A >> B >> K;
    vector<ll> ans;
    REP(i, K)
    {
        if (A + i <= B)
            ans.push_back(A + i);
        if (B - i >= A)
            ans.push_back(B - i);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    REP(i, ans.size())
    {
        cout << ans[i] << endl;
    }
    return 0;
}