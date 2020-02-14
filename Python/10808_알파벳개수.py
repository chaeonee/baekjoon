if __name__ == '__main__':
    S = input()
    
    arr = [0]*26 # 알파벳 개수 저장할 배열
    for s in S: # a의 아스키코드 97, 알파벳을 아스키코드로 바꾸기 위해 ord() 사용
        arr[ord(s)-97] += 1
    
    for n in arr:
        print(n, end=' ')