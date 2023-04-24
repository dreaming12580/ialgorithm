




bool isValid(string str) {
  stack<char> left;
  for (char c : str) {
    if (c == '(' || c == '{' || c == '[') {
      left.push(c);
    } else {
      // 字符c 是右括号
      if (!left.empty() && leftOf(c) == left.top()) {
        left.pop();
      } else {
        // 和最近的左括号不匹配
        return false;
      }
    }
  }
  // 是否所有的左括号都被匹配了
  return left.empty();
}

char leftOf(char c) {
  if (c == '}') return '{';
  if (c == ')') return '(';
  return '[';
}












