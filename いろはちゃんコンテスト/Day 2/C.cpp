#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll H[100005];

int main()
{
    int N;
    cin >> N;
    vector<ll> X;
    REP(i, N)
    {
        cin >> H[i];
        X.push_back(H[i]);
    }
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    REP(i, N)
    {
        int index = lower_bound(X.begin(), X.end(), H[i]) - X.begin();
        cout << index + 1 << endl;
    }
    return 0;
}