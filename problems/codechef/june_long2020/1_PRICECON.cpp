// PRICECON 

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int T;
	cin >> T;
	while( T-- ){
	    int N, K;
	    int loss = 0;
	    int price = 0;
	    cin >> N >> K;
	    for( int i = 0; i < N; i++){
	        cin >> price;
	        if( price > K){
	            loss += price - K;
	        }
	    }
	    cout << loss << endl;
	}
	return 0;
}

