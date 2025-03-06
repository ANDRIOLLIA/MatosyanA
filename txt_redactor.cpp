#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>  // Для работы с клавишами

using namespace std;

// Функция для чтения содержимого файла в строку
string readFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        return "";
    }

    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    return content;
}

// Функция для сохранения текста в файл
void saveFile(const string& filename, const string& content) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Ошибка сохранения файла!" << endl;
        return;
    }

    file << content;
    file.close();
}

// Функция для отображения текста
void displayText(const string& text, size_t cursorPos) {
    system("cls");  // Очистка экрана (работает в Windows)
    for (size_t i = 0; i < text.size(); ++i) {
        if (i == cursorPos) {
            cout << "|";  // Позиция курсора
        }
        cout << text[i];
    }
    if (cursorPos == text.size()) {
        cout << "|";  // Курсор в конце текста
    }
}

int main() {
    system("chcp 1251");
    string filename;
    cout << "Введите имя файла: ";
    cin >> filename;

    string text = readFile(filename);  // Считываем файл
    size_t cursorPos = text.size();   // Изначально курсор в конце текста

    while (true) {
        displayText(text, cursorPos);  // Отображаем текст с курсором
        int ch = _getch();  // Чтение нажатой клавиши

        if (ch == 27) {  // Выход из программы по Escape
            break;
        }
        else if (ch == 224) {  // Коды для стрелок
            ch = _getch();
            if (ch == 75 && cursorPos > 0) {  // Стрелка влево
                cursorPos--;
            }
            else if (ch == 77 && cursorPos < text.size()) {  // Стрелка вправо
                cursorPos++;
            }
        }
        else if (ch == 8) {  // Backspace
            if (cursorPos > 0) {
                text.erase(cursorPos - 1, 1);  // Удаляем символ слева от курсора
                cursorPos--;
            }
        }
        else if (ch == 127) {  // Delete
            if (cursorPos < text.size()) {
                text.erase(cursorPos, 1);  // Удаляем символ справа от курсора
            }
        }
        else if (ch == 13) {  // Enter
            text.insert(cursorPos, "\n");
            cursorPos++;
        }
        else {  // Печать символа
            text.insert(cursorPos, 1, static_cast<char>(ch));
            cursorPos++;
        }
    }

    saveFile(filename, text);  // Сохраняем изменения в файл
    return 0;
}
