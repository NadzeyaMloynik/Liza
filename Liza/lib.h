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
		cout << "�������� ���������: ";
		string a;
		a = getchar();
		getline(cin, name);
		if (a != "\n")
			name.insert(0, a);
		cout << "���������: ";
		cin >> cost;
	}
	void showInf() {
		cout << "�������� ���������: " << name << endl
			<< "���������: " << cost << endl;
		fstream inf("inf.txt", fstream::out);
		inf << "�������� ���������: " << name << endl
			<< "���������: " << cost << endl;
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
		cout << "��� �������: ";
		string a;
		a = getchar();
		getline(cin, scientist);
		if (a != "\n")
			scientist.insert(0, a);
		cout << "�����: ";
		getline(cin, field);
	}
	void showInf() {
		Publication::showInf();
		cout << "������: " << scientist << endl
			<< "�����: " << field << endl;
		fstream inf("inf.txt", fstream::out);
		inf << "������: " << scientist << endl
			<< "�����: " << field << endl;
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

		cout << "��� ������: ";
		cin >> author;
		cout << "���������� �������: ";
		cin >> numPaper;
		cout << "����� ����������� (� ���.): ";
		cin >> timeInMin;
	}

	void showInf() {
		Publication::showInf();
		cout << "�����: " << author << endl
			<< "���. �������: " << numPaper << endl
			<< "����� ����������� (� ���.): " << timeInMin << endl;
		fstream inf("inf.txt", fstream::app);
		inf << "�����: " << author << endl
			<< "���. �������: " << numPaper << endl
			<< "����� ����������� (� ���.): " << timeInMin << endl;
		inf.close();
	}
};
