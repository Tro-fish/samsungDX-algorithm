#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

int target = 1;

struct Student
{
    int id;
    int score;
};

struct GradeOneMale
{
    int max;
    int maxID;
    int min;
    int minID;
    vector<Student> student;
};

bool compare(Student x, Student y) {     //매달수에 따른 내림차순 정렬
	if (x.score > y.score) {            //금매달 수 같으면    //은매달 수 같으면
			return x.score > y.score; //동매달 수 비교
	}
	else return x.score < y.score;       //금매달 수 비교
}

bool finds(Student x)
{
    return x.id == target;
}

int main(void)
{
    GradeOneMale gradeone;
    for(int i=0;i<10;i++)
    {
        Student temp;
        temp.score = i;
        temp.id = i;
        gradeone.student.push_back(temp);
    }
    sort(gradeone.student.begin(),gradeone.student.end(),compare);
    for(int i=0;i<10;i++)
    {
        cout<<gradeone.student[i].score<<endl;
    }
    auto it = find_if(gradeone.student.begin(),gradeone.student.end(),finds);
    cout << it - gradeone.student.begin() << endl;
    //cout<<gradeone.student.end()<<endl;
/*
    vector<int> v;
    v.push_back(46);
    v.push_back(67);
    v.push_back(184);
    v.push_back(4);
    v.push_back(17);
    v.push_back(53);
    int a = 17;
    auto it = find(v.begin(), v.end(), a);
    int x = it - v.begin();
    cout << it - v.begin() << endl;
    v.erase(v.begin() + x);
    cout << v[4] << endl;
    */
}