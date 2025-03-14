#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int studentNum = 0;
	cin >> studentNum;

	int roomCapacity = 0;
	cin >> roomCapacity;

	int gender = 0;
	int grade = 0;
	int maxGrade = 0;

	vector<vector<int>> studentArr;
	studentArr.resize(studentNum);

	for (int i = 0; i < studentNum; i++)
	{
		cin >> gender;
		cin >> grade;

		studentArr[i] = { gender, grade };

		if (grade > maxGrade)
		{
			maxGrade = grade;
		}
	}

	// 학년별 남녀 수를 담아두는 벡터
	vector<vector<int>> gradeArr;
	gradeArr.resize(maxGrade);

	for (int i = 0; i < maxGrade; i++)
	{
		gradeArr[i] = { 0,0 };
	}

	for (int i = 0; i < studentNum; i++)
	{
		if (!studentArr[i][0])
		{
			gradeArr[studentArr[i][1] - 1][0]++;
		}
		else
		{
			gradeArr[studentArr[i][1] - 1][1]++;
		}
	}

	int roomNum = 0;
	for (int i = 0; i < maxGrade; i++)
	{
		roomNum += gradeArr[i][0] % roomCapacity == 0 ? gradeArr[i][0] / roomCapacity : gradeArr[i][0] / roomCapacity + 1;
		roomNum += gradeArr[i][1] % roomCapacity == 0 ? gradeArr[i][1] / roomCapacity : gradeArr[i][1] / roomCapacity + 1;
	}

	cout << roomNum;

	return 0;
}