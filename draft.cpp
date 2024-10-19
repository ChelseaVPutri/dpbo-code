#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

class User {
    private:
        static int user_id;
        string name;
        string phone_number;
        // string email;
        // vector<User> contact_list;

    public:
        User() {}

        void setName(string name) {
            this->name = name;
        }

        string getName() {
            return this->name;
        }

        void setPhoneNumber(string phone_number) {
            this->phone_number = phone_number;
        }

        string getPhoneNumber() {
            return this->phone_number;
        }
};

class Contact {
    private:
        User contact_user;
        vector<User> contact_list;

    public:
        Contact() {}

        void addContact(User new_contact) {
            bool isExist = false;
            for(auto contact : contact_list) {
                if(contact.getName() == new_contact.getName() || contact.getPhoneNumber() == new_contact.getPhoneNumber()) {
                    isExist = true;
                    break;
                }
            }
            if (!isExist) {
                contact_list.push_back(new_contact);
                cout << "Size of contact: " << contact_list.size() << endl;
            } else {
                cout << "Already added the contact before" << endl;
            }
        }

        void delContact(User del_user) {
            for (auto contact = contact_list.begin(); contact != contact_list.end(); contact++) {
                if (contact->getName() == del_user.getName()) {
                    contact_list.erase(contact);
                } else {
                    cout << "No user found" << endl;
                }
            }
        }

        void printContactList() {
            if (contact_list.empty()) {
                cout << "There is no contact list" << endl;
            } else {
                cout << "Contact list: " << contact_list.size() << " contacts" << endl;
                for (auto contact : contact_list) {
                    cout << "Name: " << contact.getName() << " | Phone: " << contact.getPhoneNumber() << endl;
                }
            }
        }
};

class Chat {
    private:
        User sender;
        User receiver;
        // FILE * msg_file;
        int msg_id;
        string msg_file;

    public:
        Chat() : msg_id(1), msg_file("msg.txt") {}

        void sendMessage(User sender, User receiver) {
            string text;
            cout << "Enter the text: " << endl;
            getline(cin >> ws, text);

            ofstream file("msg.txt", ios::app);
            file << "id: " << msg_id << endl;
            file << "From: " << sender.getName() << endl;
            file << "To: " << receiver.getName() << endl;
            file << "Message: " << text << endl;
            file << endl;
            file.close();

            cout << "Message already sent\n" << endl;
            msg_id++;

        }
};

class ChatLog {
    private:
        string msg_file;

    public:
        ChatLog() : msg_file("msg.txt"){}

        void printChatLog(int msg_id) {
            ifstream file(msg_file);
            string line;
            int id;
            bool isFound = false;
            string sender;
            string receiver;
            string text;

            while(getline(file, line)) {
                if(line.find("id: ") != string::npos) {
                   id = stoi(line.substr(4));

                   if (id == msg_id) {
                    isFound = true;
                   }
                }

                if (line.find("From: ") != string::npos) {
                    sender = line.substr(6);
                }

                if (line.find("To: ") != string::npos) {
                    receiver = line.substr(4);
                }

                if (line.find("Message: ") != string::npos) {
                    text = line.substr(9);
                }

                if (isFound && line.empty()) {
                    cout << "id: " << msg_id << endl;
                    cout << "From: " << sender << endl;
                    cout << "To: " << receiver << endl;
                    cout << "Message: " << text << endl;
                    isFound = false;
                    break;
                } else {
                    cout << "Message is not found" << endl;
                }
            }
            
        }
    
};

int main() {
    string main_username, main_phone;

    // cout << "Welcome! Please fill the field below to sign in" << endl;
    // cout << "Name: ";
    // getline(cin, main_username);
    // cout << "Phone number: ";
    // getline(cin, main_phone);
    
    // cout << "-----------------" << endl;
    // cout << "Welcome, " << main_username << "!" << endl;
 
    // cout << " " << endl;
    // cout << "..................." << endl;
    // cout << " " << endl;

    User mika;
    mika.setName("Mika");
    mika.setPhoneNumber("0812...");

    User shu;
    shu.setName("Shu");
    shu.setPhoneNumber("0813...");

    User nazuna;
    nazuna.setName("Nazuna");
    nazuna.setPhoneNumber("0858...");

    // cout << "Adding the users to contact list...." << endl;
    Contact contact_list;
    contact_list.addContact(mika);
    contact_list.addContact(shu);
    contact_list.addContact(nazuna);
    // cout << "-----------------" << endl;
    // contact_list.printContactList();

    // Chat chat;
    // chat.sendMessage(shu, mika);
    // chat.sendMessage(mika, shu);
    return 0;
}