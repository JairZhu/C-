#include <iostream>
using namespace std;

int main() {
	int number;
	int data[100000] = { 0 };
	cin >> number;
	for (int i = 0; i < number; ++i)
		cin >> data[i];
	int max = data[0];               //��ǰ���������ĺ�
	int cur = 0;					 //��data[i]��β��������
	for (int i = 0; i < number; ++i) {
		cur = data[i] > (cur + data[i]) ? data[i] : (cur + data[i]);//����data[i]��β�ĺ�����������
		max = cur > max ? cur : max;								//��ǰ�����������Ҫô����data[i]��β��Ҫô��data[i]�޹�
	}
	cout << max;
	return 0;
}