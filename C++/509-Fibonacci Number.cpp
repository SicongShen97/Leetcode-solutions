//��̬�滮
//1.ȷ��dp�����Լ��±�ĺ���: ��i������쳲�������ֵ��dp[i]
//2.ȷ�����ƹ�ʽ: dp[i] = dp[i - 1] + dp[i - 2]
//3.dp������γ�ʼ��: dp[0] = 0, dp[1] = 1
//4.ȷ������˳�򣺴�ǰ�������
//5.�����Ƶ�dp����
//ʱ�临�Ӷȣ�O(n)
//�ռ临�Ӷȣ�O(1)

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int dp[2];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};

//�ݹ�
// 1.�ݹ��ϵ
// 2.��ֹ����
// ʱ�临�Ӷȣ�O(2^n)
// �ռ临�Ӷȣ�O(n)�������˱��������ʵ�ֵݹ��ϵͳջ��ռ�ռ�
class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1) return n;
        return fib(n - 1) + fib(n - 2);
    }
};