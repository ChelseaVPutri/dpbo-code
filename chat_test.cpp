#include "add_contact_test.cpp"
#include <fstream>

class Chat {
    private:
        User sender;
        User receiver;
        // FILE * msg_file;
        // int msg_id;
        string msg_file;

    public:
        Chat() : msg_file("msg.txt") {}

        void sendMessage(User sender, User receiver, string msg_file) {
            ifstream file(msg_file);
            if (!file) {
                cout << "Failed to send the message" << endl;
                exit(0);
            } else {
                cout << "Reading the message..." << endl;
                cout << "Message already sent to " << receiver.getName() << endl;
                file.close();
            }
        }
};