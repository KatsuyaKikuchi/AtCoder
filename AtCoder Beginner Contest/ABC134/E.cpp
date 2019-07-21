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
    std::multiset<ll> st;
    ll ans = 0;
    REP(i, N)
    {
        int n = N - i - 1;
        ll m = A[n];
        auto it = st.lower_bound(m + 1);
        if (it == st.end())
            ans++;
        else
            st.erase(it);
        st.insert(m);
    }
    cout << ans << endl;
    return 0;
}