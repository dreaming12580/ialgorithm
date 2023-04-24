#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define max 100
string to_String(int n) {
  int m = n;
  char s[max];
  char ss[max];
  int i = 0, j = 0;
  if (n < 0) {
    // 处理负数
    m = 0 - m;
    j = 1;
    ss[0] = '-';
  }

  while (m > 0) {
    s[i++] = m % 10 + '0';
    m /= 10;
  }
  s[i] = '\0';
  i = i - 1;
  while (i >= 0) {
    ss[j++] = s[i--];
  }
  ss[j] = '\0';
  return ss;
}


int main() {
  cout << "please input number:";
  int m;
  cin >> m;
  string s = to_String(m);
  cout << s << endl;
  system("pause");
  return 0;
}









