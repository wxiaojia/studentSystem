#include<iostream>
#include<string> 
#include<fstream>
#define M 100 
#define N 10 
#define NU 20 
using namespace std; 
typedef struct  Student
{  
    string no;  //学号
    string name;//姓名
    string cla;   //班级
	string sex;		//性别 
	string phone; //手机号码
	string sele;	//	选修课程
}Student; 
typedef struct stu{
	Student data[M];
	int len;
}stu;
	
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

	stu readFile(stu S){
		ifstream stu("stu.txt");
		stu.seekg(ios::beg);
		char s[100];
		stu.getline(s,100,'\n');
		while ( stu.getline(s,100,'\n') ){
			S.len++;
			char seg[] = "------"; /*分隔符这里为逗号comma，分隔符可以为你指定的，如分号，空格等*/  
			char charlist[50][50]={""};/*指定分隔后子字符串存储的位置，这里定义二维字符串数组*/  
			int i =0;  
			char *substr= strtok(s, seg);/*利用现成的分割函数,substr为分割出来的子字符串*/  
			while (substr != NULL) {    
					strcpy(charlist[i],substr);/*把新分割出来的子字符串substr拷贝到要存储的charlsit中*/  
					i++;  
					//	cout<<substr<<endl;
				   substr = strtok(NULL,seg);  
			}   
			S.data[S.len].no=charlist[0];
			 S.data[S.len].name=charlist[1];
			S.data[S.len].cla=charlist[2];
			 S.data[S.len].sex=charlist[3];
			 S.data[S.len].phone=charlist[4];
			S.data[S.len].sele=charlist[5];
			//	cout<<charlist[5]<<endl;
		}
		return S;
	}

	/*将链表写入文件中*/
	void writeFile(stu S){
		 ofstream stud("stu.txt");
		 int a;
		 stud<<"学号------姓名------班级------性别------手机号码------选修课"<<endl; 
		 for(a=1;a<=S.len;a++)  {
			 stud<<S.data[a].no<<"------"<<S.data[a].name<<"------"<<S.data[a].cla<<"------"<<S.data[a].sex<<"------"<<S.data[a].phone<<"------"<<S.data[a].sele<<endl;
		 }
}
 /*学生信息管理目录*/
 void stu_menu(){
	cout<<"学生信息管理系统"<<endl;
	cout<<"1.添加学生信息"<<endl;
    cout<<"2.删除学生信息"<<endl;
	cout<<"3.修改学生信息"<<endl;
	cout<<"4.查找学生信息"<<endl;
	cout<<"5.学生信息排序"<<endl;
	cout<<"6.课程信息"<<endl;
	cout<<"7.学生选课"<<endl;
	cout<<"8.输出学生信息"<<endl;
	cout<<"9.退出"<<endl;
 }
 /*4.1查询学生学号*/
int searchByno(stu S,string no){
	int i,s=0;
	for(i=1;i<=S.len;i++){
		if(S.data[i].no==no)
		{s=i;break;}
	}
	return s;
 }
/*1.增加*/
stu insert(stu S){
	S.len++;
	int s=0,b=0;
	int n=S.len;
	cout<<"请输入学生学号:";  
	cin>>S.data[n].no;
	s=searchByno(S,S.data[n].no);
	while(s!=n)  
    {  
       cout<<"该学号已存在，请输入其他学号：";  
       cin>>S.data[n].no;  
	   s=searchByno(S,S.data[n].no);
    }  
	cout<<"请输入学生名字:";  
	cin>>S.data[n].name;
	cout<<"请输入学生班级(如：15级软件1班):";  
	cin>>S.data[n].cla;
	cout<<"请输入学生性别(填写：男/女):";  
	cin>>S.data[n].sex;
	cout<<"请输入学生手机号码:";  
	cin>>S.data[n].phone;
	cout<<"添加成功"<<endl;
	return S;
}
/*2.删除目录*/
void dele_menu(){
	cout<<"根据***删除学生信息管理"<<endl;
	cout<<"1.学号"<<endl;
    cout<<"2.姓名"<<endl;
	cout<<"3.班级"<<endl;
	cout<<"4.返回"<<endl;
 }
/*2.删除后后部分前移*/
stu dele(stu S,int s){
	int j;
	for(j=s+1;j<=S.len;j++){
		S.data[j-1]=S.data[j];
	}
	S.len--;
	cout<<"删除成功;"<<endl;
	return S;
}
/*根据下标输出*/
void out_one(stu S,int a){
	cout<<S.data[a].no<<"------";
	cout<<S.data[a].name<<"------";
	cout<<S.data[a].cla<<"------";
	cout<<S.data[a].sex<<"------";
	cout<<S.data[a].phone<<"------";
	cout<<S.data[a].sele<<endl;
	cout<<endl;
}
/*2.1按学号删除*/
stu deleByNo(stu S,string i){
	int s;
	if(S.len==0) {cout<<"表空，不能删除"<<endl;}
	else{
		s=searchByno(S,i);
		cout<<s;
		if(s<1||s>S.len) {cout<<"找不到此学生"<<endl;}
		else{
			S=dele(S,s);
		}
	}
	return S;
}
/*2.2.按学生名删除*/
stu deleByName(stu S,string name){
	int flag=0;
	for(int i=1;i<=S.len;i++){
		if(S.data[i].name==name)
			{
				if(flag==0)
					cout<<"学号------姓名------班级------性别------手机号码------选修课"<<endl; 
					out_one(S,i);
				flag++;
			}	
	}
	cout<<endl;
	if(flag==0) cout<<"不存在该学生"<<endl;
	else if(flag==1){
		S=dele(S,i);
	}
	else{
		cout<<"有"<<flag<<"个同名的学生，请根据上方出现的学生到学号删除功能删除"<<endl;
	}
	return S;
}
/*2.3按班级删除*/
stu deleByCla(stu S,string cla){
	int flag=0;
	for(int i=1;i<=S.len;i++){
		if(S.data[i].cla==cla)
			{
				S=dele(S,i);
				flag=1;
			}	
	}
	if(flag==0) cout<<"该班级不存在学生"<<endl;
	else S=deleByCla(S,cla);
	return S;
}
/*3.0改*/
void update_menu(){
	cout<<"修改学生***信息管理"<<endl;
	cout<<"1.姓名"<<endl;
    cout<<"2.班级"<<endl;
	cout<<"3.性别"<<endl;
	cout<<"4.手机号码"<<endl;
	cout<<"5.选修课"<<endl;
	cout<<"6.返回"<<endl;
}
/*3.1修改姓名*/
stu updateName(stu S){
	string no;
	string name;
	cout<<"请输入要修改的学号:";
	cin>>no;
	cout<<"请输入要修改的姓名:";
	cin>>name;	
	int b=searchByno(S,no);
	if(b==0) {cout<<"不存在该学生!"<<endl;}
	else{ S.data[b].name=name;cout<<"修改成功"<<endl;}
	return S;
}
/*3.2修改班级*/
stu updateCla(stu S){
	string no;
	string cla;
	cout<<"请输入要修改的学号:";
	cin>>no;
	cout<<"请输入要修改的班级:";
	cin>>cla;
	int n=searchByno(S,no);
	if(n==0) {cout<<"不存在该学生!"<<endl;}
	else{ S.data[n].cla=cla;cout<<"修改成功"<<endl;}
	return S;
}
/*3.3修改性别*/
stu updateSex(stu S){
	string no;
	string sex;
	cout<<"请输入要修改的学号:";
	cin>>no;
	cout<<"请输入要修改的性别:";
	cin>>sex;
	int n=searchByno(S,no);
	if(n==0) {cout<<"不存在该学生!"<<endl;}
	else{ S.data[n].sex=sex;cout<<"修改成功"<<endl;}
	return S;
}
/*3.4修改电话*/
stu updatePhone(stu S){
	string no;
	string phone;
	cout<<"请输入要修改的学号:";
	cin>>no;
	cout<<"请输入要修改的电话号码:";
	cin>>phone;
	int n=searchByno(S,no);
	if(n==0) {cout<<"不存在该学生!"<<endl;}
	else{ S.data[n].phone=phone;cout<<"修改成功"<<endl;}
	return S;
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
/*3.5 修改选修课*/
stu updateA(stu S,subject L){
	string no;
	string sele;
	cout<<"请输入要修改的学号:";
	cin>>no;
	cout<<"请输入要修改的选修课:";
	cin>>sele;
	int n=searchByno(S,no);
	// 添加选修课信息
	out(L);
	if(n==0) {cout<<"不存在该学生!"<<endl;}
	else{ S.data[n].sele=sele;cout<<"修改成功"<<endl;}
	return S;
}
/*4.0查询*/
void search_menu(){
	cout<<"根据**信息查询学生"<<endl;
	cout<<"1.学号"<<endl;
	cout<<"2.姓名"<<endl;
	cout<<"3.手机号码"<<endl;
	cout<<"4.返回"<<endl;
}
/*4.1根据学号输出*/
void search_no(stu S){
	string no;
	cout<<"请输入要查询的学号:";
	cin>>no;
	int s=searchByno(S,no);
	if(s==0){
		cout<<"不存在该学生"<<endl;
	}
	else{
		cout<<"学号------姓名------班级------性别------手机号码------选修课"<<endl; 
		out_one(S,s);
	}
}
/*4.2根据姓名输出*/
void search_name(stu S){
	string name;
	cout<<"请输入查询的学生名:";
	cin>>name;
	int flag=0;
	for(int i=1;i<=S.len;i++){
		if(S.data[i].name==name)
			{
				if(flag==0)
					cout<<"学号------姓名------班级------性别------手机号码------选修课"<<endl; 
					out_one(S,i);
				flag++;
			}	
	}
	if(flag==0) cout<<"不存在该学生"<<endl;
}
/*4.3根据手机号码查询*/
void search_phone(stu S){
	string phone;
	cout<<"请输入查询的手机号码:";
	cin>>phone;
	int flag=0;
	for(int i=1;i<=S.len;i++){
		if(S.data[i].phone==phone)
			{
				if(flag==0)
					cout<<"学号------姓名------班级------性别------手机号码------选修课"<<endl; 
					out_one(S,i);
				flag++;
			}	
	}
	if(flag==0) cout<<"不存在该手机号"<<endl;
}
/*5.排序*/
void sort(){
	cout<<"根据**信息排序"<<endl;
	cout<<"1.学号"<<endl;
    cout<<"2.班级"<<endl;
	cout<<"3.手机号码"<<endl;
	cout<<"4.返回"<<endl;
}
/*5.1根据学号排序:冒泡排序*/
stu Sort_no(stu S){
	int flag,n=S.len;
	for(int i=1;i<=n;i++){	//做n-1趟扫描
		flag=0;
		for(int j=n;j>=i+1;j--){
			if(S.data[j].no<S.data[j-1].no){
				flag=1;
				S.data[0]=S.data[j];
				S.data[j]=S.data[j-1];
				S.data[j-1]=S.data[0];
			}
		}
	if(!flag) break;
	}
	return S;
}
/*5.2根据班级排序:冒泡排序*/
stu Sort_cla(stu S){
	int flag,n=S.len;
	for(int i=1;i<=n;i++){	//做n-1趟扫描
		flag=0;
		for(int j=n;j>=i+1;j--){
			if(S.data[j].cla<S.data[j-1].cla){
				flag=1;
				S.data[0]=S.data[j];
				S.data[j]=S.data[j-1];
				S.data[j-1]=S.data[0];
			}
		}
	if(!flag) break;
	}
	return S;
}
/*5.3根据电话排序:冒泡排序*/
stu Sort_phone(stu S){
	int flag,n=S.len;
	for(int i=1;i<=n;i++){	//做n-1趟扫描
		flag=0;
		for(int j=n;j>=i+1;j--){
			if(S.data[j].phone<S.data[j-1].phone){
				flag=1;
				S.data[0]=S.data[j];
				S.data[j]=S.data[j-1];
				S.data[j-1]=S.data[0];
			}
		}
	if(!flag) break;
	}
	return S;
}
 /*将文件中的信息写到链表中*/
subject readFile(subject L){
	ifstream cla("class.txt");
	cla.seekg(ios::beg);
	char s[100];
	cla.getline(s,100,'\n');
	while ( cla.getline(s,100,'\n') ){
		L.len++;
		char seg[] = "------"; /*分隔符这里为逗号comma，分隔符可以为你指定的，如分号，空格等*/  
        char charlist[4][50]={""};/*指定分隔后子字符串存储的位置，这里定义二维字符串数组*/  
        int i =0;  
        char *substr= strtok(s, seg);/*利用现成的分割函数,substr为分割出来的子字符串*/  
        while (substr != NULL) {    
                strcpy(charlist[i],substr);/*把新分割出来的子字符串substr拷贝到要存储的charlsit中*/  
                i++;  
				//	cout<<substr<<endl;
               substr = strtok(NULL,seg);  
        }   
		L.data[L.len].num=charlist[0];
		 L.data[L.len].book=charlist[1];
		L.data[L.len].start=charlist[2];
	}
	return L;
}
/*将链表写入文件中*/
void writeFile(subject L){
	 ofstream clas("class.txt");
	 int a;
	 clas<<"课程编号------课程名------开课学期"<<endl; 
	 for(a=1;a<=L.len;a++)  {
		 clas<<L.data[a].num<<"------"<<L.data[a].book<<"------"<<L.data[a].start<<endl;
	 }
}
/*6.课程信息管理目录*/
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

 /*7. 学生选课*/
 stu selectcla(stu S,subject L){
 	string no;
 	cout<<"请输入选课学生学号：";
 	cin>>no;
 	int s=searchByno(S,no);
 	if(s==0) cout<<"不存在给学生"<<endl;
 	else{
 		out(L);
	 	cout<<"请输入选课的编号：";
	 	cin>>S.data[s].sele;
	 	cout<<"选课成功"<<endl;
 	}
 	return S;
 }
/*8.输出*/
void print(){
	cout<<"根据**信息输出"<<endl;
    cout<<"1.班级"<<endl;
	cout<<"2.性别"<<endl;
	cout<<"3.选修课"<<endl;
	cout<<"4.全部"<<endl;
	cout<<"5.返回"<<endl;
}
/*8.1根据班级输出*/
void search_cla(stu S){
	string cla;
	cout<<"请输入查询的班级:";
	cin>>cla;
	int flag=0;
	for(int i=1;i<=S.len;i++){
		if(S.data[i].cla==cla)
			{
				if(flag==0)
					cout<<"学号------姓名------班级------性别------手机号码------选修课"<<endl; 
					out_one(S,i);
					flag++;
			}	
	}
	if(flag==0) cout<<"不存在该班级"<<endl;
	else cout<<"该班有"<<flag<<"名学生"<<endl;
}
/*8.2根据性别输出*/
void search_sex(stu S){
	string sex;
	cout<<"请输入查询的性别:";
	cin>>sex;
	int flag=0;
	for(int i=1;i<=S.len;i++){
		if(S.data[i].sex==sex)
			{
				if(flag==0)
					cout<<"学号------姓名------班级------性别------手机号码------选修课"<<endl; 
					out_one(S,i);
					flag++;
			}	
	}
	if(flag==0) cout<<"不存在该性别的学生"<<endl;
	else cout<<"共有"<<flag<<"名符合要求的学生"<<endl;
}
/*8.3 输出选修课*/
void search_select(stu S){
	string num;
	int flag=0;
	cout<<"请输入查询的课程编号：";
	cin>>num;
	for(int i=1;i<=S.len;i++){
		if(S.data[i].sele==num){
			if(flag==0)
				cout<<"学号------姓名------班级------性别------手机号码------选修课"<<endl; 
				out_one(S,i);
				flag++;
		}
	}
	if(flag==0) cout<<"没有学生选该门课程";
	else cout<<"共有"<<flag<<"名学生选择这门课程"<<endl;
}
/*8.4输出全部*/
void out(stu S) {
	 int a;   
	 cout<<"学号------姓名------班级------性别------手机号码------选修课"<<endl; 
	 for(a=1;a<=S.len;a++)  {
		 cout<<S.data[a].no<<"------";
		 cout<<S.data[a].name<<"------";
		 cout<<S.data[a].cla<<"------";
		cout<<S.data[a].sex<<"------";
		cout<<S.data[a].phone<<"------";
		cout<<S.data[a].sele<<endl;
	}
	cout<<"共有"<<S.len<<"名学生"<<endl;
 }
void main(){
   	stu S;  
	string num;
	int x;
	string no;
	S.len=0;
	S=readFile(S);
	subject L;  
	L.len=0;
	L=readFile(L);
	while(1){
		stu_menu();
		cout<<endl;
		cout<<"请输入要实现的功能：";
		cin>>x;
		switch(x){
			case 1:{  S=insert(S);cout<<endl;break;  }
			case 2:{	dele_menu();
						int y;
						char con='y';
						string name;
						string cla;
						while(con=='y'){
							cout<<"请输入有关删除的功能:";
							cin>>y;
							//1：学号，2：名 3.班级  4.选修课
							if(y==1) {cout<<"请输入要删除学生的学号:";cin>>no;S=deleByNo(S,no);}
							else if(y==2) {cout<<"请输入要删除的学生名:";cin>>name;S=deleByName(S,name);}
							else if(y==3) {cout<<"请输入要删除的学生的班级：";cin>>cla;S=deleByCla(S,cla);}
								// else if(y==4) dele_select(S);
							else if(y==4) break;	
							cout<<endl;
							cout<<"是否继续删除（y:继续,任意任意键返回上一级):";
							cin>>con;
							cout<<endl;
						}
						break;
					}
			case 3:{	update_menu();
						int y;
						char con='y';
						while(con=='y'){
							cout<<"请输入有关修改的功能:";
							cin>>y;
							//1：名 2.班级 3.性别 4.电话 
							if(y==1)	S=updateName(S);
							else if(y==2) S=updateCla(S);
							else if(y==3) S=updateSex(S);
							else if(y==4) S=updatePhone(S);
							else if(y==5) S=updateA(S,L);
							else if(y==6) break;	
							cout<<endl;
							cout<<"是否继续修改（y:继续,任意键返回上一级):";
							cin>>con;
							cout<<endl;
						}
						break;
					}
			case 4:{	search_menu();
						char con='y';
						int y;
						while(con=='y'){
							cout<<"请输入有关查询的功能:";
							cin>>y;
							// 1.学号  2.姓名  3.电话号码
							if(y==1) search_no(S);
							else if(y==2) search_name(S);
							else if(y==3) search_phone(S);
							else if(y==4) break;
							cout<<endl;
							cout<<"是否继续查询（y:继续,任意键返回上一级):";
							cin>>con;
							cout<<endl;
						}
						break;
				   }
			case 5:{	sort();
						char con='y';
						int y;
						while(con=='y'){
							cout<<"请输入有关排序的功能:";
							cin>>y;
							// 1.学号  2.班级  3.电话
							if(y==1) {S=Sort_no(S);out(S);}
							else if(y==2) {S=Sort_cla(S);out(S);}
							else if(y==3) {S=Sort_phone(S);out(S);}
							else if(y==4) break;
							cout<<endl;
							cout<<"是否继续排序输出（y:继续,任意键返回上一级):";
							cin>>con;
							cout<<endl;
						}
						break;
			}
			case 6:{	sub_menu();
						char con='y';
						int y;
						while(con=='y'){
							cout<<"请输入有关课程信息的功能:";
							cin>>y;
							// 1.添加  2.删除  3.改	4.查  5.输出
							if(y==1) L=insert(L);
							else if(y==2) {
								delecla_menu();
								int y;
								char con1='y';
								string book;
								string start;
								while(con1=='y'){
									cout<<"请输入有关删除的功能:";
									cin>>y;
									//1：编号，2：名 3.开学期
									if(y==1) {cout<<"请输入要删除课程的编号:";cin>>num;L=deleByNum(L,num);}
									else if(y==2) {cout<<"请输入要删除的课程名:";cin>>book;L=deleByName(L,book);}
									else if(y==3) {cout<<"请输入要删除的学期课程：";cin>>start;L=deleByStart(L,start);}
									else if(y==4) break;	
									cout<<endl;
									cout<<"是否继续删除（y:继续,任意键返回上一级):";
									cin>>con1;
									cout<<endl;
								}
							}
							else if(y==3) {
								updatecla_menu();
								int y;
								char con2='y';
								while(con2=='y'){
									cout<<"请输入有关修改的功能:";
									cin>>y;
									//1：名 2.开学期
									if(y==1)	L=updateName(L);
									else if(y==2) L=updateStart(L);
									else if(y==3) break;	
									cout<<endl;
									cout<<"是否继续修改（y:继续,任意键返回上一级):";
									cin>>con2;
									cout<<endl;
								}
							}
							else if(y==4) {
								searchcla_menu();
								char con3='y';
								int y;
								while(con3=='y'){
									cout<<"请输入有关查询的功能:";
									cin>>y;
									//1.编号  2.课程名  3.开课学期
									if(y==1) L=search_num(L);
									else if(y==2) L=search_name(L);
									else if(y==3) L=search_start(L);
									else if(y==4) break;
									cout<<endl;
									cout<<"是否继续查询（y:继续,任意键返回上一级):";
									cin>>con3;
									cout<<endl;
								}
							}
							else if(y==5) out(L);
							else if(y==6) break;
							cout<<endl;
							cout<<"是否继续有关课程（y:继续,任意键返回上一级):";
							cin>>con;
							cout<<endl;
							writeFile(L);
						}
						break;
			}
			case 7:{	char con4='y';
						while(con4=='y'){
							S=selectcla(S,L);
							cout<<endl;
							cout<<"是否继续选课（y:继续,任意键返回上一级):";
							cin>>con4;
							cout<<endl;
						}
						break;
					}
			case 8:{	print();
						char con='y';
						int y;
						while(con=='y'){
							cout<<"请输入有关输出的功能:";
							cin>>y;
							// 1.班级  2.性别  3.全部
							if(y==1) search_cla(S);
							else if(y==2) search_sex(S);
							else if(y==3) search_select(S);
							else if(y==4) out(S);
							else if(y==5) break;
							cout<<endl;
							cout<<"是否继续输出（y:继续,任意键返回上一级):";
							cin>>con;
							cout<<endl;
						}
						break;
					}
			default:{writeFile(S);exit(0);}
		}		
	}
}


// 必须完成学籍登记表中的下面功能。
// 登记表中包括：学号、姓名、班级（如：15级软件1班）、性别、手机号码、选修课程等信息。
// 程序必须采用链表数据结构实现；
// （1）插入：将某学生的基本信息插入到登记表中；
 	// ①学号不能重复，添加时要查询该学号是否存在,重复时重新输入		ok
// （2）删除：将满足条件的基本信息删除；
	// ①根据学号删除												ok
	// ②根据名字删除 重名的，输出重名学生信息						ok
	// ③根据班级删除												ok
// （3）修改：对基本信息的数据项进行修改；
	// ①修改姓名													ok
	// ②修改班级													ok
	// ③修改性别													ok
	// ④修改手机号码												ok
	// 修改选修课程													?
// （4）查询：查找满足条件（学号或姓名等字段）的学生；
	// ①学号查询													ok
	// ②姓名查询													ok
	// ⑤手机号码查询												ok
	// 选修课的学生查询												?
// （5）排序：根据学生信息（例如：学号或电话号码等）进行排序，尽可能提高查找和维护性能；
	// ①学号排序													ok
	// ②班级排序													ok
	// ③电话号码排序												ok
// （6）增加课程信息（如：课程名、课程编号、开课学期等信息）管理（增加、删除和查找和输出，不限存储结构）；
	// 课程信息														ok
// （7）实现学生的选课功能（学生选择一门课后，该课程信息会出现在该生“选修课程”）；
		// 选修（输入学生学号，输出课程信息，学生选课）				ok
// （8）输出：将登记表中的所有学生的（或满足条件）信息全部输出，要求格式清晰，方便查看。
	// ③班级查询													ok
	// ④性别查询													ok
	//③全部学生														ok

// 扩展功能要求：
// （1）导入：把用户信息从文件读入程序；
// （2）导出：把用户信息导出到文件中保存；

