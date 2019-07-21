#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

bool U[100005];

int main()
{
    ll N;
    cin >> N;
    ll n = N;
    vector<ll> prime;
    FOR(i, 100000, 2)
    {
        if (U[i])
            continue;
        prime.push_back(i);
        for (int j = i; j < 100000; j += i)
            U[j] = true;
    }

    vector<ll> ans;
    int index = 0;
    while (index < prime.size())
    {
        if (N % prime[index] == 0)
        {
            ans.push_back(prime[index]);
            N /= prime[index];
        }
        else
            ++index;
    }
    if (N > 1)
        ans.push_back(N);

    cout << n << ":";
    REP(i, ans.size())
    {
        cout << " " << ans[i];
    }
    cout << endl;

    return 0;
}