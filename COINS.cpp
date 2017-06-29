//http://www.spoj.com/problems/COINS/
#include <iostream>
using namespace std;
long long exchange(long long num){
	long long  sum;
	if(num<24)
		sum=num/2+num/3+num/4;
	else
		sum=exchange(num/2)+exchange(num/3)+exchange(num/4);
	if(sum<num)
		sum=num;
	return sum;
}
int main(int argc, char const *argv[])
{
	long coins;
	while(cin>>coins)
		cout<<exchange(coins)<<endl;
	return 0;
}