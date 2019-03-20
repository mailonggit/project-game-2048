#include "File.h"

void permutation(SCORE &A, SCORE &B)
{
	SCORE temp = A;
	A = B;
	B = temp;
}

void arrange(vector<SCORE> &s)
{
	int size = s.size();
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (s[i].score < s[j].score)
				permutation(s[i], s[j]);
		}
	}
}

void File(int hightScore)
{
	system("cls");
	HienConTro();
	vector<Score> topScore;

	ifstream FileIn("fileData\\hightScore.in", ios::in); //Mở file hight score;
	if (FileIn.fail()) // Thất bại => lần đầu play;
	{
		SCORE s;
		ofstream FileOut("fileData\\hightScore.in", ios::out); // Tạo mới file hight socre;
		do {
			gotoxy(2, 5); cout << "Enter the name(length < 7): ";
			cin >> s.name;
			if (s.name.size() >= 7)
			{
				gotoxy(2, 5);  cout << "                                        ";
			}
		} while (s.name.size() >= 7);
		

		for (int i = 0; i < 5; i++) //Add vào file; 
		{
			if (i == 0)
				FileOut << s.name << " " << hightScore << endl;
			else
				FileOut << "Empty" << " " << "0" << endl; // Cho có đủ 5 hight score;
		}
		FileOut.close();

		return;
	}
	else
	{
		//Đọc file vào vector topScore
		while (!FileIn.eof())
		{
			SCORE s;
			FileIn >> s.name >> s.score;
			topScore.push_back(s);
		}
	}
	FileIn.close();

	//TH k phải play lần đầu;
	SCORE s;
	do {
		gotoxy(2, 5); cout << "Enter the name(length < 7): ";
		cin >> s.name;
		if (s.name.size() >= 7)
		{
			gotoxy(2, 5);  cout << "                                        ";
		}
	} while (s.name.size() >= 7);
	s.score = hightScore;
	topScore.push_back(s);
	arrange(topScore); 
	
	//Ghi lại vào file sau khi sắp xếp;
	ofstream FileOut("fileData\\hightScore.in", ios::out);
	FileOut.clear();

	int maxLength;
	if (topScore.size() < 5)
		maxLength = topScore.size();
	else
	    maxLength = 5; // Top 5 hight score;
	for (int i = 0; i < maxLength; i++)
	{
		FileOut << topScore[i].name << " " << topScore[i].score << " ";
	}
	FileOut.close();
}