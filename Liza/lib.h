#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <vector>

using namespace std;

class Publication {
	string name;
	float cost;
public:
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
	void setCost(float cost) {
		this->cost = cost;
	}
	float getCost() {
		return cost;
	}

	Publication() {
		cout << "Название продукции: ";
		string a;
		a = getchar();
		getline(cin, name);
		if (a != "\n")
			name.insert(0, a);
		cout << "Стоимость: ";
		cin >> cost;
	}
	void showInf() {
		cout << "Название продукции: " << name << endl
			<< "Стоимость: " << cost << endl;
		fstream inf("inf.txt", fstream::out);
		inf << "Название продукции: " << name << endl
			<< "Стоимость: " << cost << endl;
		inf.close();
	}
};

class ScientificWork : public Publication {
	string scientist;
	string field;
public:

	void setScientist(string scientist) {
		this->scientist = scientist;
	}
	string getScientist() {
		return scientist;
	}
	void setField(string field) {
		this->field = field;
	}

	ScientificWork() {
		cout << "Имя учёного: ";
		string a;
		a = getchar();
		getline(cin, scientist);
		if (a != "\n")
			scientist.insert(0, a);
		cout << "Сфера: ";
		getline(cin, field);
	}
	void showInf() {
		Publication::showInf();
		cout << "Учёный: " << scientist << endl
			<< "Сфера: " << field << endl;
		fstream inf("inf.txt", fstream::out);
		inf << "Учёный: " << scientist << endl
			<< "Сфера: " << field << endl;
		inf.close();
	}

};

class Book : public Publication {
	string author;
	int numPaper;
	int timeInMin;
public:

	void setAuthor(string author) {
		this->author = author;
	}
	string getAuthor() {
		return author;
	}
	void setNumPaper(int numPaper) {
		this->numPaper = numPaper;
	}
	int getNumPaper() {
		return numPaper;
	}
	void setTimeInMin(int timeImMin) {
		this->timeInMin = timeImMin;
	}
	int getTimeInMin() {
		return timeInMin;
	}

	Book() {

		cout << "Имя автора: ";
		cin >> author;
		cout << "Количество страниц: ";
		cin >> numPaper;
		cout << "Время аудиозаписи (в мин.): ";
		cin >> timeInMin;
	}

	void showInf() {
		Publication::showInf();
		cout << "Автор: " << author << endl
			<< "Кол. страниц: " << numPaper << endl
			<< "Время аудиозаписи (в мин.): " << timeInMin << endl;
		fstream inf("inf.txt", fstream::app);
		inf << "Автор: " << author << endl
			<< "Кол. страниц: " << numPaper << endl
			<< "Время аудиозаписи (в мин.): " << timeInMin << endl;
		inf.close();
	}
};
