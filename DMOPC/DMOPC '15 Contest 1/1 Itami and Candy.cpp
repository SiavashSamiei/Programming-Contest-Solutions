#include <cmath> 
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector <int> primes;
void sieve(int n){
	vector<bool> list(n+1,true);
	for (int i = 2; i*i<=n; i++){
		if (list[i]){
			for (int j = i*i;j<=n;j+=i){
			list[j] = false;
			}
		}
	}
	for (int i = 2; i <=n; i++){
		if (list[i])
			primes.push_back(i);
	}
}
int main (){
	int N, X;
	cin>>N>>X;
	sieve (N);
	int total=0;
	if (N<=1){
		cout<<0<<endl;
		return 0;
	}
	for (int n = 0; n < primes.size() ; n++){
			total += (N - primes[n]) / X * 2 +2;
				if ((N - primes[n]) % X == 0){
				 total--;
			}
	}
	cout<<total<<endl;
	return 0;
}
