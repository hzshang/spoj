//http://www.spoj.com/problems/SHPATH/
//修改队列中边的长度不一定要删除，可以做标记表示已经取过改边
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <cstring>
#include <set> 
#include <queue>
#include <cstdio>
using namespace std;
int record[10000];//保存最短路集合
typedef pair<int,int> pa;
#define INF 10012312;
struct city{
	vector<int> neibor;
	vector<int> dis;
};

int distance(int begin,int end,vector<city*> &cities){
	priority_queue<pa,vector<pa>,greater<pa> > Q;
	int i,size,dis,n;
	n=cities.size();
	for(int i=0;i<n;i++){
		record[i]=i!=begin?0:INF;
	}
	Q.push(pa(0,begin));
	while(!Q.empty()){
		pa p=Q.top();
		Q.pop();
		if(record[p.second]<p.first)
			continue;
		if(end==p.second)
		{
			dis=p.first;
			break;
		}
		city *temp=cities[p.second];
		size=temp->neibor.size();
		for(i=0;i<size;i++){
			if (record[temp->neibor[i]]==0||temp->dis[i]+p.first<record[temp->neibor[i]])
			{
				record[temp->neibor[i]]=temp->dis[i]+p.first;
				Q.push(pa(temp->dis[i]+p.first,temp->neibor[i]));
			}
		}
	}
	return dis;
}
int main()
{
	int T;
	scanf("%d",&T);
	vector<city*> cities;
	map<string,int> cityMap;
	while(T--){
		int num,i,j,neiborNum,neibor,path;
		char cityName[15];
		cities.clear();
		cityMap.clear();
		scanf("%d",&num);
		for(i=0;i<num;i++){
			scanf("%s",cityName);
			cityMap[string(cityName)]=i;
			scanf("%d",&neiborNum);
			city* a=new city();
			while(neiborNum--){
				scanf("%d %d",&neibor,&path);
				a->neibor.push_back(neibor-1);
				a->dis.push_back(path);
			}
			cities.push_back(a);
		}
		scanf("%d",&num);
		char a[10],b[10];
		while(num--){
			scanf("%s %s",a,b);
			printf("%d\n",distance(cityMap[string(a)],cityMap[string(b)],cities));
		}
	}
	return 0;
}