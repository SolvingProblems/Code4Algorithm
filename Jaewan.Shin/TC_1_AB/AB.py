
class AB:
    def createString(self, N, K):

        if self.__checkInitialCondition(N, K) == False:
            return ""

        arrData = ['B'] * N
        if K == 0:
            arrData[N-1] = 'A'
            return ''.join(arrData)

        l_Value = 0
        for i in range(1, N):
            l_Value = (N-i)*i

            if l_Value <= K:
                arrData[i-1] = "A"
                if l_Value == K:
                    return ''.join(arrData)
            else:
                l_Value = (N-i)*(i-1)

                r_value = K - l_Value

                for j in range(i, N):
                    if r_value == (N-j):
                        arrData[j-1] = "A"
                        return ''.join(arrData)

        return ""

    def __checkInitialCondition(self, N, K):
        if N < 2 or N > 50:
            return False
        if K < 0 or K > (N*(N-1)/2):
            return False
        if K > (N-(N/2))*N:
            return False
        return True
    
quiz = AB()

print quiz.createString(3, 2)
print quiz.createString(2, 0)
print quiz.createString(5, 0)
print quiz.createString(5, 8)
print quiz.createString(10, 12)

