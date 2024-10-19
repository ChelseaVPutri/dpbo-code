#include "chat_test.cpp"

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

                if (isFound && line.find("From: ") != string::npos) {
                    sender = line.substr(6);
                }

                if (isFound && line.find("To: ") != string::npos) {
                    receiver = line.substr(4);
                }

                if (isFound && line.find("Message: ") != string::npos) {
                    text = line.substr(9);
                }

                if (line.empty()) {
                    cout << "id: " << msg_id << endl;
                    cout << "From: " << sender << endl;
                    cout << "To: " << receiver << endl;
                    cout << "Message: " << text << endl;
                    isFound = false;
                    return;
                }
            }
            
        }
    
};