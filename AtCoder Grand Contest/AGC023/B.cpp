#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

ll N;
string S[305];
bool A[305];
bool B[305];

bool solve(ll a, ll b)
{
    ll s = std::min(a, b);
    if (a > b)
    {
        return A[a - s];
    }
    return B[b - s];
}

int main()
{
    cin >> N;
    REP(i, N)
    {
        cin >> S[i];
    }
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    REP(a, N)
    {
        //! A=a,B=0移動したときSynmetryか
        A[a] = true;
        REP(i, N)
        {
            REP(j, N)
            {
                int h0 = (N + i - a) % N;
                int w0 = j;
                int h1 = (N + j - a) % N;
                int w1 = i;
                if (S[h0][w0] == S[h1][w1])
                    continue;
                A[a] = false;
                break;
            }
            if (!A[a])
                break;
        }
    }
    REP(b, N)
    {
        //! A=0,B=b移動したときSynmetryか
        B[b] = true;
        REP(i, N)
        {
            REP(j, N)
            {
                int h0 = i;
                int w0 = (N + j - b) % N;
                int h1 = j;
                int w1 = (N + i - b) % N;
                if (S[h0][w0] == S[h1][w1])
                    continue;
                B[b] = false;
                break;
            }
            if (!B[b])
                break;
        }
    }

    ll ans = 0;
    REP(a, N)
    {
        REP(b, N)
        {
            if (solve(a, b))
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}