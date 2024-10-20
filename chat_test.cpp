#include "add_contact_test.cpp"
#include <fstream>

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