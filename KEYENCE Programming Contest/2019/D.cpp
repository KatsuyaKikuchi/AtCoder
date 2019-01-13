#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll A[1005];
ll B[1005];

//! Nを置ける場所が何通りあるか
ll T[1000005];
ll Map[1005][1005];
//! 場所が決まっている
bool S[1000005];

int main()
{
    int N, M;
    cin >> N >> M;
    REP(i, N)
    {
        cin >> A[i];
    }
    REP(i, M)
    {
        cin >> B[i];
    }

    bool same = false;
    REP(i, N)
    {
        FOR(j, N, i + 1)
        {
            if (A[i] == A[j])
                same = true;
        }
    }
    REP(i, M)
    {
        FOR(j, M, i + 1)
        {
            if (B[i] == B[j])
                same = true;
        }
    }
    if (same)
    {
        cout << 0 << endl;
        return 0;
    }
    REP(h, N)
    {
        REP(w, M)
        {
            Map[h][w] = std::min(A[h], B[w]);
            T[Map[h][w]]++;
            if (A[h] == B[w])
                S[Map[h][w]] = true;
        }
    }

    ll ans = 1;
    ll next = 0;
    for (int i = N * M; i > 0; --i)
    {
        if (T[i] == 0)
        {
            T[i] += next;
            next = 0;
        }
        if (!S[i])
            ans = (ans * T[i]) % MOD;
        next += T[i] - 1;
    }
    cout << ans << endl;
    return 0;
}