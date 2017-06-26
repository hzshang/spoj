//http://www.spoj.com/problems/POUR1/

#include <iostream>
#include <set>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int,int> pa;
int A,B,C;

pa fillA(int a,int b){
	return pa(A,b);
}
pa fillB(int a,int b){
	return pa(a,B);
}
pa emptyA(int a,int b){
	return pa(0,b);
}
pa emptyB(int a,int b){
	return pa(a,0);
}
pa AtoB(int a,int b){
	if(a<B-b)
		return pa(0,b+a);
	else
		return pa(a+b-B,B);
}
pa BtoA(int a,int b){
	if(b<A-a)
		return pa(a+b,0);
	else
		return pa(A,a+b-A);
}
pa (*fc[6])(int,int);

int out(){
	if(C>A&&C>B)
		return -1;
	set<pa> record;
	pa *root=new pa(0,0);
	pa *temp=root;
	pa t;
	queue<pa*> Q;
	Q.push(root);
	record.insert(*root);
	Q.push(NULL);
	int step=1;
	bool over=false,done=false;
	while(!done){
		temp=Q.front();
		Q.pop();
		if(temp==NULL){
			Q.push(NULL);
			step++;
			if(over)
				break;
			over=true;
			continue;
		}
		for(int i=0;i<6;i++){
			t=fc[i](temp->first,temp->second);
			if(t.first==C||t.second==C){
				done=true;
				break;
			}
			if(record.find(t)!=record.end()||(t.first==A&&t.second==B))
				continue;
			Q.push(new pa(t.first,t.second));
			record.insert(t);
			over=false;
		}
	}
	if(done!=true)
		step=-1;
	return step;

}
int main(int argc, char const *argv[])
{
	int T;
	fc[0]=fillA;
	fc[1]=fillB;
	fc[2]=emptyA;
	fc[3]=emptyB;
	fc[4]=AtoB;
	fc[5]=BtoA;
	cin>>T;
	while(T--){
		cin>>A>>B>>C;
		cout<<out()<<endl;
	}
	return 0;
}