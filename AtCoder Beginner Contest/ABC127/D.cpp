#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

pll B[100005];
int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    REP(i, N)
    {
        cin >> A[i];
    }
    REP(i, M)
    {
        cin >> B[i].first >> B[i].second;
    }
    sort(B, B + M, [](pll a, pll b) { return a.second > b.second; });
    ll index = 0;
    REP(i, N)
    {
        A.push_back(B[index].second);
        if (--B[index].first <= 0)
            index++;
    }
    sort(A.begin(), A.end(), [](ll a, ll b) { return a > b; });
    ll sum = 0;
    REP(i, N)
    {
        sum += A[i];
    }
    cout << sum << endl;
    return 0;
}