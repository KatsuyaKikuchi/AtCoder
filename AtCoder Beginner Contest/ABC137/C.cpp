#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

string S[100005];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> S[i];
        sort(S[i].begin(), S[i].end());
    }
    sort(S, S + N);
    ll ans = 0;
    ll index = 0;
    while (true)
    {
        ll i = index;
        ll n = 0;
        while (S[i] == S[index] && index < N)
        {
            n++;
            index++;
        }
        ans += (n - 1) * n / 2;
        if (index >= N)
            break;
    }
    cout << ans << endl;
    return 0;
}