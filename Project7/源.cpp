//#include<stdio.h>
//int main()
//{
//	//int a = 2, c = 5;
//	//printf("a=%%d,b=%%d\n", a, c);
//
//
//	double a, b;
//	scanf_s("%lf,%lf", &a, &b);
//	printf("%lf %lf", a, b);
//
//}

//#define _CRT_SECURE_NO_WARNINGS 1
//�������ϵͳ
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class pet {
//    char* name;
//public:
//    pet(const char* n = "") {   // Ĭ�Ϲ���
//        name = new char[strlen(n) + 1];
//        strcpy(name, n);
//    }
//    pet(const pet& p) {    // ��������
//        name = new char[strlen(p.name) + 1];
//        strcpy(name, p.name);
//    }
//    void setName(const char* n) {
//        delete[] name;
//        name = new char[strlen(n) + 1];
//        strcpy(name, n);
//    }
//    void print() const {
//        cout << "Name: " << name << endl;
//    }
//    pet& operator=(const pet& W) {
//        if (this == &W)
//            return *this;
//        delete[] name;
//        name = new char[strlen(W.name) + 1];
//        strcpy(name, W.name);
//    }
//    ~pet() {
//        delete[] name;
//    }
//};
//
//class petStore {
//    pet* pPet;
//    int total;
//public:
//    petStore(pet* p,int n) : total(n) {   // Ĭ�Ϲ���
//        pPet = new pet[total];
//        for (int i = 0; i < total; i++)
//            pPet[i].operator=(p[i]);//�Ⱥ�����
//    }
//    
//    int len() const {
//        return total;
//    }
//    pet getitem(int index) const{//���޸Ķ���
//        return pPet[index];
//    }
//    ~petStore() {
//        delete[] pPet;
//    }
//};
//
//int main() {
//    pet mypets[3] = { "mimi"};
//    pet* pPet = mypets;
//    
//    char name[20];
//    
//    for (; pPet<mypets+3; pPet++) {
//        cin >> name;
//        pPet->setName(name);
//    }
//    pet hisPet(mypets[0]);
//    hisPet.print();
//    petStore ps(mypets,3);//������pet����Ϣ�浽ps
//    
//    for (int i = 0; i < ps.len(); i++) {
//        ps.getitem(i).print();//��ʾps������pet����Ϣ
//    }
//    return 0;
//}


//����ͳ�Ƴ�һ���ж��ٸ��ַ�
/*#include<stdio.h>
int main() {
	int n = 0; char ch;

	ch = getchar();
	while(ch != '\n')
	{ 
		n++;
	}
	while ((ch = getchar()) != '\n') 
		n++;

	while (getchar() != '\n')
		n++;

	for (n = 0; getchar() != '\n'; n++) {

	}
	printf("%d", n);
	return 0;
}

#include<stdio.h>
#include<math.h>
int main()
{
	double a, b, c, d, p, q, x1, x2;
	scanf("%lf,%lf,%lf", &a, &b, &c);
	d = b * b - 4 * a * c;

	if (d > 1e-6)
	{
		x1 = (-b + sqrt(d)) / (2 * a);
		x2 = (-b - sqrt(d)) / (2 * a);

		printf("���ȣ�%6.2f,%6.2f\n", x1, x2);
	}
	else if (fabs(d)<= 1e-6)
		printf("��ȣ�%6.2f\n", b / (-2 * a));

	else
	{
		p = - b / (2 * a);
		q = sqrt(-d) / (2 * a);
		printf("��������������:\n");
		printf("%6.2f+%6.2fi\n", p, q);
		printf("%6.2f-%6.2fi\n", p, q);
	}
	return 0;
}*/
//����ɸ
//#include<stdio.h>
//const int N = 1e5 + 10;
//bool check(int t) {
//	if (t < 2) return false;
//	for (int i = 2; i <= t / i; i++) {
//		if (t % i == 0) return false;
//	}
//	return true;
//}
//int main()
//{
//	int n;
//	int a[N];
//	scanf("%d", &n);
//	int t,cnt=0;
//	while (n--) {
//		scanf("%d", &t);
//		if (check(t))
//			a[cnt++] = t;
//	}
//	for (int i = 0; i < cnt; i++)
//		printf("%d ", a[i]);
//	return 0;
//}
/*
//��°ͺղ���
#include<stdio.h>
bool check(int t) {
	if (t < 2) return false;
	for (int i = 2; i <= t / i; i++) {
		if (t % i == 0) return false;
	}
	return true;
}

void Output(int t) {
	for(int i=2;i<=t;i++)
		if (check(i) && check(t - i)) {
			printf("%d=%d+%d\n", t, i, t - i);
			break;
		}
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 4; i <= n; i++) {
		if (i % 2 == 0)
			Output(i);
	}
	return 0;
}*/

//#include<stdio.h>
//const int N = 1e8;
////����2��ż��һ����������
//bool isPrime(int t) {
//	if (t < 2) return false;
//	for (int i = 3; i <= t / i; i+=2) {
//		if (t % i == 0) return false;
//	}
//	return true;
//}
//bool isHW(int t) {
//	int a[10], cnt = 0;
//	while (t) {
//		a[cnt++] = t % 10;
//		t /= 10;
//	}
//	for (int i = 0; i < cnt/2; i++) {
//		if (a[i] != a[cnt - i - 1])
//			return false;
//	}
//	return true;
//}
//int main()
//{
//	int l, r;
//	scanf("%d%d", &l, &r);
//	for (int i = l; i <= r; i++) {
//		if (i % 2 == 0) continue;
//		if (isPrime(i) && isHW(i))
//			printf("%d\n", i);
//	}
//	return 0;
//}