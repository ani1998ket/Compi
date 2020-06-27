// Thematic Contests
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i, start, end, d) for( int i = (start); i < (end); i += (d) )

void solve(){
    int N;
    cin >> N;
    unordered_map<int, int> count;
    count.reserve( 2 * N );
    for( int i = 0; i < N; i++ ){
        int a;
        cin >> a;
        count[a]++;
    }
    vector<int> arr;
    arr.reserve( N + 1);
    for( auto i = count.begin(); i != count.end(); i++ ){
        arr.push_back( i->second );
    }
    sort( arr.begin(), arr.end() );

    int max_val = 0;
    int i = arr.back();
    max_val = i;
    if( i & 1 ){
        i--;
    }
    for( ; i >= 0; i -= 2 ){
        int index = arr.size() - 1;
        int val =  i;
        int sum = val;
        while( index >= 0 ){
            --index;
            if( val & 1 || index < 0){
                break;
            }
            if( arr[ index ] >= val / 2 ){
                val /= 2;
                sum += val;
            }else{
                break;
            }
             
        }

        max_val = max( sum, max_val );
    }
    cout << max_val << endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	//cin >> T;

	while( T-- ){
	    solve();
	}
	return 0;
}

