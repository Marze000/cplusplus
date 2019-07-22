#if 0
#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	long long CD[3] = {0, 0,1 };
	long long JC[3] = {0, 1,2 };
	for (int i = 3; i < 22; ++i) {
		CD[i] = (i - 1)*(CD[i - 1] + CD[i - 2]);
		JC[i] = JC[i - 1] * JC[i - 2];
	}

	cout << JC[4] << endl;

	system("pause");
	return 0;
}

#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	long long d[22] = { 0, 0, 1 };
	// ����������Ԥ����һ��Ϊ 0 ���������������� n
	long long f[22] = { 0, 1, 2 }; 
	// �� ��
	for (int i = 3; i < 22; i++){
		d[i] = (i - 1) * (d[i - 1] + d[i - 2]); // ���ŵĵ��ƹ�ʽ
		f[i] = i * f[i - 1]; // �׳˵ĵ��ƹ�ʽ
	}

	int n;
	while (std::cin >> n){
		printf("%.2f%%\n", 100.0 * d[n] / f[n]);
		// �� 100.0 ���ѽ�������� double ��������λС��
	}

	system("pause");
	return 0;
}

#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	long long d[22] = { 0, 0, 1 };
	// ����������Ԥ����һ��Ϊ 0 ���������������� n
	long long f[22] = { 0, 1, 2 };
	// �� ��
	for (int i = 3; i < 22; i++) {
		d[i] = (i - 1) * (d[i - 1] + d[i - 2]); // ���ŵĵ��ƹ�ʽ
		f[i] = i * f[i - 1]; // �׳˵ĵ��ƹ�ʽ
	}

	int n;
	while (std::cin >> n) {
		printf("%.2f%%\n", 100.0 * d[n] / f[n]);
		// �� 100.0 ���ѽ�������� double ��������λС��
	}

	system("pause");
	return 0;
}
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
int main(){
	std::string line;
	// ��һ�ε�����ץ�� line ��
	while (std::getline(std::cin, line)) {
		std::vector<std::string> names; 
		//names �������е�����
		size_t pos = 0;
		// λ��������ڵ����˳��ȣ���ô֤�������ˣ�˫���ŵ��������������
		while (pos < line.length()) {
			// �ҵ�˫����Ҫ����˫�����ڲ�
			if (line[pos] == '\"') {
				size_t end = line.find("\"", pos + 1);
				names.push_back(line.substr(pos + 1, end - pos - 1)); 
				// ��ȡ�����ŵ� names ��
				pos = end + 2;
				// ���������˫���źͶ���
			}else{
				size_t end = line.find(",",pos+1);
				// �Ҳ�������֤���������һ���ַ����ˣ�ֱ�Ӵ�������ַ���������ne.find(",", pos + 1);
				if (end == -1) {
					names.push_back(line.substr(pos, line.size() - pos));
					break;
				}
				names.push_back(line.substr(pos, end - pos));
				pos = end + 1; // ��������Ķ���
			}
		}

		std::getline(std::cin, line);
		if (names.end() == std::find(names.begin(), names.end(), line))
			//std::find �������������������м���ң����һ��������Ҫ�ҵ�ֵ��
			// �ҵ��˷��ض�Ӧ���������Ҳ����ͷ�������ĩβ��λ�á��������� end() ��
		{
			printf("Important!\n"); // û�ҵ�
		}else{
			printf("Ignore\n"); // �ҵ���
		}
	}
	return 0;
}
#endif

#include <iostream>
#include <stdlib.h>
using namespace std;

//ͨ��һ�׿����������з�Ϊ������
int Partion(int* arr, int left, int right) {
	int key = arr[right - 1];
	int begin = left;
	int end = right - 1;
	while (begin < end) {
		while (begin < end && arr[begin] <= key) {
			++begin;
		}
		while (begin < end && arr[end] >= key) {
			--end;
		}

		if (begin < end) {
			swap(arr[end], arr[begin]);
		}
	}

	if (begin != right - 1) {
		swap(arr[end], arr[right -1]);
	}

	return begin;
}

void QuickSort(int* array, int left, int right) {
	if (right - left > 1) {
		//���ֻ�׼ֵ
		int div = Partion(array, left, right);

		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}
}

int main() {
	int a[10] = { 3,5,1,6,9,0,7,2,8,4 };
	QuickSort(a, 0, 10);
	for (int i = 0; i < 10; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}