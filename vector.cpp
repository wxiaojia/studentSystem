#include<iostream>
#include<string> 
#include<vector>
#define M 100 
#define N 10 
#define NU 20 
using namespace std; 
typedef struct  Student
{  
    string no;  //学号
    string name;//姓名
    string cla;   //班级
	int sex;		//性别  0男1 女
	string phone;//手机号码
	vector<int> a;	//	选修课程
}Student; 
typedef struct stu{
	Student data[M];
	int len;
}stu;
void main(){
	stu S;
	S.data[0].a.push_back(5);
	S.data[0].a.push_back(4);
	S.data[0].a.pop_back();
	for(int i=0;i<S.data[0].a.size();i++){
		cout<<S.data[0].a[i]<<endl;
	}
	//cout<<S.data[0].a.size()<<endl;

}