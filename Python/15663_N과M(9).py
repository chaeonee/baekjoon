def getSeries(N, M, num, d, visit, result):
  if d == M:
    for r in result:
      print(r, end=' ')
    print()
    return

  pre_num = -1
  for i in range(N):
    if visit[i] or pre_num == num[i]:
      continue
    pre_num = num[i]
    visit[i] = True
    result.append(num[i])
    getSeries(N,M,num,d+1,visit,result)
    visit[i] = False
    result.pop()

if __name__ == '__main__':
  N, M = list(map(int,input().split()))
  num = list(map(int,input().split()))
  num.sort()

  getSeries(N,M,num,0,[False]*N,[])
