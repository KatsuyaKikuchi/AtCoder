#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

bool check(int n)
{
    vector<int> k;
    for (; n > 0; n /= 10)
    {
        k.push_back(n % 10);
    }
    REP(i, k.size())
    {
        if (k[i] != k[k.size() - 1 - i])
            return false;
    }
    return true;
}

int main()
{
    int A, B;
    cin >> A >> B;
    int ans = 0;
    FOR(i, B + 1, A)
    {
        if (check(i))
            ans++;
    }
    cout << ans << endl;
    return 0;
}