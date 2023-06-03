#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int grading(vector<int>& student, vector<int>& answers)
{
    int result = 0;
    for(int i = 0; i < answers.size(); i++)
    {
        int idx = i;
        if(idx >= student.size())
        {
            idx = idx % student.size();
        }
        if(student[idx] == answers[i])
        {
            result++;
        }
    }
    return result;
}
vector<int> solution(vector<int> answers) {
    vector<pair<int, int>> score;
    vector<int> answer;
    vector<int> student1;
    vector<int> student2;
    vector<int> student3;
    student1.insert(student1.end(), {1, 2, 3, 4, 5});
    student2.insert(student2.end(), {2, 1, 2, 3, 2, 4, 2, 5});
    student3.insert(student3.end(), {3, 3, 1, 1, 2, 2, 4, 4, 5, 5});
    
    score.push_back(make_pair(grading(student1, answers), 1));
    score.push_back(make_pair(grading(student2, answers), 2));    
    score.push_back(make_pair(grading(student3, answers), 3));
    
    sort(score.rbegin(), score.rend());
    
     if(score[0].first == score[1].first)
    {
        answer.push_back(score[0].second);
        answer.push_back(score[1].second);
        if(score[1].first == score[2].first)
        {
            answer.push_back(score[2].second);
        }
         sort(answer.begin(), answer.end());
    }
    else
    {
        answer.push_back(score[0].second);
    }
    
    return answer;
}