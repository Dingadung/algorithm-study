
# RREF를 찾는 함수
def UT(m,col):
    # 제일 먼저 augmented matrix를 출력을 함
    file2 = open("seol/output.txt", "w", encoding='utf-8')
    file2.writelines('augmented matrix = \n')
    file2.writelines(str(m))
    file2.writelines('\n\n')
    
    n = len(m)
    col = int(col)
    # lower triangle 0으로 만듬
    file2.writelines('REF => \n')
    for i in range(1,n):
        for j in range(i,n):
            if(m[i-1][i-1] == 0 or m[i-1][j] == 0):
                continue
            lam = -m[i-1][i-1]/m[j][i-1]
            
            for k in  range(col):
                m[j][k] = m[j][k]*lam
                m[j][k] = m[j][k]+m[i-1][k]
            file2.writelines(str(m))
            file2.writelines('\n')
    # backward gauss 
    file2.writelines('RREF => \n')
    for i in range(n-1,0,-1):
        for j in range(0,i):
            if(m[i][i] == 0 or m[j][i] == 0):
                file2.writelines(str(m))
                file2.writelines('\n')
            else:    
                lam = -m[i][i]/m[j][i]
                for k in range(col):
                    m[j][k] = m[j][k]*lam
                    m[j][k] = m[j][k]+m[i][k]
                file2.writelines(str(m))
                file2.writelines('\n')
    # pivot의 값을 1로 만들어 줌
    for i in range(n):
        if(m[i][i] != 0 and m[i][i] != 1):
            lam = 1/m[i][i]
            for k in range(col):
                m[i][k] = m[i][k]*lam
    file2.writelines(str(m))
    file2.writelines('\n')
    file2.close()






if __name__ == '__main__':

    file = open("seol/input.txt", "r", encoding='utf-8')
    strings = file.readlines()
    strings = [line.rstrip('\n') for line in strings]
    list = []
    list3 = []
    cnt = len(strings)
    for i in range(cnt):
        if(i == 0):
            list3 = strings[i].split()
        else:  
            list2 = strings[i].split()  
            list2 = [float(i) for i in list2]
            list.append(list2)
    UT(list,list3[1])

    #한번의 RREF를 구한 후 반복을 계속하고 싶다면 1을 입력합니다.
    #그리고 y나 yes를 입력한 수 파일의 이름만을 입력을 하면 output.txt 파일에 결과가 출력됩니다.

    # 그리고 다시 반복을 하고 싶다면 다시 숫자 1을 입력 한다면 반복이 계속 됩니다.
    #다음 부터는 위의 절차를 계속 하면 됩니다.
    k = int(input())
    while k ==1:
        kk = input()  #y 나 yes를 입력함
        if kk == 'y' or kk == 'yes':
            #새로운 파일이름 입력
            newfile = input()
            newfile = ("seol/" + newfile) #c rrrf
            file = open(newfile,"r",encoding='utf-8')
            strings = file.readlines()
        strings = [line.rstrip('\n') for line in strings]
        list = []
        list3 = []
        cnt = len(strings)
        for i in range(cnt):
            if(i == 0):
                list3 = strings[i].split()
            else:  
                list2 = strings[i].split()  
                list2 = [float(i) for i in list2]
                list.append(list2)
        UT(list,list3[1])
        k = int(input())
