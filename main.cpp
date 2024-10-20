#include "chat_log_test.cpp"

int main() {
    string main_uname, main_pw;
    string auth_uname, auth_pw;
    User main_user;

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
        main_user.setName(main_uname);
        main_user.setPhoneNumber("021...");
    } else {
        cout << "Wrong username or password" << endl;
        cout << "Login failed" << endl;
        exit(0);
    }

    cout << endl;
    cout << "----------------" << endl;
    cout << endl;

    // adding user to contact list
    Contact contact_list;
    User user1;
    user1.setName("Hokuto");
    user1.setPhoneNumber("0813...");
    User user2;
    user2.setName("Yuzuru");
    user2.setPhoneNumber("0812...");
    User user3;
    user3.setName("Meru");
    user3.setPhoneNumber("0858...");

    // chatting
    int chatlog_id;
    Chat chat;
    ChatLog chat_log;

    cout << "Adding contact" << endl;
    contact_list.addContact(user1);
    contact_list.addContact(user2);
    contact_list.addContact(user3);

    cout << endl;

    cout << "Chatting...." << endl;
    cout << "From " << main_user.getName() << " to " << user1.getName() << endl;
    chat.sendMessage(main_user, user1, "msg.txt");

    cout << endl;
    cout << "Show chat log" << endl;
    cout << "Enter chat id: ";
    cin >> chatlog_id;

    cout << endl;

    chat_log.printChatLog(chatlog_id);
}