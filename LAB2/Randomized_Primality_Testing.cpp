// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
#include <cassert>

using namespace std;

unsigned long long int power(int a, int x, int n) {
  unsigned long long exp = 1;
  for (int i = 1; i <= x; i++) {
    exp = (exp * a) % n;
  }
  return exp;
}

bool gcd(unsigned long long a,unsigned long long  b){
	unsigned long long r=0;
	while(b>0){
    	r=a%b;
    	a=b;
    	b=r;
	}
	if(a!=1) return true;
	else return false;
}

bool check_prime(unsigned long long  n){
	if(n == 2 || n == 3){
    	return 1;
	}
	if(n <= 1 || n % 2 ==0)
   	return 0;
	int i=0;
	while(i<2){
    	unsigned long long a  = 2 + (rand()%(n-3));
    	if(gcd(a,n)){
        	return 0;
    	}
    	if(power(a,n-1,n)!=1) return 0;
   	 
    	i++;
	}
	return 1;
}

int main() {
	srand(time(0));
	unsigned long long  num =1000000007;
	bool ans =  check_prime(num);
	if(ans) cout << "prime" ;
	else cout << "not prime";
    
	return 0;
}
