#include <iostream>
#include "SC.h"
#include <map>
#include <vector>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	system("chcp 1251");                           
	string curName;          //  ������� ��� ������������
	string curPassWord;      //  ������� ������ ������������
	int messNumber = 0;      //  ����� �������� ��������� (��������� ���������� �� ���� � ����� � ������� ��������)
	bool persPresence = false;       //  ����������, ������������ ������������� ������������ � ������ ������ � �������
	bool nameInChatAlready = false;  //  ����������, ������� ���������� ��� ����������� ���� �� ��� � ���� ������������ � ����� ������

	string contProcNumber = "0";     // ����������, ������� �������� �� ����������� ���������	

	Chat presChat;


	while (true)
	{
		while (persPresence == false)  // ���� ������������ ���� ������������ �� ����� � ������� ��� �� �����������������
		{
			while (contProcNumber != "1" && contProcNumber != "2" && contProcNumber != "3")  //  ������ �� ������������� ����� ������ ���������� ��������
			{
				cout << "�������� ��������: 1 - �����; 2 - ������������������; 3 - ����� �� ���������." << endl;
				getline(cin, contProcNumber);
			}
			persPresence = false;
			if (contProcNumber == "1")
			{
				presChat.entrChat(persPresence, curName, curPassWord);      // ����� � ���
				if (presChat.ifEmpty() && persPresence)                     // ���� � ������� ���� ��������� � ������������ ����� � ���
				{
					presChat.showMess(curName);
				}
				contProcNumber = "0";
			}

			if (contProcNumber == "2")
			{
				presChat.regChat(nameInChatAlready, persPresence, curName, curPassWord);    // ������������������ � ����
				if (presChat.ifEmpty() && persPresence)                     // ���� � ������� ���� ��������� � ������������ ������� �����������������
				{
					presChat.showMess(curName);
				}
				contProcNumber = "0";
			}

			if (contProcNumber == "3") break;  //  ����� �� �����
		}
		if (contProcNumber == "3") break;      //  ����� �� ���������
		while (true)                       // ���� ������������ ���� ������������ �� ������� ����� �� ������� ��� �� ���������
		{
			while (contProcNumber != "1" && contProcNumber != "2" && contProcNumber != "3")  //  ������ �� ������������� ����� ������ ���������� ��������
			{
				cout << "�������� ��������: 1 - ��������� ���������; 2 - ������� ��������� ; 3 - ����� �� �������." << endl;
				getline(cin, contProcNumber);
			}
			if (contProcNumber == "3")     //  ���� ������ ����� �� �������
			{
				cout << endl;              
				persPresence = false;      //  ������������ ������� �� �������
				contProcNumber = "0";
				break;                     //  ����� �� �����
			}
			if (contProcNumber == "2")     //  ���� ������� �������� ���������
			{
				presChat.delMess();
				contProcNumber = "0";
			}

			if (contProcNumber == "1")     //  ���� ������� �������� ���������
			{
				presChat.sendMess(curName);
				contProcNumber = "0";
			}
			if (contProcNumber == "3") break;  //  ����� �� ���������
		}
		if (contProcNumber == "3") break;      //  ����� �� ���������
	}
	return 0;
}