#include<stdio.h>
#include<string.h>
float getfloat(int m);

int main() {
	int m = 1; //��¼�ڼ���������
	float num1, num2;
	double sum;//��ֹ��ӽ�������ת���ɸ���ľ���
	num1 = num2 = sum = 0;

	printf("�������һ��128λ��������-126~127��\n");
	num1 = getfloat(m);
	printf("������ڶ���128λ��������-126~127��\n");
	m = 2;
	num2 = getfloat(m);
	sum = num1 + num2;
	printf("������ %f + %f = %f\n", num1, num2, sum);
	getchar();

	return 0;

}
float getfloat(int m) {
	float num;
	bool flag = true;
	do {
		scanf("%f", &num);
		if (getchar() != '\n') {
			printf("����ĵ�%d�����������Ϸ�������������\n", m);
			flag = true;
		} else {
			if (((int)num <= 127) && ((int)num >= -126)) {
				flag = false;
			} else {
				flag = true;
				printf("����ĵ�%d�����������Ϸ�������������\n", m);
			}

		}
	} while (flag);
	return num;


}
