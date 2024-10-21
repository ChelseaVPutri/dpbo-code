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

                if (isFound == true && line.find("From: ") != string::npos) {
                    sender = line.substr(6);
                    cout << "From: " << sender << endl;
                }

                if (isFound == true && line.find("To: ") != string::npos) {
                    receiver = line.substr(4);
                    cout << "To: " << receiver << endl;
                }

                if (isFound == true && line.find("Message: ") != string::npos) {
                    text = line.substr(9);
                    cout << "Message: " << text << endl;
                }
            }
            
        }
    
};