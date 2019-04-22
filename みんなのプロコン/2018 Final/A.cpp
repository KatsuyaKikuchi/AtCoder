#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

vector<int> prime;
bool U[100005];
ll A[100005];
ll S[100005];

int main()
{
    ll N, M;
    cin >> N >> M;
    REP(i, N)
    {
        cin >> A[i];
    }
    memset(U, 0, sizeof(U));
    for (int i = 2; i <= 100000; ++i)
    {
        if (U[i])
            continue;
        prime.push_back(i);
        for (int j = i; j <= 100000; j += i)
            U[j] = true;
    }

    memset(S, 0, sizeof(S));
    REP(i, N)
    {
        vector<int> v;
        ll a = A[i];
        for (int j = 0; prime[j] * prime[j] <= A[i]; ++j)
        {
            if (a % prime[j] != 0)
                continue;
            v.push_back(prime[j]);
            while (a % prime[j] == 0)
                a /= prime[j];
        }
        if (a > 1)
            v.push_back(a);

        FOR(j, pow(2, v.size()), 1)
        {
            ll t = 1;
            REP(k, v.size())
            {
                if (((j >> k) & 1) == 1)
                    t *= v[k];
            }
            S[t]++;
        }
    }
    cout << N << endl;
    FOR(i, M + 1, 2)
    {
        vector<int> v;
        ll a = i;
        for (int j = 0; prime[j] * prime[j] <= i; ++j)
        {
            if (a % prime[j] != 0)
                continue;
            v.push_back(prime[j]);
            while (a % prime[j] == 0)
                a /= prime[j];
        }
        if (a > 1)
            v.push_back(a);

        int n = N;
        FOR(j, pow(2, v.size()), 1)
        {
            ll t = 1;
            ll s = 0;
            REP(k, v.size())
            {
                if (((j >> k) & 1) == 1)
                {
                    t *= v[k];
                    s++;
                }
            }
            if (s % 2 == 1)
                n -= S[t];
            else
                n += S[t];
        }
        cout << n << endl;
    }
    return 0;
}