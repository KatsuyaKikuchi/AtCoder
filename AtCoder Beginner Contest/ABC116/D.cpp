#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for (ll(i) = (m); (i) < (n); ++(i))
#define REP(i, n) FOR(i, n, 0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

struct Sushi
{
    ll t;
    ll d;
    bool e;
};

Sushi S[100005];
bool V[100005];
bool U[100005];

int main()
{
    ll N, K;
    cin >> N >> K;

    ll mv = 0;
    REP(i, N)
    {
        cin >> S[i].t >> S[i].d;
        if (!V[S[i].t])
        {
            mv++;
            V[S[i].t] = true;
        }
    }

    sort(S, S + N, [](Sushi a, Sushi b) { return a.d > b.d; });

    mv = std::min(K, mv); //! 食べられる最大の種類数
    int v = 0;            //! 被っているものを食べた数

    ll sum = 0;
    int i = 0, j = 0;
    REP(k, K)
    {
        for (; i < N; ++i)
        {
            if (!S[i].e)
                break;
        }
        for (; j < N; ++j)
        {
            if (!S[j].e && !U[S[j].t])
                break;
        }

        if (v + mv + 1 <= K)
        {
            //! mvを減らさずiを食べる
            sum += S[i].d;
            if (U[S[i].t])
                v++;
            S[i].e = U[S[i].t] = true;
            continue;
        }

        if (j >= N || 2 * mv - 1 + S[j].d < S[i].d)
        {
            //! mvを減らしてiを食べる
            sum += S[i].d;
            if (U[S[i].t])
                v++;
            S[i].e = U[S[i].t] = true;
            mv--;
            continue;
        }
        //! jを食べる
        sum += S[j].d;
        S[j].e = U[S[j].t] = true;
    }
    cout << sum + mv * mv << endl;
    return 0;
}