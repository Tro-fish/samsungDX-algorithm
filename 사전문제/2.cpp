#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Student
{
    int id;
    int grade;
    int score;
    string gender;
};

struct GradeOneMale
{
    int max;
    int maxID;
    int min;
    int minID;
    vector<Student> student;
};

struct GradeTwoMale
{
    int max;
    int maxID;
    int min;
    int minID;
    vector<Student> student;
};

struct GradeThreeMale
{
    int max;
    int maxID;
    int min;
    int minID;
    vector<Student> student;
};

struct GradeOneFemale
{
    int max;
    int maxID;
    int min;
    int minID;
    vector<Student> student;
};

struct GradeTwoFemale
{
    int max;
    int maxID;
    int min;
    int minID;
    vector<Student> student;
};

struct GradeThreeFemale
{
    int max;
    int maxID;
    int min;
    int minID;
    vector<Student> student;
};

int main(void)
{
    /*
    Student temp1;
    temp1.id = 11;
    temp1.grade = 20;
    temp1.score = 30;
    temp1.gender = "man";
    
    GradeOneMan temp;
    temp.max = 10;
    temp.maxID = 20;
    temp.min = 30;
    temp.minID = 40;
    temp.student.push_back(temp1);
    */
    GradeOneMale grade_1_male;

    GradeTwoMale grade_2_male;

    GradeThreeMale gradde_3_male;

    GradeOneFemale grade_1_female;

    GradeTwoFemale grade_2_female;
    
    GradeThreeFemale grade_3_female;


}