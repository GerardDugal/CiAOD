#pragma once

#include "HashTable.h"

class File {
	ifstream IFile; //����� ������ �� �����
	ofstream OFile; //����� ������ � ����
	HashTable* hashTable; //���-�������
	int position; //������� �������
public:
	File(string path) {
		IFile.open(path);
		OFile.open(path, ios::app);
		hashTable = new HashTable();
		this->fillTable();
	}
	//����� ������ �� �����
	Node find(int key) {
		return this->hashTable->find(key);
	}
	//���������� ������ � ������� � ����
	void push(Node newNode) {
		this->position++;
		newNode.position = position;
		this->hashTable->push(newNode);
		OFile << endl;
		OFile << newNode.code << " "
			<< newNode.name;
	}

	void output() {
		this->hashTable->output();
	}


	void pop(int key) {
		hashTable->pop(key);
	}

	~File() {
		delete hashTable;
		IFile.close();
		OFile.close();
		position = 0;
	}

private:
	//���������� ������� �� �����
	void fillTable() {
		int buff, pos;
		string name;
		while (IFile >> buff) {
			Node* node = new Node();
			node->code = buff;
			IFile >> name;
			node->name = name;
			node->position = position;
			position++;
			this->hashTable->push(*node);
		}
	}
};

//void main() {
//	setlocale(LC_ALL, "Russian");
//	cout << "����� �������" << endl;
//	File* file = new File("database.txt");
//	file->output();
//
//	cout << endl << "���������� ����� ������: 678789, ��������" << endl;
//	Node node = { 678789, "��������" };
//	file->push(node);
//	file->output();
//
//	cout << endl << "�������� �� �����: " << endl;
//	file->find(678789).output();
//	cout << endl;
//	file->pop(179865);
//	file->output();
//}