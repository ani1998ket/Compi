// Picture with kittens( Easy version )
#include <bits/stdc++.h>
using namespace std;
 
inline void print( vector<int> arr ) { for( const auto& e : arr ) cout << e << " "; cout << endl;}
 
long long recurse( const vector<int>& arr, int count_left, vector< vector<long long > >& dp, int segment_size, int index = 0 ){
     
 
    if( count_left <= 0 && (int)arr.size() - index >= segment_size )
        return -1;
    
    if( index >= (int)arr.size() || count_left <= 0)
        return 0;
 
    if( dp[ index ][ count_left ] != -3 ){
        return dp[ index ][ count_left ];
    }
 
    int i = index;
    long long max_sum = -1;
    for(; i < index + segment_size; i++ ){
        if( i < arr.size() ){
            long long sum =  recurse( arr, count_left - 1, dp, segment_size, i + 1 );
            if( sum >= 0 )
                max_sum = max( max_sum, arr[i] + sum );
        }else{
            break;
        }
    }
    dp[ index ][ count_left ] = max_sum;
    return dp[ index ][ count_left ];
}
 
void solve(){
    int N, K, X;
    cin >> N >> K >> X;
    vector<int> arr(N, 0);
    for( auto& e : arr ){
        cin >> e;
    } 
    //print( arr );
    bool possible = true;
    vector< vector< long long > > dp( N, vector< long long >( X + 1, -3) );
    if( N / K > X ){
        cout << -1;
    }else{
        cout << recurse( arr, X, dp, K);
    }
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
