#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[300005];
//! 引かれる数がN+iの時の最大値
ll S[100005];

int main()
{
    ll N;
    cin >> N;
    REP(i, 3 * N)
    {
        cin >> A[i];
    }
    priority_queue<ll, vector<ll>, function<bool(ll, ll)>> q0([](ll a, ll b) { return a > b; });
    priority_queue<ll, vector<ll>, function<bool(ll, ll)>> q1([](ll a, ll b) { return a < b; });
    ll fs = 0, bs = 0;
    REP(i, N)
    {
        q0.push(A[i]);
        q1.push(A[3 * N - 1 - i]);
        fs += A[i];
        bs += A[3 * N - 1 - i];
        S[i] = 0;
    }
    S[0] = fs;
    S[N] = -bs;

    FOR(i, N + 1, 1)
    {
        {
            ll t = q0.top();
            q0.pop();
            fs -= t;
            t = std::max(t, A[N - 1 + i]);
            fs += t;
            q0.push(t);
            S[i] += fs;
        }
        {
            ll t = q1.top();
            q1.pop();
            bs -= t;
            t = std::min(t, A[2 * N - i]);
            bs += t;
            q1.push(t);
            S[N - i] -= bs;
        }
    }

    ll max = -INF;
    REP(i, N + 1)
    {
        max = std::max(max, S[i]);
    }
    cout << max << endl;
    return 0;
}