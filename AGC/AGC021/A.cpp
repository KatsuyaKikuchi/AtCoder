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
    ll N;
    cin >> N;
    vector<int> v;
    while (N > 0)
    {
        v.push_back(N % 10);
        N /= 10;
    }

    int max = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        int sum = 0;
        REP(j, v.size())
        {
            sum += v[j];
        }
        v[i] = 9;
        if (i + 1 < v.size())
            v[i + 1]--;
        max = std::max(max, sum);
    }
    cout << max << endl;
    return 0;
}