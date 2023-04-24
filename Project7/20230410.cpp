//array类
/*
#include<iostream>
#include<array>
#include<string>
const int Seasons = 4;			//constant data
const std::array<std::string, Seasons> Snames = { "Spring","Summer","Fall","Winter" };//function to modify array object

void fill(std::array<double, Seasons>* pa);//function that uses array object without modifying it
void show(std::array<double, Seasons> da);

int main()
{
	std::array<double, Seasons> expenses;
	fill(&expenses);
	show(expenses);
	return 0;
}

void fill(std::array<double, Seasons>* pa) {//使用指针直接处理原始对象
	using namespace std;
	for (int i = 0; i < Seasons; i++) {
		cout << "Enter" << Snames[i] << " expenses: ";
		cin >> (*pa)[i];
	}
}
void show(std::array<double, Seasons> da) {
	using namespace std;
	double total = 0.0; cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++) {
		cout << Snames[i] << ": S " << da[i] << endl;
		total += da[i];
	}
	cout << "Total Expenses: S" << total << endl;
}*/

//函数的递归
/*
#include<iostream>
const int len = 66;
const int divs = 6;
void subdivide(char ar[], int low, int high, int level);
int main()
{
	char ruler[len];
	int i;
	for (int i = 1; i < len - 2; i++)
		ruler[i] = ' ';
	ruler[len - 1] = '\0';
	int max = len - 2;
	int min = 0;
	ruler[min] = ruler[max] = '|';
	std::cout << ruler << std::endl;

	for (int i = 1; i <= divs; i++) {
		subdivide(ruler, min, max, i);
		std::cout << ruler << std::endl;
		for (int j = 1; j < len - 2; j++)
			ruler[j] = ' ';
	}
	return 0;
}
void subdivide(char ar[], int low, int high, int level) {
	if (level == 0) return;
	int mid = (high + low) / 2;
	ar[mid] = '|';
	subdivide(ar, low, mid, level - 1);
	subdivide(ar, mid, high, level - 1);
}*/

