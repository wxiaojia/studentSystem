#include <iostream>
#include <fstream>  
#define M 100 
#define N 10 
#define NU 20 
#include<string>
using namespace std;
typedef struct  sub 
{ 	 string num;				//课程编号
	 string book;			//课程名
	 string start;				//开课学期
}sub; 
 typedef struct  subject 
 {
	 sub data[M];  
	 int len;
 }subject; 

 /*将文件中的信息写到链表中*/
subject readFile(subject L){
	ifstream cla("class.txt");
	cla.seekg(ios::beg);
	string s;
	getline(cla,s);
	while ( getline(cla,s) ){
		L.len++;
		int n,l=0;
		n=s.find("------");
		int flag=1;
		while(l<=s.size()){	
			string sh=s.substr(l,n);
			if(flag==1) L.data[L.len].num=sh;
			else if(flag==2) L.data[L.len].book=sh;
			else if(flag==3) L.data[L.len].start=sh;
			n=s.find("------",n);
			l+=n;
			l+=6;
			flag++;
		}
	}
	return L;
}
/*将链表写入文件中*/
void writeFile(subject L){
	 ofstream clas("class.txt");
     //	clas.seekg(ios::beg);
	 int a;
	 clas<<"课程编号------课程名------开课学期"<<endl; 
	 for(a=1;a<=L.len;a++)  {
		 clas<<L.data[a].num<<"------"<<L.data[a].book<<"------"<<L.data[a].start<<endl;
	 }
	// cla.close();
}
 /*6.0 课程信息管理目录*/
  void sub_menu(){
	cout<<"课程信息管理"<<endl;
	cout<<"1.添加课程信息"<<endl;
    cout<<"2.删除课程信息"<<endl;
	cout<<"3.修改课程信息"<<endl;
	cout<<"4.查找课程信息"<<endl;
	cout<<"5.输出课程信息"<<endl;
	cout<<"6.退出"<<endl;
 }
 /*6.4.1查询课程编号*/
 int searchBynum(subject L,string num){
	int i,s=0;
	for(i=1;i<=L.len;i++){
		if(L.data[i].num==num)
		{s=i;break;}
	}
	return s;
 }
 /*6.4.2查询课程名字*/
 int searchByBook(subject L,string book){
	int i,b=0;
	for(i=1;i<=L.len;i++){
		if(L.data[i].book==book)
		{b=i;break;}
	}
	return b;
 }
/*6.1.增加*/
subject insert(subject L){
	L.len++;
	int s=0,b=0;
	int n=L.len;
	cout<<"请输入课程编号:";  
	cin>>L.data[n].num;
	s=searchBynum(L,L.data[n].num);
	while(s!=n)  
    {  
       cout<<"该编号已存在，请输入其他编号：";  
       cin>>L.data[n].num;  
	   s=searchBynum(L,L.data[n].num);
    }  
	cout<<"请输入课程名:";  
	cin>>L.data[n].book;
	b=searchByBook(L,L.data[n].book);
	while(b!=n)  
    {  
       cout<<"该课程名已存在，请输入其他课程名：";  
       cin>>L.data[n].book;     
	   b=searchByBook(L,L.data[n].book);
    }  
	cout<<"请输入开课学期:";  
	cin>>L.data[n].start;
	return L;
}
/*6.2.删除目录*/
void delecla_menu(){
	cout<<"根据***删除课程信息管理"<<endl;
	cout<<"1.课程编号"<<endl;
    cout<<"2.课程名"<<endl;
	cout<<"3.开课学期"<<endl;
	cout<<"4.退出"<<endl;
 }
/*6.6.0删除后后部分前*/
subject dele(subject L,int s){
	int j;
	for(j=s+1;j<=L.len;j++){
		L.data[j-1]=L.data[j];
	}
	L.len--;
	cout<<"删除成功;"<<endl;
	return L;
}
/*6.2.1按课程编号删除*/
subject deleByNum(subject L,string i){
	int s;
	if(L.len==0) {cout<<"表空，不能删除"<<endl;}
	else{
		s=searchBynum(L,i);
		cout<<s;
		if(s<1||s>L.len) {cout<<"找不到此课程"<<endl;}
		else{
			L=dele(L,s);
		}
	}
	return L;
}

/*6.2.2按课程名删除*/
subject deleByName(subject L,string book){
	int b=0;
	b=searchByBook(L,book);
	if(b==0){cout<<"不存在此课程!!"<<endl;}
	else{
		L=dele(L,b);
	}
	return L;
}
/*6.2.3按学期删除*/
subject deleByStart(subject L,string start){
	int i;
	for(i=1;i<=L.len;i++){
		if(L.data[i].start==start){
			L=dele(L,i);
		}
	}
	return L;
}
/*6.3.0改*/
void updatecla_menu(){
	cout<<"修改课程***信息管理"<<endl;
	cout<<"1.课程名"<<endl;
    cout<<"2.开课学期"<<endl;
	cout<<"3.退出"<<endl;
}
/*6.3.1修改课程*/
subject updateName(subject L){
	string num;
	string book;
	cout<<"请输入要修改的编号:";
	cin>>num;
	cout<<"请输入要修改的课程:";
	cin>>book;			
	int b=searchByBook(L,book);
	if(b==0) {L.data[b].book=book;cout<<"修改成功"<<endl;}
	else cout<<"该课程号已经存在，编号为"<<L.data[b].num<<endl;
	return L;
}
/*6.3.2 修改开课学期*/
subject updateStart(subject L){
	string num,start;
	cout<<"请输入要修改的编号:";
	cin>>num;
	cout<<"请输入要修改的开课学期:";
	cin>>start;
	int n=searchBynum(L,num);
	L.data[n].start=start;
	cout<<"修改成功"<<endl;
	return L;
}
/*6.4查询*/
void searchcla_menu(){
	cout<<"根据**信息查询课程管理"<<endl;
	cout<<"1.课程编号"<<endl;
	cout<<"2.课程名"<<endl;
    cout<<"3.开课学期"<<endl;
	cout<<"4.退出"<<endl;
}
/*6.4.0 根据编号输*/
void out_one(subject L,int num){
	cout<<"课程编号------课程名------开课学期"<<endl; 
	cout<<L.data[num].num<<"------";
	cout<<L.data[num].book<<"------";
	cout<<L.data[num].start<<endl;
}
/*6.4.1 根据编号查*/
subject search_num(subject L){
	string num;
	int n;
	cout<<"请输入查询的编号:";
	cin>>num;
	n=searchBynum(L,num);
	cout<<n;
	if(n==0) cout<<"不存在该编号;"<<endl; 
	else out_one(L,n);	
	return L;
}
/*6.4.2 根据课程名查*/
subject search_name(subject L){
	string book;
	int b;
	cout<<"请输入查询的课程名:";
	cin>>book;
	b=searchByBook(L,book);
	if(b==0) cout<<"不存在该课程名;"<<endl;
	else out_one(L,b);
	return L;
}
/*6.4.3 根据开课学期查*/
subject search_start(subject L){
	string start;
	cout<<"请输入查询的开课学期:";
	cin>>start;
	int flag=0;
	for(int i=1;i<=L.len;i++){
		if(L.data[i].start==start)
			{out_one(L,i);flag=1;}	
	}
	if(flag==0) cout<<"不存在该学期的课程"<<endl;
	return L;
}
/*6.5输*/
void out(subject L) {
	 int a;   
	 cout<<"课程编号------课程名------开课学期"<<endl; 
	 for(a=1;a<=L.len;a++)  {
		 cout<<L.data[a].num<<"------";
		 cout<<L.data[a].book<<"------";
		 cout<<L.data[a].start<<endl;
	 }
 }

void main(){
   	subject L;  
   	string num;
	int x;
	L.len=0;
	sub_menu();
	L=readFile(L);
	while(1){
		cout<<endl;
		cout<<"请输入要实现的功能：";
		cin>>x;
		switch(x){
		case 1:{L=insert(L);break;
			   }
			case 2:{	delecla_menu();
						int y;
						char con='y';
						string book;
						string start;
						while(con=='y'){
							cout<<"请输入有关删除的功能:";
							cin>>y;
							//1：编号，2：名 3.开学期
							if(y==1) {cout<<"请输入要删除课程的编号:";cin>>num;L=deleByNum(L,num);}
							else if(y==2) {cout<<"请输入要删除的课程名:";cin>>book;L=deleByName(L,book);}
							else if(y==3) {cout<<"请输入要删除的学期课程：";cin>>start;L=deleByStart(L,start);}
							else if(y==4) exit(0);	
							cout<<endl;
							cout<<"是否继续删除（y:继续,任意键返回上一级):";
							cin>>con;
							cout<<endl;
						}
						break;
					}
			case 3:{	updatecla_menu();
						int y;
						char con='y';
						while(con=='y'){
							cout<<"请输入有关修改的功能:";
							cin>>y;
							//1：名 2.开学期
							if(y==1)	L=updateName(L);
							else if(y==2) L=updateStart(L);
							else if(y==3) exit(0);	
							cout<<endl;
							cout<<"是否继续修改（y:继续,任意键返回上一级):";
							cin>>con;
							cout<<endl;
						}
						break;
					}
			case 4:{	searchcla_menu();
						char con='y';
						int y;
						while(con=='y'){
							cout<<"请输入有关查询的功能:";
							cin>>y;
							//1.编号  2.课程名  3.开课学期
							if(y==1) L=search_num(L);
							else if(y==2) L=search_name(L);
							else if(y==3) L=search_start(L);
							else if(y==4) exit(0);
							cout<<endl;
							cout<<"是否继续修改（y:继续,任意键返回上一级):";
							cin>>con;
							cout<<endl;
						}
						break;
				   }
			case 5:out(L);break;
			default:{writeFile(L);exit(0);}
		}		
	}
}

