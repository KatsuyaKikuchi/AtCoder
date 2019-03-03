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
    int n = 0;
    vector<int> v;
    FOR(i, std::min(A, B) + 1, 1)
    {
        if (A % i == 0 && B % i == 0)
            v.push_back(i);
    }

    cout << v[v.size() - K] << endl;
    return 0;
}