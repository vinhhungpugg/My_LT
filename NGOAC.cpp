#include <iostream>
#include <stack>

#define  st  stack<char>

using namespace std;

st a;

bool Ngoac(string str,st a)
{
	for(int i=0; i<str.size(); i++)
	{
		if  (str[i]=='(' || str[i]=='{' || str[i]=='[')  a.push(str[i]);
         else
		  {
			if(a.empty()) return false;
			if ((str[i]==')' && a.top()!='(') ||
				(str[i]=='}' && a.top()!='{') ||
				(str[i]==']' && a.top()!='['))
			  return false;
            a.pop();
	      }
	}
	return a.empty()==true;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

	int n;
	cin>>n;
	cin.ignore();

	while (n--)
	{
		string str;
		cin>>str;
		if  (Ngoac(str,a)) cout<<"YES\n";
			else cout<<"NO\n";
		while (!a.empty()) a.pop();
	}
	return 0;
}
