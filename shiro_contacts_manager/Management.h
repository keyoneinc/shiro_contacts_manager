//#ifndef SHIRO_MANAGEMENT_H
//#define SHIRO_MANAGEMENT_H
//
//#endif //SHIRO_MANAGEMENT_H
#pragma once

#include <iostream>
#include <cstdio>
#include <limits>
#include <string>
using namespace std;


void addContact();
void deleteContact();
void editContact();
void searchContacts();
void sortContacts();
void displayContacts();
void loadContacts();
void saveContacts();



struct Contact {
    string name;
    string surname;
    string phone;
    string email;
    string address;
};

int contactsCount = 1;
int contactsCapacity = 10;
Contact* contacts = new Contact[contactsCapacity];

void addContact() {
    string name, surname, phone, email, address;

    cout << "Введите имя: ";
    cin >> name;

    cout << "Введите фамилию: ";
    cin >> surname;

    cout << "Введите номер телефона: ";
    cin >> phone;

    cout << "Введите адрес электронной почты (необязательно): ";
    cin.ignore();
    getline(cin, email);

    cout << "Введите адрес (необязательно): ";
    getline(cin, address);

    Contact newContact = {name, surname, phone, email, address};

    if (contactsCount == contactsCapacity) {
        Contact* newContacts = (Contact*) realloc(contacts, (contactsCapacity + 1) * sizeof(Contact));
        if (newContacts) {
            contacts = newContacts;
            contactsCapacity++;
        } else {
            cout << "Ошибка выделения памяти. Не удалось добавить контакт." << endl;
            return;
        }
    }

    contacts[contactsCount] = newContact;
    contactsCount++;

    cout << "Контакт успешно добавлен!" << endl;
}

void deleteContact() {
    if (contactsCount == 0) {
        cout << "Список контактов пуст." << endl;
        return;
    }

    displayContacts();

    int index;
    cout << "Введите номер контакта, который хотите удалить: ";
    cin >> index;

    // check if index correct
    while (index < 0 || index >= contactsCount) {
        cin.ignore();
        cout << "Неверный номер. Пожалуйста, введите число от 0 до " << contactsCount - 1 << ": ";
        cin >> index;
    }

    // move elements
    for (int i = index; i < contactsCount - 1; ++i) {
        contacts[i] = contacts[i + 1];
    }

    contactsCount--;

    cout << "Контакт успешно удален!" << endl;
}


void editContact() {
    if (contactsCount == 0) {
        cout << "Список контактов пуст." << endl;
        return;
    }

    displayContacts();

    int index;
    cout << "Введите номер контакта, который хотите изменить: ";
    cin >> index;

    // check index input correct
    while (cin.fail() || index < 0 || index >= contactsCount) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Неверный номер. Пожалуйста, введите число от 0 до " << contactsCount - 1 << ": ";
        cin >> index;
    }

    // access to contact by index
    Contact& contact = contacts[index];

    string newName, newSurname, newPhone, newEmail, newAddress;

    cout << "Введите новое имя (текущее: " << contact.name << "): ";
    cin >> newName;
    contact.name = newName.empty() ? contact.name : newName;

    cout << "Введите новую фамилию (текущее: " << contact.surname << "): ";
    cin >> newSurname;
    contact.surname = newSurname.empty() ? contact.surname : newSurname;

    cout << "Введите новый номер телефона (текущее: " << contact.phone << "): ";
    cin >> newPhone;
    contact.phone = newPhone.empty() ? contact.phone : newPhone;

    cout << "Введите новый адрес электронной почты (текущий: " << contact.email << "): ";
    cin.ignore();
    getline(cin, newEmail);
    contact.email = newEmail.empty() ? contact.email : newEmail;

    cout << "Введите новый адрес (текущий: " << contact.address << "): ";
    getline(cin, newAddress);
    contact.address = newAddress.empty() ? contact.address : newAddress;

    cout << "Контакт успешно изменен!" << endl;
}

// -----------------------------------------------------------------------------


void searchContacts() {
    string searchTerm;
    cout << "Введите текст для поиска: ";
    cin.ignore();
    getline(cin, searchTerm);

    int foundCount = 0;
    for (int i = 0; i < contactsCount; ++i) {
        Contact& contact = contacts[i];

        if (contact.name.find(searchTerm) != string::npos ||
            contact.surname.find(searchTerm) != string::npos ||
            contact.phone.find(searchTerm) != string::npos ||
            contact.email.find(searchTerm) != string::npos ||
            contact.address.find(searchTerm) != string::npos) {
            cout << "\n---------------------------------------\n";
            cout << "Имя: " << contact.name << " " << contact.surname << endl;
            cout << "Телефон: " << contact.phone << endl;
            if (!contact.email.empty()) {
                cout << "Email: " << contact.email << endl;
            }
            if (!contact.address.empty()) {
                cout << "Адрес: " << contact.address << endl;
            }
            cout << "---------------------------------------\n";
            foundCount++;
        }
    }

    if (foundCount == 0) {
        cout << "По вашему запросу ничего не найдено." << endl;
    } else {
        cout << "Найдено " << foundCount << " контактов." << endl;
    }
}

void sortContacts() {
    int choice;

    cout << "Выберите поле для сортировки:" << endl;
    cout << "1. Имя" << endl;
    cout << "2. Фамилия" << endl;
    cout << "0. Назад" << endl;
    cout << "Ваш выбор: ";
    cin >> choice;

    switch (choice) {
        case 1:
//            sortContactsByName();
            break;
        case 2:
//            sortContactsBySurname();
            break;
        case 0:
            return;
        default:
            cout << "Неверный выбор. Пожалуйста, выберите из предложенных вариантов." << endl;
            break;
    }

    cout << "Контакты успешно отсортированы!" << endl;
}


void displayContacts() { // display all contacts
    if (contactsCount == 0) {
        cout << "Список контактов пуст." << endl;
        return;
    }

    cout << "\nСписок контактов:\n";
    for (int i = 0; i < contactsCount; i++) {
        cout << i + 1 << ". " << contacts[i].name << " " << contacts[i].surname << endl;
        cout << "\tТелефон: " << contacts[i].phone << endl;
        if (!contacts[i].email.empty()) {
            cout << "\tEmail: " << contacts[i].email << endl;
        }
        if (!contacts[i].address.empty()) {
            cout << "\tАдрес: " << contacts[i].address << endl;
        }
        cout << endl;
    }
}


//void loadContacts() { // load contacts from text file
//    FILE* file = fopen("contacts.txt", "r");
//
//    if (file != NULL) {
//        char line[1024];
//        char* field = line;
//        size_t fieldLength = 0;
//
//        while (fgets(line, sizeof(line), file)) {
//
//            // name
//            char* delimiter = line;
//            while (*delimiter != ',' && *delimiter != '\0') {
//                fieldLength++;
//                delimiter++;
//            }
//
//            if (*delimiter != '\0') {
//                string name(field, fieldLength);
//                *delimiter = '\0'; // Отделить имя
//
//                field = delimiter + 1;
//                fieldLength = 0;
//            } else {
//                string name(line); // Имя может быть в конце строки
//            }
//
//            // surname
//            delimiter = field;
//            while (*delimiter != ',' && *delimiter != '\0') {
//                fieldLength++;
//                delimiter++;
//            }
//
//            if (*delimiter != '\0') {
//                string surname(field, fieldLength);
//                *delimiter = '\0';
//
//                field = delimiter + 1;
//                fieldLength = 0;
//            } else {
//                string surname(field);
//            }
//
//            // number phone
//            delimiter = field;
//            while (*delimiter != ',' && *delimiter != '\0') {
//                fieldLength++;
//                delimiter++;
//            }
//
//            if (*delimiter != '\0') {
//                string phone(field, fieldLength);
//                *delimiter = '\0';
//
//                field = delimiter + 1;
//                fieldLength = 0;
//            } else {
//                string phone(field);
//            }
//
//            // email
//            delimiter = field;
//            while (*delimiter != ',' && *delimiter != '\0') {
//                fieldLength++;
//                delimiter++;
//            }
//
//            if (*delimiter != '\0') {
//                string email(field, fieldLength);
//                *delimiter = '\0';
//
//                field = delimiter + 1;
//                fieldLength = 0;
//            } else {
//                string email(field);
//            }
//
//            // address
//            string address(field);
//
//            // create new contact
//            Contact newContact = {name, surname, phone, email, address};
//
//            // adding new contact to array
//            if (contactsCount < contactsCapacity) {
//                contacts[contactsCount] = newContact;
//                contactsCount++;
//            } else {
//                cout << "Предупреждение: Массив contacts заполнен. Некоторые контакты не будут загружены." << endl;
//            }
//        }
//
//        fclose(file); // Закрытие файла
//        cout << "Контакты загружены из файла." << endl;
//    } else {
//        cout << "Ошибка открытия файла с контактами." << endl;
//    }
//}


// save all contacts in array to text file
void saveContacts() {
    FILE* file = fopen("contacts.txt", "w");

    if (file != NULL) {
        for (int i = 0; i < contactsCount; ++i) {
            Contact& contact = contacts[i];

            char buffer[1024];
            sprintf(buffer, "%s,%s,%s,%s,%s\n", contact.name.c_str(), contact.surname.c_str(),
                    contact.phone.c_str(), contact.email.c_str(), contact.address.c_str());
            fputs(buffer, file);
        }
        fclose(file);
        cout << "Контакты сохранены в файл." << endl;
    } else {
        cout << "Ошибка открытия файла для сохранения контактов." << endl;
    }
}
