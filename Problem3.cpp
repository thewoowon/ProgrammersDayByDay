#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;

    // ���� ���� �������� �����϶�.
    // �ش� �׻� 2�̻��� ���̴�.
    int divisor = 2;
    while (true)
    {
        if (n - 1 % divisor == 0) //������ ������ �������ٸ� ����
            return divisor;
        else
            divisor += 1;
    }
}

int main() {
    cout << solution(10) << endl;
    cout << solution(12) << endl;
}