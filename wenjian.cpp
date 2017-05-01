//借助strtok实现split
#include <iostream>
#include <string>
 using namespace std;
void main()
{
	string s="2--5--1";
	cout<<s<<endl;
	int n,len=0;
	n=s.find("--");
	while(len<=s.size())
	{	//cout<<n<<endl;
		cout<<s.substr(len, n)<<endl; //截取s中从pos开始（包括0）的n个字符的子串，并返回
		n=s.find("--",n);
		len+=n;
		len+=2;
	}
}
