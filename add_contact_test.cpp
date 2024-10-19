#include <vector>
#include "register_test.cpp"

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
                cout << "Adding " << new_contact.getName() << " to contact list" << endl;
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