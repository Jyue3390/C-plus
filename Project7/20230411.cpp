/*#include<iostream>
#include<ostream>
class Vector;
class Matrix;
class Matrix {
	int* a;
	int m, n;
public:
	Matrix(int m, int n) :m(m), n(n) {
		a = new int[n * m];
	}
	~Matrix() {
		delete[]a;
	}
	Matrix(const Matrix& W) {
		n = W.n; m = W.m;
		a = new int[n * m];
		for (int i = 0; i < m * n; i++)
			*(a + i) = *(W.a + i);
	}
	friend std::ostream operator<<(std::ostream& out, Matrix& M) {
		for (int i = 0; i < M.m; i++) {
			for (int j = 0; j < M.n; j++) {
				int* p = M.a + i * M.n + j;
				std::cout << *p << " ";
			}
		}
	}
};*/

/*
#include<iostream>
using namespace std;
class CComplex {
	double m_im, m_re;
public:
	CComplex(double=0,double=0);
	inline void set_re(double re) {
		m_re = re;
	}
	inline void set_im(double im) {
		m_im = im;
	}
	inline void display()const {
		cout << m_re << "+" << m_im << "i"<<endl;
	}//inline尽量写在头文件里

	CComplex& operator++();//CComplex&);//前自增
	CComplex operator++(int);//CComplex&, int);//后自增
	friend CComplex operator+(const CComplex&, const CComplex&);//加法
	//CComplex& operator+(const CComplex&);

	friend istream& operator>>(istream&, CComplex&);
	friend ostream& operator<<(ostream&, CComplex&);
};
CComplex::CComplex(double re, double im) :m_re(re), m_im(im) {};
//成员形式重载
CComplex& CComplex::operator++(){//CComplex& M) {//前增
	this->m_re++;
	return *this;
}
CComplex CComplex::operator++(int i) {//后增
	CComplex old = *this;
	++(*this);
	return old;
}*/
/*
CComplex& CComplex::operator+(const CComplex& obj) {
	m_im += obj.m_im; m_re += obj.m_re;
	return *this;
}
*/
//友元重载
/*
CComplex operator+(const CComplex& c1, const CComplex& c2)//加法
{
	CComplex tmp(c1);
	tmp.m_im += c2.m_im;
	tmp.m_re += c2.m_re;
	return tmp;
}
istream& operator>>(istream& in, CComplex& obj) {
	in >> obj.m_re >> obj.m_im;
	return in;
}
ostream& operator<<(ostream& out, CComplex& obj) {
	out << obj.m_re << obj.m_im;
	return out;
}
int main()
{
	CComplex c1(1, 2), c2;
	cout << "c1: "; 	c1.display();//1 2
	cout << "\n前自增c1: "; c2 = ++c1;  c1.display();//2 2
	cout << "\nc2: ";  c2.display();//2 2
	cout << "\n后自增c1: "; c2 = c1++;
	c1.display();//3 2
	cout << "\nc2: ";  c2.display();//2 2

	CComplex c3; c3 = c1 + c2;
	c3.display();//5 4
	//c3.operator+(c2);
	c3.display();//7 6
	
	CComplex c4 = c1 + 2.1;
	c4.display();//3.1+2i     //把+的成员函数打上注释
	c1.display();//3.1+2i     //1+2i
	c4 = 2.2 + c1;
	c4.display();//5.3+2i     //3.2+2i

	CComplex c5; cin >> c5;
	c5.display();
	cout << "\n";
	return 0;
}
*/
/*
2023/4/18
程序化设计 社会化分工
声明和实现要分开
头文件卫士
inline写在cpp中 不会 出现重定义 内联函数：替换 
但是会造成体积庞大

尽量不用对象传递和对象返回，尽量用引用
*/


//下标运算重载
/*
//#ifndef _COMPLEX_H
//#define _COMPLEX_H
#include<iostream>
#include<cstring>
#include<string>
class CMystring {
private:
	unsigned int m_size;
	char* mp_data;
public:
	CMystring(unsigned int = 0);//字符串实际长度
	CMystring(const char* pstr);//构造
	~CMystring();
	char& operator[](int);//下标运算符-----
	CMystring& operator=(const CMystring&);//赋值运算符------只能写成成员函数
	inline int length()const {
		return strlen(mp_data);
	}//返回当前数组的元素个数
	inline int capacity()const {
		return m_size;
	}//返回当前数组的最大元素个数
	void display()const;//输出
};
//#endif
CMystring::CMystring(unsigned int size) {
	m_size = size;
	if (size > 0) mp_data = new char[size];
	else mp_data = 0;
}
CMystring::CMystring(const char* p) {
	m_size = strlen(p) + 20;
	mp_data = new char[m_size];
	strcpy(mp_data, p);
}
CMystring::~CMystring() {
	if (mp_data) delete[] mp_data;
}
void CMystring::display()const {
	std::cout << mp_data << std::endl;
}
char& CMystring::operator[](int idx) {
	return mp_data[idx];
}
//加引用成左值，不加引用不能做左值

CMystring& CMystring::operator=(const CMystring& obj) {//实参的对象既可以是const也可以不是，不加const则实参只能是非const，不能放宽范围
	if (&obj == this) return *this;
	m_size = obj.m_size;
	if (mp_data) delete[] mp_data;
	mp_data = new char[m_size];
	strcpy(mp_data, obj.mp_data);
	return *this;
	/*
	* 浅复制
	* CMystring *p1=new CMystring("ABC"),str2(10);
	* str2=*p1;
	
}*/
/*
int main()
{
	CMystring str("ABCDEFG");
	str.display();
	str[1] = '6';
	str.display();
	std::cout << str[1] << std::endl;
}
*/


//类型转换
/*
#include<iostream>
class Cmoney {
private:
	int yuan, jiao, fen;
public:
	Cmoney(double);
	Cmoney(int, int, int);
	void display()const;
};
Cmoney::Cmoney(int y, int j, int f) :yuan(y),jiao(j),fen(f){
}
Cmoney::Cmoney(double x) {
	yuan = (int)x;
	jiao = (int)(x * 10) - yuan*10;
	fen = (int)(x * 100) - yuan * 100 - jiao*10;
}
void Cmoney::display()const {
	std::cout << yuan << "元" << jiao << "角" << fen << "分" << std::endl;
}

int main()
{
	Cmoney c1(1.24);
	Cmoney c2(1, 3, 6);
	c1.display(); c2.display();
	return 0;
}*/
#include<iostream>
using namespace std;

class Cline;
class CPoint {
	//friend class Cline;
	friend bool isonline(CPoint&, Cline&);
	int x, y;
public:
	CPoint(int x=0, int y=0):x(x), y(y) {}
	void print();
	friend ostream& operator<<(ostream& os, const CPoint& obj)
	{
		os << obj.x << " " << obj.y << endl;
		return os;
	}
};
void CPoint::print() {
	cout << '(' << x << ',' << y << ')';
}

class Cline {
	int a, b;
public:
	Cline(int a=0, int b=0):a(a), b(b) {}
	//bool isonline(CPoint&);

	friend bool isonline(CPoint& point, Cline& line)
	{
		if (point.y == line.a * point.x + line.b)
			return true;
		return false;
	}

};
int main() {
	CPoint p[2] = { CPoint(1,4) };
	cout << p[0] << endl; 
	Cline l1(3, 1);
	int i;
	for(i=0;i<2;i++)
		if (isonline(p[i], l1)) {
			p[i].print();
			cout << "在" << endl;
		}
		else {
			p[i].print();
			cout << "不在" << endl;
		}

	return 0;
}
