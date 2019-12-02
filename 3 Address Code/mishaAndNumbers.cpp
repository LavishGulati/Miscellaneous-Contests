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

bool isPossible(ll *digitA, ll *digitB, string a, string b, ll carry, string c, ll id){
    if(id < 0){
        for(ll i = 0; i < 10; i++){
            if(digitA[i] > 0) return false;
            if(digitB[i] > 0) return false;
        }

        if(stoll(a)+stoll(b) == stoll(c)){
            return true;
        }
        else return false;
    }

    for(ll i = 0; i < 10; i++){
        for(ll j = 0; j < 10; j++){
            if(digitA[i] > 0 && digitB[j] > 0 && (i+j+carry)%10 == c[id]-'0'){
                digitA[i]--;
                digitB[j]--;
                char appendA = i+'0';
                char appendB = j+'0';
                if(isPossible(digitA, digitB, appendA+a, appendB+b, (i+j+carry)/10, c, id-1)){
                    return true;
                }

                digitA[i]++;
                digitB[j]++;
            }
        }
    }

    for(ll i = 0; i < 10; i++){
        if(digitA[i] > 0 && (i+carry)%10 == c[id]-'0'){
            digitA[i]--;
            char appendA = i+'0';
            if(isPossible(digitA, digitB, appendA+a, b, (i+carry)/10, c, id-1)){
                return true;
            }

            digitA[i]++;
        }
    }

    for(ll i = 0; i < 10; i++){
        if(digitB[i] > 0 && (i+carry)%10 == c[id]-'0'){
            digitB[i]--;
            char appendB = i+'0';
            if(isPossible(digitA, digitB, a, appendB+b, (i+carry)/10, c, id-1)){
                return true;
            }

            digitB[i]++;
        }
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        string a, b, c;
        cin >> a >> b >> c;

        ll *digitA = new ll[10];
        ll *digitB = new ll[10];
        for(ll i = 0; i < 10; i++){
            digitA[i] = 0;
            digitB[i] = 0;
        }

        for(ll i = 0; i < a.length(); i++){
            digitA[a[i]-'0']++;
        }

        for(ll i = 0; i < b.length(); i++){
            digitB[b[i]-'0']++;
        }

        if(isPossible(digitA, digitB, "", "", 0, c, c.length()-1)){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}
