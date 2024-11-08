#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>

class MyClass {
public:
	MyClass() = default;
	MyClass(int val):val_(val){}
	MyClass(double val):val_(::ceil(val)){}
	~MyClass() = default;

	MyClass& operator=(const MyClass& other) = default;

	void SetVal(int val) { val_ = val; }
	int GetVal()const { return val_; }
	bool operator<(const MyClass& other)const {
		return val_ < other.val_;
	}



private:
	int val_;
};



int main() {
	std::vector<MyClass> collection;
	collection.reserve(15);
	for (int i = 0; i < collection.capacity(); i++) {

		double temp = 1 + rand() % 10;
		temp += 1. / (1 + rand() % 10);
		//� ���������� temp �������� ����� �� 1 �� 10
		// � ������� ������ �� 0.1 �� 1.0
		//
		collection.emplace_back(temp);
	}
	for (int i = 0; i < collection.size(); i++)
	{
		std::cout << collection[i].GetVal() << ' ';
	}

	std::sort(collection.begin(), collection.end());
	std::cout << "\n";
	//for (int i = 0; i < collection.size(); i++)
	//{
	//	std::cout << collection[i].GetVal() << ' ';
	//}
	std::multiset<MyClass> sortedcollection;//����� ����� ��� ������� � ��� �� ������� ������������ �� ������
	//set ��������� ��������� �������� multiset ���
	for (auto& el : collection) {
		sortedcollection.insert(el);

	}
	//std::set - ������ ������� � ��������������� ���� � �� ������ ������ ���������� ��������


	for (const auto& el : sortedcollection) {
		std::cout<<el.GetVal()<<' ';
	}
	return 0;
}