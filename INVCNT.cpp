//http://www.spoj.com/problems/INVCNT/
#include <iostream>
#include <cstdlib>
using namespace std;
typedef long long ll;
struct node{
	ll value;
	node* left;
	node* right;
	ll leftnum;
	ll rightnum;
};
ll sum,pos;
node* array;

node* alloc(ll key){
	array[pos].value=key;
	array[pos].left=array[pos].right=NULL;
	array[pos].leftnum=array[pos].rightnum=0;
	return array+pos++;
}
void insert(node* root,ll key){
	if (key>=root->value)
	{
		if(root->right==NULL)
			root->right=alloc(key);
		else
			insert(root->right,key);
		root->rightnum++;
	}else{
		if (root->left==NULL)
			root->left=alloc(key);
		else
			insert(root->left,key);
		sum+=root->rightnum+1;
		root->leftnum++;
	}
}

int main(int argc, char const *argv[])
{

	ll T,i,n,key;
	cin>>T;
	while(T--){
		sum=0;
		pos=0;
		cin>>n;
		array=(node*)malloc(n*sizeof(node));
		cin>>key;
		alloc(key);
		for(i=1;i<n;i++){
			cin>>key;
			insert(array,key);
		}
		free(array);
		cout<<sum<<endl;
	}
	return 0;
}