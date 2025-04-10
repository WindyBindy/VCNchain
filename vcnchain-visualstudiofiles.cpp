#include <iostream>
#include <vector>
#include <string>

#ifdef _WIN32
#include <windows.h>
void clear_screen() { system("cls"); }
#else
#include <unistd.h>
void clear_screen() { std::cout << "\033[2J\033[1;1H"; }
#endif
using namespace std;

int main() {
    vector<std::string> messages;
    string input;

    while (true) {
        clear_screen();

        cout << "VCNchain\n\n";
        for (const auto& msg : messages) {
            cout << msg << "\n";
        }

        cout << "\nType your message (or 'exit'): ";
        getline(cin, input);


        if (input == "exit") break;
        if (!input.empty()) {
            messages.push_back("You: " + input);
        }

        
    }

    return 0;
}
