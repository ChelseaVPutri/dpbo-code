using GLib;

class Chat : GLib.Object {
    private User sender;
    private User receiver;
    private int msg_id;
    private string msg_file;

    
    public Chat() {
        this.msg_id = 1;
        this.msg_file = "msg.txt";
    }

    public void sendMessage(User sender, User receiver) {
        string text;
        stdout.printf("Enter the text: ");
        stdin.read_line(out text);

        //  try {
        //      var file = File.new_for_path(msg_file);
        //      var file_stream
        //  }
    }
}