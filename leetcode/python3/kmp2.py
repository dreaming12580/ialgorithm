




def prefix_function(s):
  n = len(s)
  pi = [0] * n
  for i in range(1, n):
     for j in range(i , -1, -1):
         if s[0 : j] == s[i - j + 1: i + 1]:
             pi[i] = j
             break
  return pi

def prefix_function2(s):
  n = len(s) 
  pi = [0] * n 
  for i in range(1, n):
    for j in range(pi[i - 1] + 1, -1, -1):
      if s[0: j] == s[i - j + 1: i + 1]:
        pi[i] = j
        break
  return pi

def prefix_function3(s):
  n = len(s)
  pi = [0] * n
  for i in range(1, n):
    j = pi[i - 1]
    while j > 0 and s[i] != s[j]:
      j = pi[j - 1]
    if s[i] == s[j]:
      j += 1
    pi[i] = j
  return pi









