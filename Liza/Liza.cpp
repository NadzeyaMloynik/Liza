#include "lib.h"

vector <Book> book;
vector <ScientificWork> scienWork;

int maxNumPaper() {

	int max = book[0].getNumPaper();
	int temp, j = 0;
	for (int i = 0; i < book.size(); i++) {
		temp = book[i].getNumPaper();
		if (temp > max) {
			max = temp;
			j = i;
		}
	}
	return j;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool isCorrect = 0;
	int i;
	while (isCorrect == 0) {
		fstream inf("inf.txt", fstream::out);
		system("cls");
		cout << "Выберите пункт меню:" << endl
			<< "1. Ввести информацию о книгах" << endl
			<< "2. Ввести информацию о научной работе" << endl
			<< "3. Определить продукцию с самым большим кол. страниц" << endl
			<< "4. Вывести информацию о книгах" << endl
			<< "5. Вывести информацию о научных работах" << endl
			<< "0. Завершить работу программы" << endl;
		string a, choice_s;
		a = getchar();
		getline(cin, choice_s);
		system("cls");// clear screen
		if (a != "\n")
			choice_s.insert(0, a);
		if (choice_s.size() > 2 || (choice_s[0] < '0' || choice_s[0]>'5')) {
			isCorrect = 0;
			cout << "Пункт меню выбран некорректно." << endl << "Попробуйте еще раз." << endl;
			system("pause");
			system("cls");
		}
		else {
			char choice = choice_s[0];

			switch (choice)
			{
			case '1':
				book.push_back(Book());
				break;
			case '2':
				scienWork.push_back(ScientificWork());
				break;
			case '3':
				i = maxNumPaper();
				cout << "Книга с максимальным количеством страниц: " << endl;
				book[i].showInf();
				getchar();
				break;
			case'4':
				for (i = 0; i < book.size(); i++) {
					cout << "№" << i + 1 << endl;
					inf << "Книга №" << i + 1 << endl;
					book[i].showInf();
					inf << endl;
					inf.close();
				}
				getchar();
				break;
			case'5':
				for (i = 0; i < scienWork.size(); i++) {
					cout << "№" << i + 1 << endl;
					inf << "Научная работа №" << i + 1 << endl;
					scienWork[i].showInf();
					inf << endl;
					inf.close();
				}
				getchar();
				break;
			case '0':
				cout << "Работа программы завершена" << endl;
				system("pause");
				isCorrect = 1;
				break;
			}

		}
	}
}