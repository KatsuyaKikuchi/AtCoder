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
ll B[100005];
ll C[100005];

int main()
{
    ll N;
    cin >> N;
    REP(i, N)
    {
        cin >> A[i];
    }
    ll max = 0;

    REP(i, N)
    {
        B[i] = A[i] - A[(N + i - 1) % N];
        max = std::max(max, B[i]);
    }
    //! A[i]はmax回の操作で似たものを作れる
    REP(i, N)
    {
        ll k = (B[i] + (N - 1) * max) / N;
        C[i] = max - k;
    }
    //! C[i]にはA[i]が何回1から始まったかが入っている
    //! C[0]をとりあえず求める
    FOR(i, N, 1)
    {
        C[0] += (N + 1 - i) * C[i];
    }
    FOR(i, N, 1)
    {
        C[i] = C[i - 1] + (max - C[i]) - (N - 1) * C[i];
    }

    string ans = "YES";
    REP(i, N)
    {
        if (A[i] < C[i])
        {
            ans = "NO";
            break;
        }
        if ((A[i] - C[i]) % (N * (N + 1) / 2) != 0)
        {
            ans = "NO";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}