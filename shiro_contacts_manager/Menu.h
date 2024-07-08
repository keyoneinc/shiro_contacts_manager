//#ifndef SHIRO_MENU_H
//#define SHIRO_MENU_H
//
//#endif //SHIRO_MENU_H
#pragma once

#include <iostream>
using namespace std;

void displayMenu() {
    cout << "\n\t\tТелефонная книга\n";
    cout << "-------------------------------------\n";
    cout << "1. Добавить контакт\n";
    cout << "2. Удалить контакт\n";
    cout << "3. Редактировать контакт\n";
    cout << "4. Поиск контактов\n";
    cout << "5. Сортировать контакты\n";
    cout << "6. Просмотреть все контакты\n";
    cout << "7. Сохранить контакты\n";
    cout << "0. Выход\n";
    cout << "-------------------------------------\n";
    cout << "Введите номер пункта меню: ";
}

int selectMenu() {
    int choice;
    cin >> choice;
    while (choice < 0 || choice > 7) {
        cin.clear();
        cin.ignore();
        cout << "Неверный выбор. Пожалуйста, введите число от 0 до 7: ";
        cin >> choice;
    }
    return choice;
}
