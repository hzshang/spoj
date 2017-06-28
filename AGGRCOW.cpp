//http://www.spoj.com/problems/AGGRCOW/
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int *array;
int N, C;

bool isOK(int d){
	int *pos=array,*end=array+N,i;
	for(i=1;i<C;i++){
		pos=lower_bound(pos,end,*pos+d);
		if(pos==end)
			break;
	}
	return i==C;
}

int out(){
	int begin=1,end=*(array+N-1)-*array+1,mid;
	while(end-begin>1){
		mid=(begin+end)/2;
		if(isOK(mid)){
			begin=mid;
		}else
			end=mid;
	}
	return begin;
}

int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T--){
		cin>>N>>C;
		array=(int*)malloc(sizeof(int)*N);
		for(int i=0;i<N;i++){
			cin>>array[i];
		}
		sort(array,array+N);
		cout<<out()<<endl;
		free(array);
	}
	return 0;
}