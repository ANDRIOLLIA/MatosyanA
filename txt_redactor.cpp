#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>  // ��� ������ � ���������

using namespace std;

// ������� ��� ������ ����������� ����� � ������
string readFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "������ �������� �����!" << endl;
        return "";
    }

    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    return content;
}

// ������� ��� ���������� ������ � ����
void saveFile(const string& filename, const string& content) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "������ ���������� �����!" << endl;
        return;
    }

    file << content;
    file.close();
}

// ������� ��� ����������� ������
void displayText(const string& text, size_t cursorPos) {
    system("cls");  // ������� ������ (�������� � Windows)
    for (size_t i = 0; i < text.size(); ++i) {
        if (i == cursorPos) {
            cout << "|";  // ������� �������
        }
        cout << text[i];
    }
    if (cursorPos == text.size()) {
        cout << "|";  // ������ � ����� ������
    }
}

int main() {
    system("chcp 1251");
    string filename;
    cout << "������� ��� �����: ";
    cin >> filename;

    string text = readFile(filename);  // ��������� ����
    size_t cursorPos = text.size();   // ���������� ������ � ����� ������

    while (true) {
        displayText(text, cursorPos);  // ���������� ����� � ��������
        int ch = _getch();  // ������ ������� �������

        if (ch == 27) {  // ����� �� ��������� �� Escape
            break;
        }
        else if (ch == 224) {  // ���� ��� �������
            ch = _getch();
            if (ch == 75 && cursorPos > 0) {  // ������� �����
                cursorPos--;
            }
            else if (ch == 77 && cursorPos < text.size()) {  // ������� ������
                cursorPos++;
            }
        }
        else if (ch == 8) {  // Backspace
            if (cursorPos > 0) {
                text.erase(cursorPos - 1, 1);  // ������� ������ ����� �� �������
                cursorPos--;
            }
        }
        else if (ch == 127) {  // Delete
            if (cursorPos < text.size()) {
                text.erase(cursorPos, 1);  // ������� ������ ������ �� �������
            }
        }
        else if (ch == 13) {  // Enter
            text.insert(cursorPos, "\n");
            cursorPos++;
        }
        else {  // ������ �������
            text.insert(cursorPos, 1, static_cast<char>(ch));
            cursorPos++;
        }
    }

    saveFile(filename, text);  // ��������� ��������� � ����
    return 0;
}
