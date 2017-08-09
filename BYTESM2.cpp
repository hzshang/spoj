//http://www.spoj.com/problems/BYTESM2/
#include <iostream>
using namespace std;
int pool[102][102];
int max(int a,int b,int c){
	int t=a>b?a:b;
	return t>c?t:c;
}
int main(int argc, char const *argv[])
{
	int T,clo,row;
	for(int i=0;i<102;i++){
		pool[0][i]=0;
	}
	cin>>T;
	while(T--){
		cin>>row>>clo;
		for(int i=1;i<=row;i++){
			pool[i][0]=pool[i][clo+1]=0;
			for(int j=1;j<=clo;j++){
				cin>>pool[i][j];
				pool[i][j]+=max(pool[i-1][j-1],pool[i-1][j],pool[i-1][j+1]);
			}
		}
		int max=0;
		for(int i=1;i<=clo;i++){
			if(max<pool[row][i])
				max=pool[row][i];
		}
		cout<<max<<endl;
	}
	return 0;
}