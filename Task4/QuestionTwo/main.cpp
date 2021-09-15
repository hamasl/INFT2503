#include <gtkmm.h>
#include <string>
#include <iostream>

using namespace std;

class Window : public Gtk::Window {
private:
    void toggle_button();
    string trim(string str);

public:
    Gtk::VBox vbox;
    Gtk::Label label_first_name;
    Gtk::Entry entry_first_name;
    Gtk::Label label_last_name;
    Gtk::Entry entry_last_name;
    Gtk::Button button;
    Gtk::Label label;

    Window() {
        this->set_title("Task 4");
        this->set_default_size (400, 200);
        label_first_name.set_text("First name");
        entry_first_name.set_text("");
        label_last_name.set_text("Last name");
        entry_last_name.set_text("");
        button.set_label("Combine names");
        button.set_sensitive(false);
        vbox.pack_start(label_first_name);  //Add the widget entry to vbox
        vbox.pack_start(entry_first_name);  //Add the widget entry to vbox
        vbox.pack_start(label_last_name);  //Add the widget entry to vbox
        vbox.pack_start(entry_last_name);  //Add the widget entry to vbox
        vbox.pack_start(button); //Add the widget button to vbox
        vbox.pack_start(label);  //Add the widget label to vbox

        add(vbox);  //Add vbox to window
        show_all(); //Show all widgets

       entry_first_name.signal_changed().connect([this]() {
            toggle_button();
        });

        entry_last_name.signal_changed().connect([this]() {
            toggle_button();
        });

        button.signal_clicked().connect([this]() {
            label.set_text(trim(entry_first_name.get_text()) + " " + trim(entry_last_name.get_text()));
        });
    }
};

void Window::toggle_button(){
    button.set_sensitive(!(trim(entry_first_name.get_text())  == "" || trim(entry_last_name.get_text()) == ""));
}

string Window::trim(string str){
    if(str == "") return "";
    size_t index = 0;
    bool found = false;
    size_t start_index = -1;
    while(index < str.length() && !found){
        if(str[index] != ' '){
            start_index = index;
            found = true;
        }
        index++;
    }
    index = str.length()-1;
    found = false;
    size_t end_index = str.length()+1;
    while(index >= 0 && !found){
        if(str[index] != ' '){
            end_index = index;
            found = true;
        }
        index--;
    }
    cout << start_index << " " << end_index << endl;
    cout << ((start_index == -1 && end_index == str.length()+1) ? "" : str.substr(start_index == -1 ? 0 : start_index, end_index == (str.length()+1) ? str.length() : end_index )) << " endmarker" << endl;
    return (start_index == -1 && end_index == str.length()+1) ? "" : str.substr(start_index == -1 ? 0 : start_index, end_index == (str.length()+1) ? str.length() : end_index );
}

int main() {
    Gtk::Main gtk_main;
    Window window;
    gtk_main.run(window);
}
