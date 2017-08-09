//http://www.spoj.com/problems/BYTESM1/
#include <iostream>
#include <cstring>
using namespace std;
int pool[100000000];
int sum(int num){
	int ret=0;
	while(num){
		ret+=num%10;
		num/=10;
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	int T,a,i,num;
	memset(pool,0,sizeof(pool));
	int p[3]={1,3,9};
	for(i=0;i<3;i++){
		for(num=p[i];num<100000000;){
			pool[num]=p[i];
			num+=sum(num);
		}
	}
	cin>>T;
	while(T--){
		cin>>num;
		while(pool[num]==0){
			num+=sum(num);
		}
		cout<<pool[num]<<" "<<num<<endl;
	}
	return 0;
}