#include <iostream>
using namespace std;

class User {
    private:
        static int user_id;
        string name;
        string phone_number;

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