#include <iostream>
#include <fstream>
using namespace std;

void addBook() {
    string id, name, author;

    cin.ignore(); // clear buffer
    cout << "Enter Book ID: ";
    getline(cin, id);
    cout << "Enter Book Name: ";
    getline(cin, name);
    cout << "Enter Author Name: ";
    getline(cin, author);

    ofstream file("books.txt", ios::app);
    if (file.is_open()) {
        file << id << "*" << name << "*" << author << endl;
        file.close();
        cout << " Book added successfully!\n";
    } else {
        cout << "Unable to open file.\n";
    }
}

void showBooks() {
    ifstream file("books.txt");
    string id, name, author;

    if (!file.is_open()) {
        cout << "File not found.\n";
        return;
    }

    cout << "\n All Books:\n";
    cout << "ID\t\tName\t\tAuthor\n";
    cout << "----------------------------------------\n";

    while (getline(file, id, '*') &&
           getline(file, name, '*') &&
           getline(file, author)) {
        cout << id << "\t\t" << name << "\t\t" << author << endl;
    }

    file.close();
}

void searchBook() {
    string searchId, id, name, author;
    bool found = false;

    cin.ignore(); // clear buffer
    cout << "Enter Book ID to Search: ";
    getline(cin, searchId);

    ifstream file("books.txt");
    if (!file.is_open()) {
        cout << " File not found.\n";
        return;
    }

    while (getline(file, id, '*') &&
           getline(file, name, '*') &&
           getline(file, author)) {
        if (id == searchId) {
            cout << "\nBook Found:\n";
            cout << "ID: " << id << "\nName: " << name << "\nAuthor: " << author << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Book not found.\n";
    }

    file.close();
}

int main() {
    char choice;

    do {
        cout << "\n========== BOOK MENU ==========\n";
        cout << "1. Show All Books\n";
        cout << "2. Search Book by ID\n";
        cout << "3. Add New Book\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                showBooks();
                break;
            case '2':
                searchBook();
                break;
            case '3':
                addBook();
                break;
            case '4':
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid option! Try again.\n";
        }

    } while (choice != '4');

    return 0;
}
