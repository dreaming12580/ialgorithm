
def calc_pi(t):
  pi = [0] * len(t)
  j = 0
  for i in range(1, len(t)):
    while j > 0 and t[i] != t[j]:
      j = pi[j - 1]
    if t[i] == t[j]:
      j += 1
    pi[i] = j
  return pi


def kmp(s, t):
  pi = calc_pi(t)
  j = 0
  for i, c in enumerate(s):
    while j > 0 and t[j] != c:
      j = pi[j - 1]
    if t[j] == c:
      j += 1
    if j == len(t):
      return i - j + 1

  return -1


