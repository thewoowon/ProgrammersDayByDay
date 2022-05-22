#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
	// �ϴ� ���� ū ���̴� Ȯ���ؾ��Ѵ�.
	int widthMax = 0;
	int heightMax = 0;
	// ȸ���� �����ϹǷ� ���ΰ� ���κ��� Ŀ�� �� �ְ� �ٲ۴�.
	for (int i = 0; i < sizes.size(); i++)
	{
		if (sizes[i][1] <= sizes[i][0])
		{
			int swap = sizes[i][0];
			sizes[i][0] = sizes[i][1];
			sizes[i][1] = swap;
		}
		if (sizes[i][0] > widthMax)
			widthMax = sizes[i][0];
		if (sizes[i][1] > heightMax)
			heightMax = sizes[i][1];
	}
	answer = widthMax * heightMax;

    return answer;
}


int main() {
	
}