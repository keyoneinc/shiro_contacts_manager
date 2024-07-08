#include <iostream>
#include "Management.h"
#include "Menu.h"

int main() {
//    loadContacts();

    while (true) {
        displayMenu();
        int choice = selectMenu();

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                deleteContact();
                break;
            case 3:
                editContact();
                break;
            case 4:
                searchContacts();
                break;
            case 5:
                sortContacts();
                break;
            case 6:
                displayContacts();
                break;
            case 7:
                saveContacts();
                break;
            case 0:
                exit(0);
            default:
                cout << "Неверный выбор. Пожалуйста, попробуйте еще раз." << endl;
        }
    }
}





