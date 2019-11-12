if __name__ == "__main__":
    N = int(input())
    S = input()
    
    S_sum = 0
    for i in S: #S를 문자로 받아서 더하기(더할 때 숫자로 변환)
        S_sum += int(i)
        
    print(S_sum)