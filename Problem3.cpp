#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;

    // 가장 작은 나눔값을 산출하라.
    // 해는 항상 2이상의 수이다.
    int divisor = 2;
    while (true)
    {
        if (n - 1 % divisor == 0) //완전히 나누어 떨어진다면 리턴
            return divisor;
        else
            divisor += 1;
    }
}

int main() {
    cout << solution(10) << endl;
    cout << solution(12) << endl;
}