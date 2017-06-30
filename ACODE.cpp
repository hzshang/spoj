//http://www.spoj.com/problems/ACODE/
#include <iostream>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
string s;
int size;
map<int,ll> record;

ll out(int begin){
	ll ret;
	if(record[begin]!=0)
		return record[begin];
	if(size-begin<2)
		ret=1;
	else{
		switch(s[begin]){
			case '1':
				if (s[begin+1]=='0')
					ret=out(begin+2);
				else if(s[begin+1]<'3' && s[begin+2]=='0')
					ret=out(begin+3);
				else
					ret=out(begin+1)+out(begin+2);
				break;
			case '2':
				if(s[begin+1]=='0')
					ret=out(begin+2);
				else if(s[begin+1]<'3' && s[begin+2]=='0')
					ret=out(begin+3);
				else if(s[begin+1]<'7')
					ret=out(begin+1)+out(begin+2);
				else
					ret=out(begin+1);
				break;
			default:
				ret=out(begin+1);
		}
	}
	record[begin]=ret;
	return ret;
}

int main(int argc, char const *argv[])
{
	while(1){
		cin>>s;
		if(s[0]=='0')
			break;
		size=s.size();
		cout<<out(0)<<endl;
		record.clear();
	}
	return 0;
}