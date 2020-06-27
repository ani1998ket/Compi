// MAXAND18

#include <bits/stdc++.h>
using namespace std;

bool compare( pair<long long, int> a, pair<long long, int> b ){
    if( a.first == b.first ){
        return b.second < a.second;
    }
    return a.first < b.first;
}
void solve(){
    int N, K;
    cin >> N >> K;
    vector<int> arr( N, 0 );
    for( auto& e : arr ){
        cin >> e;
    }

    vector< pair< long long, int > > sums( 32, pair<long long, int >(0, 0) );

    for( int i = 0; i < sums.size(); i++ ){
        for( auto e : arr ){
            e = e >> i;
            if( e & 1 )
                sums[i].first += (1 << i);
        }

        sums[i].second = i;
    }
    sort( sums.rbegin(), sums.rend(), compare);
    
    int result = 0;
    for( int i = 0; i < K; i++ ){ 
       result += 1 << (sums[i].second);
    }

    cout << result << endl;

}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T = 1;
	cin >> T;

	while( T-- ){
	    solve();
	}
	return 0;
}

