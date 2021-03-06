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
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<ll> a;
    int d = 0;
    REP(i, N)
    {
        if (S[i] == '(')
            d++;
        else
            d--;

        a.push_back(d);
    }
    sort(a.begin(), a.end(), [](ll a, ll b) { return a > b; });
    ll sum = 0;
    REP(i, K)
    {
        sum += a[i];
    }
    cout << sum << endl;
    return 0;
}