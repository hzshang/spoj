//http://www.spoj.com/problems/FCTRL/
#include <iostream>
using namespace std;
int main()
{
	int N,sum,num,mul;
	cin>>N;
	while(N--){
		cin>>num;
		mul=5;
		sum=0;
		while(mul<=num){
			sum+=num/mul;
			mul*=5;
		}
		cout<<sum<<endl;
	}
	return 0;
}