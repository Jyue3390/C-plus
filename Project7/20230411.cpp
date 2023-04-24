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
	}//inline����д��ͷ�ļ���

	CComplex& operator++();//CComplex&);//ǰ����
	CComplex operator++(int);//CComplex&, int);//������
	friend CComplex operator+(const CComplex&, const CComplex&);//�ӷ�
	//CComplex& operator+(const CComplex&);

	friend istream& operator>>(istream&, CComplex&);
	friend ostream& operator<<(ostream&, CComplex&);
};
CComplex::CComplex(double re, double im) :m_re(re), m_im(im) {};
//��Ա��ʽ����
CComplex& CComplex::operator++(){//CComplex& M) {//ǰ��
	this->m_re++;
	return *this;
}
CComplex CComplex::operator++(int i) {//����
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
//��Ԫ����
/*
CComplex operator+(const CComplex& c1, const CComplex& c2)//�ӷ�
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
	cout << "\nǰ����c1: "; c2 = ++c1;  c1.display();//2 2
	cout << "\nc2: ";  c2.display();//2 2
	cout << "\n������c1: "; c2 = c1++;
	c1.display();//3 2
	cout << "\nc2: ";  c2.display();//2 2

	CComplex c3; c3 = c1 + c2;
	c3.display();//5 4
	//c3.operator+(c2);
	c3.display();//7 6
	
	CComplex c4 = c1 + 2.1;
	c4.display();//3.1+2i     //��+�ĳ�Ա��������ע��
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
������� ��ữ�ֹ�
������ʵ��Ҫ�ֿ�
ͷ�ļ���ʿ
inlineд��cpp�� ���� �����ض��� �����������滻 
���ǻ��������Ӵ�

�������ö��󴫵ݺͶ��󷵻أ�����������
*/


//�±���������
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
	CMystring(unsigned int = 0);//�ַ���ʵ�ʳ���
	CMystring(const char* pstr);//����
	~CMystring();
	char& operator[](int);//�±������-----
	CMystring& operator=(const CMystring&);//��ֵ�����------ֻ��д�ɳ�Ա����
	inline int length()const {
		return strlen(mp_data);
	}//���ص�ǰ�����Ԫ�ظ���
	inline int capacity()const {
		return m_size;
	}//���ص�ǰ��������Ԫ�ظ���
	void display()const;//���
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
//�����ó���ֵ���������ò�������ֵ

CMystring& CMystring::operator=(const CMystring& obj) {//ʵ�εĶ���ȿ�����constҲ���Բ��ǣ�����const��ʵ��ֻ���Ƿ�const�����ܷſ�Χ
	if (&obj == this) return *this;
	m_size = obj.m_size;
	if (mp_data) delete[] mp_data;
	mp_data = new char[m_size];
	strcpy(mp_data, obj.mp_data);
	return *this;
	/*
	* ǳ����
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


//����ת��
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
	std::cout << yuan << "Ԫ" << jiao << "��" << fen << "��" << std::endl;
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
			cout << "��" << endl;
		}
		else {
			p[i].print();
			cout << "����" << endl;
		}

	return 0;
}
