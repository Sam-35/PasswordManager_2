#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include "encrypt.h"

using namespace std;

//TODO print records to screen
//TODO find and delete record
//TODO import enc database
//TODO import text file database
//TODO find and edit record
//TODO salt password for db

/**
 - Private members:
    string title
    string email
    string username
    string password
 - Public members:
    setters
    getters
    toString
 */
class Password
{
private:
    string title;
    string email;
    string username;
    string password;
public:
    //Default constructor:
    Password()
    {
        title = "title";
        email = "email";
        username = "username";
        password = "password";
    }
    Password(string title, string email, string username, string password){
        this->title = title;
        this->email = email;
        this->username = username;
        this->password = password;
    }
    const string &getTitle() const {
        return title;
    }

    void setTitle(const string &title) {
        Password::title = title;
    }

    const string &getEmail() const {
        return email;
    }

    void setEmail(const string &email) {
        Password::email = email;
    }

    const string &getUsername() const {
        return username;
    }

    void setUsername(const string &username) {
        Password::username = username;
    }

    const string &getPassword() const {
        return password;
    }

    void setPassword(const string &password) {
        Password::password = password;
    }

    string toString()
    {
        return "Title:" + title + "| Email:" + email + "| Username:" +
               username + "| Password:" + password;
    }

};//End of class: Password

//#########################################################################################
//#########################################################################################
//#########################################################################################

/**
 *
 - Private members:
    string key
    vector <Password> lockedDB
    vector <Password> unlockedDB
 - Public members:

 */
class Database
{
private:
    string key = "Password"; //FOR TESTING
    vector <Password> lockedDB;
    vector <Password> unlockedDB;
public:
    Database(const vector<Password> &lockedDb, const vector<Password> &unlockedDb) : lockedDB(lockedDb),
                                                                                     unlockedDB(unlockedDb) {}
    string getTitle(){
        string line = "";
        cout << "Enter title:   ";
        //cin.clear();
        cin.ignore();
        getline(cin, line);
        if(line.length() < 1 || line.length() > 30)
        {
            cout << "Error! Title must be between 1-30 characters" << endl;
            return getTitle();
        }
        return line;
    }

    string getEmail(){
        string line = "";
        cout << "Enter email:   ";
        getline(cin, line);
        if (line.length() < 3 || line.length() > 30){
            cout << "Error! Email must be between 1-30 characters" << endl;
            return getEmail();
        }else{
            //Checks if @ and . are not found:
            //Email must contain @ and .
            if (line.find("@") == string::npos || line.find(".") == string::npos)
            {
                cout << "Error! Invalid email." << endl;
                return getEmail();
            }
        }
        return line;
    }

    string getUsername(){
        string line = "";
        cout << "Enter username:    ";
        getline(cin, line);
        if (line.length() < 1 || line.length() > 30){
            cout << "Error! Username must be between 1-30 characters" << endl;
            return getUsername();
        }
        return line;
    }

    bool getPassword(const string &password)
    {
        bool upperCase = false;
        bool lowerCase = false;
        bool digit = false;
        for(int i = 0; i < password.length(); i++)
        {
            if (isupper(password[i]))
            {
                upperCase = true;
            }
            if (islower(password[i]))
            {
                lowerCase = true;
            }
            if (isdigit(password[i]))
            {
                digit = true;
            }
        }//End of for loop
        if(upperCase && lowerCase && digit){
            return true;
        }
        return false;
    }


    string getPassword()
    {
        cout << "Note:password must be at least 4 chars, includes 1 uppercase, 1 lowercase and 1 digit"  << endl;
        string line = "";
        bool saved = false;
        bool upperCase = false;
        bool lowerCase = false;
        bool number = false;
        cout << "Enter password:    ";
        cin.clear();
        getline(cin, line);
        if(line.length() < 4) {
            cout << "Error! Password must be at least 4 characters." << endl;
            return getPassword();
        }
        if(!getPassword(line)){
            cout << "Warning! Please consider using lower/uppercase characters and digits." << endl;
            return getPassword();
        }
        cout << "Password Saved." << endl;
        return line;
    }//End of function: getPassword.


    //#########################################################################################

    void editDatabase()
    {
        int userCH = 0;
        //Prompt:
        cout << "1- Add Record." << endl;
        cout << "2- Delete Record." << endl;
        cout << "3- Export/Print Database." << endl;
        cout << "4- Quit Program." << endl;
        cin >> userCH;
        while(userCH < 1 || userCH > 4){
            cout << "Enter an option from the menu: ";
            cin >> userCH;
        }
        switch (userCH)
        {
            case 1:
            {
                Password temp;
                temp.setTitle(getTitle());
                temp.setEmail(getEmail());
                temp.setUsername(getUsername());
                temp.setPassword(getPassword());
                //Adds temp to unlockedDB vector:
                unlockedDB.push_back(temp);
                break;
            }
            case 2:
                cout << "In progress" << endl;
                //removeRecord();
                break;
            case 3:
                exportDatabase();
                break;
            case 4:
                cout << "Quitting..." << endl;
                exit(1);
            default:
                cout << "Error! Pick an option from the menu." << endl;
                break;
        }//End of switch
    }//End of function: editDatabase

    void removeRecord(){
        string line = "";
        int index = 0;
        getline(cin, line);
        for(Password x: unlockedDB){
            if(line == x.getTitle()){

                //unlockedDB.erase()
            }
            cout << x.toString() << endl;
        }
    }

    void printData(){
        for(Password x: unlockedDB){
            cout << x.toString() << endl;
        }
    }

    void printEncData(){
        encrypt_db();
        for(Password x: lockedDB){
            cout << x.toString() << endl;
        }
    }
    void exportDatabase(){
        int userCH = 0;
        cout << "1- Export database to file as plain text." << endl;
        cout << "2- Export database to file as cipher text." << endl;
        cout << "3- Print database to screen as plain text." << endl;
        cout << "4- Print database to screen as cipher text." << endl;
        cout << "5- Back." << endl;
        cin >> userCH;
        while(userCH < 1 || userCH > 5){
            cout << "Enter an option from the menu: ";
            cin >> userCH;
        }
        switch(userCH){
            case 1:
                exportDB_text();
                break;
            case 2:
                exportDB_cipher();
                break;
            case 3:
                printData();
                break;
            case 4:
                printEncData();
                break;
            case 5:
                break;
            default:
                cout << "SW Default." << endl;
                break;
        }
    }

    //#########################################################################################
    void exportDB_text()
    {
        ofstream fileOUT;
        char filename[] = {"db_text.txt"};
        fileOUT.open(filename, std::ios::binary);
        if (!fileOUT)
        {
            cout << "The file " << filename << " cannot be opened.";
            exit(1);
        }
        //Writes data to text file:
        for (int i = 0; i < unlockedDB.size(); i++)
        {
            fileOUT << unlockedDB[i].toString();
        }
        fileOUT.close();
    }

    void exportDB_cipher()
    {
        ofstream fileOUT;
        char filename[] = {"db_cipher.dat"};
        fileOUT.open(filename, std::ios::binary);
        if (!fileOUT)
        {
            cout << "The file " << filename << " cannot be opened.";
            exit(1);
        }
        encrypt_db();//encrypt database
        //Writes data to text file:
        for (int i = 0; i < unlockedDB.size(); i++)
        {
            //string encrypted_msg = encrypt(line, key);
            fileOUT << lockedDB[i].toString();
        }
        fileOUT.close();
    }



    //#########################################################################################
    void encrypt_db(){
        string enc, text;
        lockedDB.clear();
        for(int i = 0; i < unlockedDB.size(); i++)
        {
             lockedDB.push_back(encrypt_pass(unlockedDB[i]));
        }
    }

    void decrypt_db(){
        string enc, text;
        lockedDB.clear();
        for(int i = 0; i < unlockedDB.size(); i++)
        {
            lockedDB.push_back(encrypt_pass(unlockedDB[i]));
        }
    }

    Password encrypt_pass(Password pass){
        Password encPass;
        string encText, text;

        text = pass.getTitle();
        encText = encrypt(text, key);
        encPass.setTitle(encText);

        text = pass.getUsername();
        encText = encrypt(text, key);
        encPass.setUsername(encText);

        text = pass.getEmail();
        encText = encrypt(text, key);
        encPass.setEmail(encText);

        text = pass.getPassword();
        encText = encrypt(text, key);
        encPass.setPassword(encText);
        return encPass;
    }

    Password decrypt_pass(Password pass){
        Password decPass;
        string decText, text;

        text = pass.getTitle();
        decText = decrypt(text, key);
        decPass.setTitle(decText);

        text = pass.getUsername();
        decText = decrypt(text, key);
        decPass.setUsername(decText);

        text = pass.getEmail();
        decText = decrypt(text, key);
        decPass.setEmail(decText);

        text = pass.getPassword();
        decText = decrypt(text, key);
        decPass.setPassword(decText);
        return decPass;
    }
    //#########################################################################################

};//End of class: Database

//#########################################################################################
//#########################################################################################
//#########################################################################################

int main()
{
    //Main function variables:
    Database data;
    int userCH = 0;
    while(true){
        cout << "1- Password Menu" << endl;
        cout << "2- Export Database" << endl;
        cout << "3- Quit" << endl;
        cin >> userCH;
        while(userCH < 1 || userCH > 3){
            cout << "Enter an option from the menu: ";
            cin >> userCH;
        }
        switch(userCH){
            case 1:
                data.editDatabase();
                break;
            case 2:
                data.exportDatabase();
                break;
            case 3:
                cout << "Quitting" << endl;
                data.exportDatabase();
                exit(1);
            default:
                cout << "SW Default." << endl;
                break;
        }
    }
    return 0;
}//End of Main Function.

