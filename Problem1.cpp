
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {

    unordered_map<string, int> reportMap1; // 각 아이디별 신고당한 횟수
    unordered_map<string, vector<string>> reportMap2; // 각 아이디별 신고한 아이디를 정리하는 맵
    unordered_map<string, unordered_map<string, int>> reportMap3;
    vector<int> result;

    for (int i = 0; i < id_list.size(); i++)
    {
        vector<string> element1;
        unordered_map<string, int> element2;
        reportMap1.insert(make_pair(id_list[i], 0)); // 초기화
        reportMap2.insert(make_pair(id_list[i], element1));
        reportMap3.insert(make_pair(id_list[i], element2));
    }
        
    for (int i = 0; i < report.size(); i++)
    {
        int index = report[i].find(' '); // 공백을 찾아내고 해당 인덱스를 반환합니다.
        int indexPlus = index + 1;
        //Map1의 카운트를 올리기 전에 Map2에 가서 키가 존재하는지 확인합니다.
        string reporter = report[i].substr(0, index);
        string respondent = report[i].substr(indexPlus, report[i].size()- indexPlus);
        reportMap2[reporter].push_back(respondent);
        if (reportMap3[reporter].find(respondent) != reportMap3[reporter].end()) // 있다는 것 자체가 이미 1이라는 것...
        {
            continue;
        }
        else
        {
            reportMap3[reporter].insert(make_pair(respondent, 1));
            reportMap1[respondent] += 1; // 신고당한 사람
        }
    }
    
    for (int i = 0; i < id_list.size(); i++)
    {
        vector<string> reportList = reportMap2[id_list[i]];
        sort(reportList.begin(), reportList.end());
        vector<string>::iterator uniques = unique(reportList.begin(), reportList.end());
        reportList.erase(uniques, reportList.end());
        int count = 0;
        for (int j = 0; j < reportList.size(); j++)
        {
            if (reportMap1[reportList[j]] >= k)
            {
                count += 1;
            }
        }
        result.push_back(count);
    }
   
    return result;
}

int main()
{
    vector<string> id_list = { "muzi", "frodo", "apeach", "neo","ryan" };
    vector<string> report = {"ryan frodo"};
    //vector<string> id_list = { "muzi", "frodo", "apeach", "neo","ryan"};
    //vector<string> report = {"ryan frodo","muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi","muzi frodo","apeach muzi","neo muzi"};
    int k = 2;

    solution(id_list, report, k);
}