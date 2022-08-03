'''
贪心：从后往前遍历，当strNum[i-1]>strNum[i]时，strNum[i-1]--, strNum[i] = 1
'''
class Solution:
    def monotoneIncreasingDigits(self, n: int) -> int:
        strNum = list(str(n))
        flag = len(strNum)
        for i in range(len(strNum)-1, 0, -1):
            if strNum[i] < strNum[i-1]:
                strNum[i-1] = str(int(strNum[i-1]) - 1)
                flag = i
        for i in range(flag, len(strNum)):
            strNum[i] = '9'
        return int(''.join(strNum))