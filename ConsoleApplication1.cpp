#include <iostream>
#include <fstream>
//#include <string>

using namespace std;

int main()
{
	ifstream file("temp.txt");
	ofstream data("newTemp.txt");
	ofstream wint("winter.txt");
	ofstream summ("summer.txt");
	int value = 0;
	int colCounter = 2;
	const int y = 110;
	double* years = new double[y];
	double* winter = new double[y];
	double* summer = new double[y];
	int year;
	file >> year >> year;
	int daysCounter = 1;
	int yearsCounter = 0;
	int sum = 0;
	int wSum = 0;
	int sSum = 0;
	int month;
	int goodData = 0;

	while (!file.eof()) {
		file >> value;
		if (file.fail())
			break;
		colCounter++;
		if (colCounter == 2) {
			if (value != year && goodData > 330) {
				years[yearsCounter] = sum / daysCounter / 10;
				winter[yearsCounter] = wSum / 900;
				summer[yearsCounter] = sSum / 900;
				data << year << " " << years[yearsCounter] << endl;
				wint << year << " " << winter[yearsCounter] << endl;
				summ << year << " " << summer[yearsCounter] << endl;
				cout << year << " summer " << sSum/900 << endl;
				cout << year << " winter " << wSum/900 << endl;
				year = value;
				sum = 0;
				wSum = 0;
				sSum = 0;
				daysCounter = 0;
				yearsCounter++;
			}
		}
		if (colCounter == 3) {
			month = value;
		}
		if (colCounter == 8 && abs(value) < 600) {
			goodData++;
			sum += value;
			if (month == 1 || month == 2 || month == 12) {
				wSum += value;
			}
			if (month >= 6 && month <= 8) {
				sSum += value;
			}
		}
		if (colCounter == 14) {
			if (abs(value) < 600) {
				daysCounter++;
			}
			colCounter = 0;
		}
	}
}