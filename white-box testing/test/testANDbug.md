环路复杂度：20



数据变化路径

num1—>

add(char num1[], char num2[], char res[])—>

char_to_int(char num[], int begins, int len)—>

get_decimal(char num1[], char num2[])—>

get_decimal_len(char num[])—>

get_dot(char num[])—>

get_integer(char num[])—>

get_integer_len(int x)—>

get_len(char num[])—>

int_to_char(char res[], int x)—>









bug:

1. 有效位数不对：

   - 整数加小数是整数 ：1+1.0=2 

   - 小数加小数是可能整数：1.0+1.0=2

     .............

  2.小数位数多时不正确

​        1+2.000......1(127个0)=3