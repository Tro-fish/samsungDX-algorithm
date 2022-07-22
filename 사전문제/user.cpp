#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int target;

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

GradeOneMale grade_1_male;

GradeTwoMale grade_2_male;

GradeThreeMale grade_3_male;

GradeOneFemale grade_1_female;

GradeTwoFemale grade_2_female;

GradeThreeFemale grade_3_female;

bool minCheck[6];

bool compare(Student x, Student y)
{ //매달수에 따른 내림차순 정렬
    if (x.score < y.score)
    {                             //금매달 수 같으면    //은매달 수 같으면
        return x.score < y.score; //동매달 수 비교
    }
    else
        return x.score > y.score; //금매달 수 비교
}

bool finds(Student x)
{
    return x.id == target;
}

void init()
{
    for(int i=0;i<6;i++)
    {
        minCheck[i] = false;
    }
    grade_1_male.max = 0;
    grade_1_male.maxID = 0;
    grade_1_male.min = 0;
    grade_1_male.minID = 0;
    grade_1_male.student.clear();
    vector<Student>().swap(grade_1_male.student);

    grade_2_male.max = 0;
    grade_2_male.maxID = 0;
    grade_2_male.min = 0;
    grade_2_male.minID = 0;
    grade_2_male.student.clear();
    vector<Student>().swap(grade_2_male.student);

    grade_3_male.max = 0;
    grade_3_male.maxID = 0;
    grade_3_male.min = 0;
    grade_3_male.minID = 0;
    grade_3_male.student.clear();
    vector<Student>().swap(grade_3_male.student);

    grade_1_female.max = 0;
    grade_1_female.maxID = 0;
    grade_1_female.min = 0;
    grade_1_female.minID = 0;
    grade_1_female.student.clear();
    vector<Student>().swap(grade_1_female.student);

    grade_2_female.max = 0;
    grade_2_female.maxID = 0;
    grade_2_female.min = 0;
    grade_2_female.minID = 0;
    grade_2_female.student.clear();
    vector<Student>().swap(grade_2_female.student);

    grade_3_female.max = 0;
    grade_3_female.maxID = 0;
    grade_3_female.min = 0;
    grade_3_female.minID = 0;
    grade_3_female.student.clear();
    vector<Student>().swap(grade_3_female.student);

    return;
}

int add(int mId, int mGrade, char mGender[7], int mScore)
{
    Student temp;
    temp.id = mId;
    temp.score = mScore;
    if (mGrade == 1 && !strcmp(mGender, "male"))
    {
        grade_1_male.student.push_back(temp);
        if (grade_1_male.max < mScore)
        {
            grade_1_male.max = mScore;
            grade_1_male.maxID = mId;
        }
        else if (grade_1_male.max == mScore)
        {
            if (grade_1_male.maxID < mId)
            {
                grade_1_male.maxID = mId;
            }
        }
        return grade_1_male.maxID;
    }
    else if (mGrade == 2 && !strcmp(mGender, "male"))
    {
        grade_2_male.student.push_back(temp);
        if (grade_2_male.max < mScore)
        {
            grade_2_male.max = mScore;
            grade_2_male.maxID = mId;
        }
        else if (grade_2_male.max == mScore)
        {
            if (grade_2_male.maxID < mId)
            {
                grade_2_male.maxID = mId;
            }
        }
        return grade_2_male.maxID;
    }
    else if (mGrade == 3 && !strcmp(mGender, "male"))
    {
        grade_3_male.student.push_back(temp);
        if (grade_3_male.max < mScore)
        {
            grade_3_male.max = mScore;
            grade_3_male.maxID = mId;
        }
        else if (grade_3_male.max == mScore)
        {
            if (grade_3_male.maxID < mId)
            {
                grade_3_male.maxID = mId;
            }
        }
        return grade_3_male.maxID;
    }
    else if (mGrade == 1 && !strcmp(mGender, "female"))
    {
        grade_1_female.student.push_back(temp);
        if (grade_1_female.max < mScore)
        {
            grade_1_female.max = mScore;
            grade_1_female.maxID = mId;
        }
        else if (grade_1_female.max == mScore)
        {
            if (grade_1_female.maxID < mId)
            {
                grade_1_female.maxID = mId;
            }
        }
        return grade_1_female.maxID;
    }
    else if (mGrade == 2 && !strcmp(mGender, "female"))
    {
        grade_2_female.student.push_back(temp);
        if (grade_2_female.max < mScore)
        {
            grade_2_female.max = mScore;
            grade_2_female.maxID = mId;
        }
        else if (grade_2_female.max == mScore)
        {
            if (grade_2_female.maxID < mId)
            {
                grade_2_female.maxID = mId;
            }
        }
        return grade_2_female.maxID;
    }
    else
    {
        grade_3_female.student.push_back(temp);
        if (grade_3_female.max < mScore)
        {
            grade_3_female.max = mScore;
            grade_3_female.maxID = mId;
        }
        else if (grade_3_female.max == mScore)
        {
            if (grade_3_female.maxID < mId)
            {
                grade_3_female.maxID = mId;
            }
        }
        return grade_3_female.maxID;
    }
    return 0;
}

int remove(int mId)
{
    target = mId;

    auto onemale = find_if(grade_1_male.student.begin(), grade_1_male.student.end(), finds);
    // 1학년 남자에서 못찾았다면
    if (onemale - grade_1_male.student.begin() == 0)
    {
        auto twomale = find_if(grade_2_male.student.begin(), grade_2_male.student.end(), finds);
        // 2학년 남자에서 못찾았다면
        if (twomale - grade_2_male.student.begin() == 0)
        {
            auto threemale = find_if(grade_3_male.student.begin(), grade_3_male.student.end(), finds);
            // 3학년 남자에서 못찾았다면
            if (threemale - grade_3_male.student.begin() == 0)
            {
                auto onefemale = find_if(grade_1_male.student.begin(), grade_1_male.student.end(), finds);
                // 1학년 여자한테서 못찾았다면
                if (onefemale - grade_1_female.student.begin() == 0)
                {
                    auto twofemale = find_if(grade_2_female.student.begin(), grade_2_female.student.end(), finds);
                    // 2학년 여자한테서 못찾았다면
                    if (twofemale - grade_2_female.student.begin() == 0)
                    {
                        // 3학년 여자한테서 못찾았다면
                        auto threefemale = find_if(grade_2_female.student.begin(), grade_2_female.student.end(), finds);
                        if (threefemale - grade_3_female.student.begin() == 0)
                        {
                            return 0;
                        }
                        // 3학년 여자한테서 찾았다면
                        else
                        {
                            int find_index = threefemale - grade_3_female.student.begin();
                            if (grade_3_female.student[find_index].id == grade_3_female.minID)
                            {
                                sort(grade_3_female.student.begin(), grade_3_female.student.end(), compare);
                                minCheck[5] = true;
                                grade_3_female.minID = grade_3_female.student[0].id;
                                grade_3_female.min = grade_3_female.student[0].score;
                                return grade_3_female.student[0].id;
                            }
                            grade_3_female.student.erase(grade_3_female.student.begin() + find_index); // 삭제
                            return grade_3_female.minID;
                        }
                    }
                    // 2학년 여자한테서 찾았다면
                    else
                    {
                        int find_index = twofemale - grade_2_female.student.begin();
                        if (grade_2_female.student[find_index].id == grade_2_female.minID)
                        {
                            sort(grade_2_female.student.begin(), grade_2_female.student.end(), compare);
                            minCheck[4] = true;
                            grade_2_female.minID = grade_2_female.student[0].id;
                            grade_2_female.min = grade_2_female.student[0].score;
                            return grade_2_female.student[0].id;
                        }
                        grade_2_female.student.erase(grade_2_female.student.begin() + find_index); // 삭제
                        return grade_2_female.minID;
                    }
                }
                // 1학년 여자한테서 찾았다면
                else
                {
                    int find_index = onefemale - grade_1_female.student.begin();
                    if (grade_1_female.student[find_index].id == grade_1_female.minID)
                    {
                        sort(grade_1_female.student.begin(), grade_1_female.student.end(), compare);
                        minCheck[3] = true;
                        grade_1_female.minID = grade_1_female.student[0].id;
                        grade_1_female.min = grade_1_female.student[0].score;
                        return grade_1_female.student[0].id;
                    }
                    grade_1_female.student.erase(grade_1_female.student.begin() + find_index); // 삭제
                    return grade_1_female.minID;
                }
            }
            // 3학년 남자에서 찾았다면
            else
            {
                int find_index = onemale - grade_3_male.student.begin();
                if (grade_3_male.student[find_index].id == grade_3_male.minID)
                {
                    sort(grade_3_male.student.begin(), grade_3_male.student.end(), compare);
                    minCheck[2] = true;
                    grade_3_male.minID = grade_3_male.student[0].id;
                    grade_3_male.min = grade_3_male.student[0].score;
                    return grade_3_male.student[0].id;
                }
                grade_3_male.student.erase(grade_3_male.student.begin() + find_index); // 삭제
                return grade_3_male.minID;
            }
        }
        // 2학년 남자에서 찾았다면
        else
        {
            int find_index = onemale - grade_2_male.student.begin();
            if (grade_2_male.student[find_index].id == grade_2_male.minID)
            {
                
                sort(grade_2_male.student.begin(), grade_2_male.student.end(), compare);
                minCheck[1] = true;
                grade_2_male.minID = grade_2_male.student[0].id;
                grade_2_male.min = grade_2_male.student[0].score;
                return grade_2_male.student[0].id;
            }
            grade_2_male.student.erase(grade_2_male.student.begin() + find_index); // 삭제
            return grade_2_male.minID;
        }
    }
    // 1학년 남자에서 찾았다면
    else
    {
        int find_index = onemale - grade_1_male.student.begin();
        if (grade_1_male.student[find_index].id == grade_1_male.minID)
        {
            sort(grade_1_male.student.begin(), grade_1_male.student.end(), compare);
            minCheck[0] = true;
            grade_1_male.minID = grade_1_male.student[0].id;
            grade_1_male.min = grade_1_male.student[0].score;
            return grade_1_male.student[0].id;
        }
        grade_1_male.student.erase(grade_1_male.student.begin() + find_index); // 삭제
        return grade_1_male.minID;
    }

    return 0;
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore)
{
    int minest = 10000000;
    int minsestID = -1;
    for (int j = 0; j < mGradeCnt; j++)
    {
        for (int k = 0; k < mGenderCnt; k++)
        {
            if (mGrade[j] == 1 && !strcmp(mGender[k], "male"))
            {
                if(minCheck[0] == false)
                    sort(grade_1_male.student.begin(), grade_1_male.student.end(), compare);
                for (int i = 0; i < grade_1_male.student.size(); i++)
                {
                    if (grade_1_male.student[i].score >= mScore)
                    {
                        if (grade_1_male.student[i].score < minest)
                        {
                            minest = grade_1_male.student[i].score;
                            minsestID = grade_1_male.student[i].id;
                        }
                        else if (grade_1_male.student[i].score == minest)
                        {
                            if (minsestID > grade_1_male.student[i].id)
                            {
                                minsestID = grade_1_male.student[i].id;
                            }
                        }
                        break;
                    }
                }
            }
            else if (mGrade[j] == 2 && !strcmp(mGender[k], "male"))
            {
                if(minCheck[1] == false)
                    sort(grade_2_male.student.begin(), grade_2_male.student.end(), compare);
                for (int i = 0; i < grade_2_male.student.size(); i++)
                {
                    if (grade_2_male.student[i].score >= mScore)
                    {
                        if (grade_2_male.student[i].score < minest)
                        {
                            minest = grade_2_male.student[i].score;
                            minsestID = grade_2_male.student[i].id;
                        }
                        else if (grade_2_male.student[i].score == minest)
                        {
                            if (minsestID > grade_2_male.student[i].id)
                            {
                                minsestID = grade_2_male.student[i].id;
                            }
                        }
                        break;
                    }
                }
            }
            else if (mGrade[j] == 3 && !strcmp(mGender[k], "male"))
            {
                if(minCheck[2] == false)
                    sort(grade_3_male.student.begin(), grade_3_male.student.end(), compare);
                for (int i = 0; i < grade_3_male.student.size(); i++)
                {
                    if (grade_3_male.student[i].score >= mScore)
                    {
                        if (grade_3_male.student[i].score < minest)
                        {
                            minest = grade_3_male.student[i].score;
                            minsestID = grade_3_male.student[i].id;
                        }
                        else if (grade_3_male.student[i].score == minest)
                        {
                            if (minsestID > grade_3_male.student[i].id)
                            {
                                minsestID = grade_3_male.student[i].id;
                            }
                        }
                        break;
                    }
                }
            }
            else if (mGrade[j] == 1 && !strcmp(mGender[k], "female"))
            {
                if(minCheck[3] == false)
                    sort(grade_1_female.student.begin(), grade_1_female.student.end(), compare);
                for (int i = 0; i < grade_1_female.student.size(); i++)
                {
                    if (grade_1_female.student[i].score >= mScore)
                    {
                        if (grade_1_female.student[i].score < minest)
                        {
                            minest = grade_1_female.student[i].score;
                            minsestID = grade_1_female.student[i].id;
                        }
                        else if (grade_1_female.student[i].score == minest)
                        {
                            if (minsestID > grade_1_female.student[i].id)
                            {
                                minsestID = grade_1_female.student[i].id;
                            }
                        }
                        break;
                    }
                }
            }
            else if (mGrade[j] == 2 && !strcmp(mGender[k], "female"))
            {
                if(minCheck[4] == false)
                    sort(grade_2_female.student.begin(), grade_2_female.student.end(), compare);
                for (int i = 0; i < grade_2_female.student.size(); i++)
                {
                    if (grade_2_female.student[i].score >= mScore)
                    {
                        if (grade_2_female.student[i].score < minest)
                        {
                            minest = grade_2_female.student[i].score;
                            minsestID = grade_2_female.student[i].id;
                        }
                        else if (grade_2_female.student[i].score == minest)
                        {
                            if (minsestID > grade_2_female.student[i].id)
                            {
                                minsestID = grade_2_female.student[i].id;
                            }
                        }
                        break;
                    }
                }
            }
            else if (mGrade[j] == 3 && !strcmp(mGender[k], "female"))
            {
                if(minCheck[5] == false)
                    sort(grade_3_female.student.begin(), grade_3_female.student.end(), compare);
                for (int i = 0; i < grade_3_female.student.size(); i++)
                {
                    if (grade_3_female.student[i].score >= mScore)
                    {
                        if (grade_3_female.student[i].score < minest)
                        {
                            minest = grade_3_female.student[i].score;
                            minsestID = grade_3_female.student[i].id;
                        }
                        else if (grade_3_female.student[i].score == minest)
                        {
                            if (minsestID > grade_3_female.student[i].id)
                            {
                                minsestID = grade_3_female.student[i].id;
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
    return minsestID;
}

#define CMD_INIT 100
#define CMD_ADD 200
#define CMD_REMOVE 300
#define CMD_QUERY 400

static bool run() {
	int q;
	scanf("%d", &q);

	int id, grade, score;
	char gender[7];
	int cmd, ans, ret;
	bool okay = false;

	for (int i = 0; i < q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
			case CMD_INIT:
				init();
				okay = true;
				break;
			case CMD_ADD:
				scanf("%d %d %s %d %d", &id, &grade, gender, &score, &ans);
				ret = add(id, grade, gender, score);
				if (ans != ret)
					okay = false;
				break;
			case CMD_REMOVE:
				scanf("%d %d", &id, &ans);
				ret = remove(id);
				if (ans != ret)
					okay = false;
				break;
			case CMD_QUERY: {
				int gradeCnt, genderCnt;
				int gradeArr[3];
				char genderArr[2][7];
				scanf("%d", &gradeCnt);
				if (gradeCnt == 1) {
					scanf("%d %d", &gradeArr[0], &genderCnt);
				} else if (gradeCnt == 2) {
					scanf("%d %d %d", &gradeArr[0], &gradeArr[1], &genderCnt);
				} else {
					scanf("%d %d %d %d", &gradeArr[0], &gradeArr[1], &gradeArr[2], &genderCnt);
				}
				if (genderCnt == 1) {
					scanf("%s %d %d", genderArr[0], &score, &ans);
				} else {
					scanf("%s %s %d %d", genderArr[0], genderArr[1], &score, &ans);
				}
				ret = query(gradeCnt, gradeArr, genderCnt, genderArr, score);
				if (ans != ret)
					okay = false;
				break;
			}
			default:
				okay = false;
				break;
		}
	}
	return okay;
}

int main() {
    init();
    /*
	setbuf(stdout, NULL);
	freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}
    */
	return 0;
}