#pragma once

#include <string>
#include <map>
#include <vector>

using namespace std;

void userReg(string& curName, string& curPassWord);   // ������� ��� ����� ������ ������������ ��� ����������� ��� �����

class PersMessage                                 // ����� ��������� �������������
{
    string persName;
    string persDirWord;
    string textInfo;
public:
    PersMessage();
    string getCharValue(int fieldNumber) const;   // ������ ��� ������ ����� ������ ���� stringt
    void setValue(int numValue, string value);    // ������ ��� ������������� ����� ���� string
    void initPersMessage(string persName);
};

class Chat
{
    map <string, string> persArray;               // ������ � ������� �������������
    vector<PersMessage> messArray;                // ������ � �����������
public:
    void entrChat(bool& persPresence, string& curName, string& curPassWord);     // ����� � ���
    void regChat(bool& nameInChatAlready, bool& persPresence, string& curName, string& curPassWord);    // ������������������ � ����
    bool ifEmpty();                               // ���� � ������� ���� ���������
    void showMess(string curName);                // �������� ���������
    void delMess();                               // ������� ���������
    void sendMess(string curName);                // ��������� ���������
};
