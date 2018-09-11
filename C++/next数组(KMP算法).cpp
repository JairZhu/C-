#include <iostream>
#include <string>
using namespace std;

void next(string p, int *next)
{
	int pLen = p.length();
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < pLen - 1)
	{
		//p[k]��ʾǰ׺��p[j]��ʾ��׺  
		if (k == -1 || p[j] == p[k])
		{
			++k;
			++j;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

void nextval(string p, int *next)
{
	int pLen = p.length();
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < pLen - 1)
	{
		//p[k]��ʾǰ׺��p[j]��ʾ��׺  
		if (k == -1 || p[j] == p[k])
		{
			++k;
			++j;
			//next[j] = k;
			if (p[j] != p[k])
				next[j] = k;
			else
				next[j] = next[k];
		}
		else
		{
			k = next[k];
		}
	}
}

/*ͨ�����㷵���Ӵ�T��next����*/
void get_next(string T, int *next) {
	int i, j;
	i = 1;
	j = 0;
	next[1] = 0;
	while (i < T.length()) {
		if (j == 0 || T[i] == T[j]) {		//T[i]��ʾ��׺�ĵ����ַ���T[j]��ʾǰ׺�ĵ����ַ�
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];					//���ַ�����ͬ����jֵ����
	}
}

/*��ģʽ��T��next��������ֵ����������nextval*/
void get_nextval(string T, int *nextval) {
	int i, j;
	i = 1;
	j = 0;
	nextval[1] = 0;
	while (i < T.length()) {
		if (j == 0 || T[i] == T[j]) {		//T[i]��ʾ��׺�ĵ����ַ���T[j]��ʾǰ׺�ĵ����ַ�
			++i;
			++j;
			if (T[i] != T[j])				//����ǰ�ַ���ǰ׺�ַ���ͬ����ǰ��jΪnextval��iλ�õ�ֵ
				nextval[i] = j;			
			else
				nextval[i] = nextval[j];	//�����ǰ׺�ַ���ͬ����ǰ׺�ַ���nextvalֵ��ֵ��nextval��iλ�õ�ֵ
		}
		else
			j = nextval[j];					//���ַ�����ͬ����jֵ����
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		int pnext[10000];
		nextval(str, pnext);
		for (int i = 0; i < str.length(); ++i) {
			cout << pnext[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}