#include<stdio.h>
#include<string.h>
float getfloat(int m);

int main() {
	int m = 1; //记录第几个浮点数
	float num1, num2;
	double sum;//防止相加结果溢出，转换成更大的精度
	num1 = num2 = sum = 0;

	printf("请输入第一个128位浮点数（-126~127）\n");
	num1 = getfloat(m);
	printf("请输入第二个128位浮点数（-126~127）\n");
	m = 2;
	num2 = getfloat(m);
	sum = num1 + num2;
	printf("浮点数 %f + %f = %f\n", num1, num2, sum);
	getchar();

	return 0;

}
float getfloat(int m) {
	float num;
	bool flag = true;
	do {
		scanf("%f", &num);
		if (getchar() != '\n') {
			printf("输入的第%d个浮点数不合法！请重新输入\n", m);
			flag = true;
		} else {
			if (((int)num <= 127) && ((int)num >= -126)) {
				flag = false;
			} else {
				flag = true;
				printf("输入的第%d个浮点数不合法！请重新输入\n", m);
			}

		}
	} while (flag);
	return num;


}
