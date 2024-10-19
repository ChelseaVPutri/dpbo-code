using GLib;

class User : GLib.Object {
    private static int user_id = 0;
    private string name;
    private string phone_number;


    public void setName(string name) {
        this.name = name;
    }

    public string getName() {
        return this.name;
    }

    public void setPhoneNumber(string phone_number) {
        this.phone_number = phone_number;
    }

    public string getPhoneNumber() {
        return this.phone_number;
    }

    public User(string name, string phone_number) {
        this.name = name;
        this.phone_number = phone_number;
    }
}