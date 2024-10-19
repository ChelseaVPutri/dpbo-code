#include "chat_log_test.cpp"

int main() {
    string main_uname, main_pw;
    string auth_uname, auth_pw;

    ifstream file("user.txt");
    getline(file, auth_uname);
    getline(file, auth_pw);
    file.close();
    
    cout << "Welcome to Rehan Wangsaff" << endl;
    cout << "Please fill the fields below to login" << endl;
    cout << "Name: ";
    getline(cin, main_uname);
    cout << "Password: ";
    getline(cin, main_pw);

    if (main_uname == auth_uname && main_pw == auth_pw) {
        cout << "\nHello, " << main_uname << endl;
    } else {
        cout << "Wrong username or password" << endl;
        cout << "Login failed" << endl;
        exit(0);
    }

    cout << endl;
    cout << "----------------" << endl;
    cout << endl;

    // for adding contacts (didn't ask for the user input)
    Contact contact_list;
    User user1;
    user1.setName("Shu");
    User user2;
    user2.setName("Mika");
    User user3;
    user3.setName("Nazuna");

    // chatting
    int chat_id;
    Chat chat;
    ChatLog chat_log;

    int choice;
    while(true) {
        cout << "Menu" << endl;
        cout << "1. Adding user to contact list" << endl;
        cout << "2. Chatting" << endl;
        cout << "3. Show past chat log" << endl;
        cout << "4. Exit program" << endl;
        cout << "What do you want to do? ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Adding " << user1.getName() << ", " << user2.getName() << ", and " << user3.getName() << " to contact list" << endl;
                contact_list.addContact(user1);
                contact_list.addContact(user2);
                contact_list.addContact(user3);
            case 2:
                chat.sendMessage(user1, user2);
            case 3: 
                cout << "Enter the chat id: ";
                cin >> chat_id;
                chat_log.printChatLog(chat_id);
            case 4:
                cout << "Exit program....." << endl;
                exit(0);
        }
    }
    return 0;
}