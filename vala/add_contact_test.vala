using GLib;
using Gee;

class Contact : GLib.Object {
    private User contact_user;
    private Gee.List<User> contact_list;

    
    public Contact() {
        this.contact_list = new Gee.List<User>();
    }

    public void addContact(User new_contact) {
        bool isExist = false;
        foreach (User contact in this.contact_list) {
            if (contact.getName() == new_contact.getName() || contact.getPhoneNumber() == new_contact.getPhoneNumber()) {
                isExist = true;
                break;
            }
        }
        if(!isExist) {
            this.contact_list.append(new_contact);
            stdout.printf("Adding %s to contact list\n", new_contact.getName());
            stdout.printf("Size of contact: %d\n", this.contact_list.length);
        } else {
            stdout.printf("Already added the contact before\n");
        }
    }
}