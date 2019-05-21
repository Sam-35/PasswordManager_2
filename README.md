
   ##CS-150: Final Project PasswordManager
   #### @author: Sam Abumoghli
   #### @date: May 21, 2019
   #### Problem Statement: Text based password manager with simple encryption.
   ##Overall Plan (Algorithm):
   
 ###1.Class Password
 ##### Private:
    string title, string email, string username, string password,
##### Public:
    Constructors, setters, getters, toString

 ###2.Class Database
 ##### Private:
    vector <Password> lockedDB: encrypted data
    vector <Password> unlockedDB: plain text
    string key: used for encryption //testing
 ##### Public:
    string getTitle:  prompts the user to enter a title for the record, must be less than 30 chars
                       and more than 1 or more chars.
    string getEmail: Prompts the user to enter an email. Email must contain '@' and '.'
                       Use .find() == string::npos to check if chars are available in string
                       Email must be between 3 and 30 characters    
                    
    string getUsername: Prompts the user to input a username. Username must be between 1 and 30 chars
    string getPassword: Prompts the user to enter a password. Calls function: checkPassword
    bool getPassword(const string &password): checks if string entered by user meets password reqs, at least one of each: upper/lower, digit
    
    void editDatabase(): 
        switch: add record, delete record, export/print data, quit
    void exportDatabase():
        switch: print/export cipher text, print/export
    void printData: for each, cout contents of unlockedDB
    void printEncData(): for each, cout contents of lockedDB
    void exportDB_text(): prints all data in unlockedDB to file
    void exportDB_cipher(): prints all data in lockedDB to file
    void encrypt_db(): loops through unlockedDB, calls encrypt_pass to return an encrypted version of it
                                    save each encrypted password to vector lockedDB
    void decrypt_db(): loops through lockedDB, calls decrypt_pass to return an decrypted version of it
                                   save each decrypted password to vector unlockedDB
    Password encrypt_pass(Password pass): returns encrypted password object 
    Password decrypt_pass(Password pass): returns decrypted password object
    
                     
 
 ####Features that work: 
- Adding password with input validation
- Exporting data as plain text to file
- Exporting data as cipher text to file
- Simple encryption
- Printing data as plain text to file
- Printing data as cipher text to file
 