#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Temp {
    string username, email, password;
    string searchname, searchpass, searchemail;
    fstream file;

public:
    void login();
    void signup();
    void forget();
};

int main() {
    Temp obj;
    char choice;

    do {
        cout << "\n1 - Login ";
        cout << "\n2 - Sign-Up ";
        cout << "\n3 - Forget Password ";
        cout << "\n4 - Exit ";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore(); // To clear the newline character from the input buffer

        switch (choice) {
        case '1':
            obj.login();
            break;
        case '2':
            obj.signup();
            break;
        case '3':
            obj.forget();
            break;
        case '4':
            cout << "Exiting...";
            break;
        default:
            cout << "***** Invalid Choice *****" << endl;
        }
    } while (choice != '4');

    return 0;
}

void Temp::signup() {
    cout << "\nEnter your username: ";
    getline(cin, username);

    cout << "\nEnter your Email Address: ";
    getline(cin, email);

    cout << "\nEnter your Password: ";
    getline(cin, password);

    file.open("logindata.txt", ios::out | ios::app);
    file << username << "*" << email << "*" << password << endl;
    file.close();

    cout << "Sign-up successful!" << endl;
}

void Temp::login() {
    cout << "--- Login ---" << endl;

    cout << "Enter your username: ";
    getline(cin, searchname);

    cout << "Enter your password: ";
    getline(cin, searchpass);

    file.open("logindata.txt", ios::in);
    bool loginSuccess = false;

    while (file >> username) {
        file.ignore(); // Ignore the '*' character
        getline(file, email, '*');
        getline(file, password);

        if (username == searchname && password == searchpass) {
            cout << "Account login successful!" << endl;
            cout << "Username: " << username << endl;
            cout << "Email: " << email << endl;
            loginSuccess = true;
            break;
        }
    }
    file.close();

    if (!loginSuccess) {
        cout << "Invalid username or password." << endl;
    }
}

void Temp::forget() {
    cout << "Enter your username: ";
    getline(cin, searchname);

    cout << "Enter your email address: ";
    getline(cin, searchemail);

    file.open("logindata.txt", ios::in);
    bool found = false;

    while (file >> username) {
        file.ignore(); // Ignore the '*' character
        getline(file, email, '*');
        getline(file, password);

        if (username == searchname && email == searchemail) {
            cout << "Account found..." << endl;
            cout << "Password is: " << password << endl;
            found = true;
            break;
        }
    }
    file.close();

    if (!found) {
        cout << "Account not found." << endl;
    }
}
