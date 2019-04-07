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
    int N;
    cin >> N;
    vector<ll> x;
    REP(i, N)
    {
        cin >> A[i];
        x.push_back(A[i]);
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    REP(i, N)
    {
        cout << lower_bound(x.begin(), x.end(), A[i]) - x.begin() << endl;
    }
    return 0;
}