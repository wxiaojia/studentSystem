void stu_menu()						0   学生信息管理目录
int searchByno(stu S,string no)		4.1 查询学生学号
stu insert(stu S)					1.  增加
void dele_menu()					2.  删除目录
stu dele(stu S,int s)				2.0 删除后后部分前移
void out_one(stu S,int a)			4.0 根据下标输出
stu deleByNo(stu S,string i)		2.1 按学号删除
stu deleByName(stu S,string name)	2.2 按学生名删除
stu deleByCla(stu S,string cla)		2.3 按班级删除
void update_menu()					3.  修改目录
stu updateName(stu S)				3.1 修改姓名
stu updateCla(stu S)				3.2 修改班级
stu updateSex(stu S)				3.3 修改性别
stu updatePhone(stu S)				3.4 修改电话
stu updateA(stu S)					3.5 修改选修课
void search_menu()					4.  查询
void search_no(stu S)				4.1 查询学号
void search_name(stu S)				4.2 根据姓名输出
void search_phone(stu S)			4.3 根据手机号码查询
void sort()							5.  排序
stu Sort_no(stu S)					5.1 根据学号排序:冒泡排序
stu Sort_cla(stu S)					5.2 根据班级排序:冒泡排序
stu Sort_phone(stu S)				5.3 根据电话排序
void sub_menu()								6.0	  课程信息管理目录
int searchBynum(subject L,int num)			6.4.1 查询课程编号
int searchByBook(subject L,string book) 	6.4.2 查询课程名字
subject insert(subject L)					6.1.  增加
void delecla_menu()							6.2   删除目录
subject dele(subject L,int s)				6.2.0 删除后后部分前
subject deleByNum(subject L,int i)			6.2.1 按课程编号删除
subject deleByName(subject L,string book) 	6.2.2 按课程名删除
subject deleByStart(subject L,int start)	6.2.3 按学期删除
void updatecla_menu()						6.3.0 改
subject updateName(subject L)				6.3.1 修改课程
subject updateStart(subject L)				6.3.2 修改开课学期
void searchcla_menu()						6.4.  查询
void out_one(subject L,int num)				6.4.0 根据编号输出
subject search_num(subject L)				6.4.1 根据编号查
subject search_name(subject L)				6.4.2 根据课程名查
subject search_start(subject L)				6.4.3 根据开课学期查
void out(subject L) 						6.5   输出全部课程
stu selectcla(stu S,subject L)		7. 学生选课
void print()						8.  输出
void search_cla(stu S)				8.1 根据班级输出
void search_sex(stu S)				8.2 根据性别输出
void search_select(stu S)			8.3 输出选修课
void out(stu S) 					8.4  输出全部
subject readFile(subject L)			读出课程表文件
void writeFile(subject L)			把课程信息写入文件
stu readFile(stu S)					读出学生表文件
void writeFile(stu S)				把学生信息写入文件
	