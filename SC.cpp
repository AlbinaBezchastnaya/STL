#include "SC.h"
#include<iostream>

void userReg(string& curName, string& curPassWord)   // ������� ��� ����� ������ ������������ ��� ����������� ��� �����
{

	cout << "������� ���: ";
	getline(cin, curName);
	cout << "������� ������: ";
	getline(cin, curPassWord);
}

PersMessage::PersMessage() // ����������� �� ���������
{
	this->persName = "persName";        
	this->persDirWord = "persDirWord";  
	this->textInfo = "textInfo";        
}
string PersMessage::getCharValue(int fieldNumber) const // ������ ��� ������ ����� ������ ���� string
{
	switch (fieldNumber)
	{
	case 1: return this->persName; break;
	case 2: return this->persDirWord; break;
	case 3: return this->textInfo;
	}
}
void PersMessage::setValue(int numValue, string value) // ������ ��� ������������� ����� ���� string
{
	(numValue == 1 ? this->persName = value : this->persDirWord = value);
}
void PersMessage::initPersMessage(string persName)  //  ������� �������� ���������
{
	string _persDirWord;            
	string _textInfo;               
	this->persName = persName;      
	cout << "���� ��������� ��������� (������� ��� ������������ ��� '����'): ";
	getline(cin, _persDirWord);
	this->persDirWord = _persDirWord;
	cout << "������� ����� ���������: ";
	getline(cin, _textInfo);
	this->textInfo = _textInfo;
}
void Chat::entrChat(bool& persPresence, string& curName, string& curPassWord)      // ����� � ���
{
	if (persArray.size())  // ���� ������ ������������� �� ����� ����
	{
		userReg(curName, curPassWord);   // ���� ������ ������������ ��� �����
		map <string, string>::iterator it = persArray.find(curName);
		if (it != persArray.end() && it->second == curPassWord) persPresence = true;  // �������� ���� ������������
		if (persPresence == false)
		{
			cout << "������������ � ������ ������ � ������� �� ������. ��������� ������������ ����� ������" << endl;
		}
	}
	else
	{
		cout << "� ���� ��� ��� ������������������ �������������." << endl;
	}
}
void Chat::regChat(bool& nameInChatAlready, bool& persPresence, string& curName, string& curPassWord)    // ������������������ � ����
{
	userReg(curName, curPassWord);                                // ���� ����� � ������� ������������ ��� �����������
	map <string, string>::iterator it = persArray.find(curName);
	if (it != persArray.end() || curPassWord == "" || curName == "") nameInChatAlready = true;  // ���� ��������� ��� ��� ���� ��� ������� ������ ������ ���� ���
	if (nameInChatAlready)                                        // �� ����������� �� ����������
	{
		cout << "������������ � ����� ������ ��� ���� � ���� ���� ���� ����������� (������ ��� ��� ������). ��������� ����." << endl;
		nameInChatAlready = false;     // ���������� ���������� �������� ������������� ����� � ���� � �������� ���������
	}
	else
	{
		persArray.insert({ curName, curPassWord });               // ��������� ������ ������������ � ������ �������������
		cout << "����� ���������� � ���, " << curName << "!" << endl;
		persPresence = true;
	}
}
bool Chat::ifEmpty()               // ���� � ������� ���� ���������
{
	return !messArray.empty();
}
void Chat::showMess(string curName)              // �������� ���������
{
	PersMessage arrMessage;  
	string arrName;          
	string arrAdress;        
	string arrMessContent;   
	cout << "               ***               " << endl;  // ���������� ��������� ��� ������� ���������� ����������
	for (int i = 0; i < messArray.size(); ++i)            //  ����� �� ����� ��������� ��� ����������� ������������
	{
		arrMessage = messArray[i];                        //  ����������� �������� ���������
		arrName = arrMessage.getCharValue(1);             //  ����������� ����� ��������� ���������
		arrAdress = arrMessage.getCharValue(2);           //  ����������� ����� �������� ���������
		arrMessContent = arrMessage.getCharValue(3);      //  ����������� ���������� ���������
		if (arrName == curName || arrAdress == curName || arrAdress == "����")  //  ���� ��������� ����� ��������� � �������� ������������
		{
			cout << "��������� #" << i << " " << arrName << " ����� " << arrAdress << ":" << endl;  // �� ��� ��������� �� �������
			cout << arrMessContent << endl;

		}
	}
	cout << "               ***               " << endl;   
}
void Chat::delMess()                 // ������� ���������
{
	string inputMessNumber = "";
	int arrNumber;                //  ����� ���������� ���������
	while (inputMessNumber == "") //  ������ �� ������������� �����
	{
		cout << "������� ����� ���������, ������� ������ �������: ";
		getline(cin, inputMessNumber);                  //  ���� ������ ���������, ������� ���������� �������
	}
	arrNumber = stoi(inputMessNumber);                  //  �������������� ������ ��������� �� ������� string � ������ int;
	if (arrNumber > -1 && arrNumber < messArray.size()) //  ���� ��������� ����� ��������� � �������� ������� ���������
	{
		vector<PersMessage>::iterator it = messArray.begin() + arrNumber;
		messArray.erase(it);      //  ��������� ���������
		cout << "��������� �������!" << endl;
	}
	else cout << "��������� � ����� ������� �� �������!" << endl;          //  ����� ��������� ��������� �� ������
}
void Chat::sendMess(string curName)             // ��������� ���������
{
	PersMessage curMessage;       //  ������� ���������
	cout << "������������ ����, ��������� ��� �������:" << endl << "<����> ";

	for (map<string, string>::iterator it = persArray.begin(); it != persArray.end(); ++it)
	{
		cout << "<" << it->first << "> ";      //  ����� ���� ������ �������������
	}
	cout << endl;                              //  ������� �� ����� ������ ��� ������ ���������� ����������
	curMessage.initPersMessage(curName);       //  ������������ ���������
	messArray.push_back(curMessage);
}