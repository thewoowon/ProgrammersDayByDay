#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
	// 일단 가장 큰 길이는 확보해야한다.
	int widthMax = 0;
	int heightMax = 0;
	// 회전이 가능하므로 가로가 세로보다 커질 수 있게 바꾼다.
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