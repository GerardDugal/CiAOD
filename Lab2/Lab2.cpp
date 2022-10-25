﻿#include"NumFail.h"
#include"BinFile.h"
#include<iostream>
#include"tester.h"

using namespace std;

const string path = "TESTer.txt";

int main() {
	
	BinFile<TESTER> bf;
	bf.openClearFile(path);
	TESTER t;
	/*
	* Счет в банке: номер счета – 7 разрядное число, ФИО (Ключ), адрес
	* Поиск записи с заданным значением ключа. 
	* Обновить значение одного поля.
	*/
	t.set(1234567, "Ruvik_V.V.", "Mozayskoe_24");
	bf.appendData(t);
	t.set(2345678, "Vladimir_V.R.", "Tarhova_40");
	bf.appendData(t);
	t.set(1234567, "Goncharov_E.V.", "Oktyabrskoe_pole_12");
	bf.appendData(t);
	t.set(2345678, "Grishina_S.A.", "Novatorov_25");
	bf.appendData(t);
	t.set(1234567, "Maslov_G.A.", "New_Island");
	bf.appendData(t);
	t.set(2345678, "Usov_V.D.", "Polezayevskaya");
	bf.appendData(t);

	TESTER mt[10];
	for (int i = 0; i < 10; i++)
		mt[i] = TESTER(i + 1000000, "DB", "DB");
	bf.appendData(mt, 10);
	bf.toStandartFormat();
	//bf.renameAllCom1("DB", "TESTER");

	//bf.take(14);
	bf.takeFromCom1("Maslov_G.A.");
	bf.getObjFromTakeFile()->setCom2((char*)"St._Peterburg");
	bf.push();
	bf.toStandartFormat();
	bf.print();

	bf.closeFile();

	return 0;
}
