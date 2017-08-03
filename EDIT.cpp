//http://www.spoj.com/problems/EDIST/
#include <iostream>
#include <string>
using namespace std;
int dp[2001][2001];
int min(int a,int b,int c){
	int t=a<b?a:b;
	return t<c?t:c;
}
int minEdit(string &a,string &b){
	int asize=a.size();
	int bsize=b.size();
	for (int i = 0; i <=asize; ++i)
		dp[i][0]=i;
	for (int i = 0; i <=bsize; ++i)
		dp[0][i]=i;
	for(int i=1;i<=asize;i++)
		for(int j=1;j<=bsize;j++){
			if(a[i-1]==b[j-1])
				dp[i][j]=dp[i-1][j-1];
			else
				dp[i][j]=1+min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
		}
	return dp[asize][bsize];
}
int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	string A;
	string B;
	while(T--){
		cin>>A;
		cin>>B;
		cout<<minEdit(A,B)<<endl;
	}
	return 0;
}