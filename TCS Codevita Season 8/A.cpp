#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef map<int, bool> mapib;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;
typedef set<int> seti;
typedef vector<int> vi;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allp(x) (x)->begin(), (x)->end()
#define f first
#define s second
#define MOD 1000000007
#define PI acos(-1)

#define MAX 1000001
ll factorial[MAX];

ll ModInverse(ll x, ll n = MOD-2){
    if(n == 0) return 1;
    if(n == 1) return x%MOD;

    ll y;
    if(n%2 == 0){
        y = ModInverse(x, n/2);
        return (y*y)%MOD;
    }
    else{
        y = ModInverse(x, (n-1)/2);
        return (x*((y*y)%MOD))%MOD;
    }
}

ll choose(ll n, ll r){
    ll answer = (factorial[n]*ModInverse(factorial[r]))%MOD;
    answer = (answer*ModInverse(factorial[n-r]))%MOD;
    return answer;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;

    factorial[0] = 1;
    for(ll i = 1; i <= n; i++){
        factorial[i] = (factorial[i-1]*i)%MOD;
    }

    ll answer = factorial[n], x;
    ll IsPos = 0;
    for(ll i = n-1; i >= 0; i--){
        x = (factorial[i]*choose(n, n-i))%MOD;
        if(IsPos) answer = (answer+x)%MOD;
        else answer = (answer-x+MOD)%MOD;
        IsPos ^= 1;
    }
    cout << answer << endl;
}
