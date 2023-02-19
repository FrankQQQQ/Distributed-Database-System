#include <iostream>
using namespace std;
#include <string>
#include <filesystem>
#include "run.h"
#include <vector>
#include <sstream>

string openFolder(string name) {
    string path = "./" + name;
    if (filesystem::exists(path) && filesystem::is_directory(path)) {
        // Directory already exists, return its path
        return path;
    } else {
        // Create the directory and return its path
        if (filesystem::create_directory(path)) {
            return path;
        } else {
            // Failed to create directory
            return "";
        }
    }
}


string helperStrip(string str){
    str.erase(0, str.find_first_not_of(" \t\n\r\f\v"));  // remove leading spaces
    str.erase(str.find_last_not_of(" \t\n\r\f\v") + 1);  // remove trailing spaces
    str.erase(0, 1);  // remove leading double quote
    str.erase(str.size() - 1);  // remove trailing double quote
    return str;
}
// int main() {
//     string folderName = "testFolder";
    // string path = openFolder(folderName);
    // if (path != "") {
    //     cout << "Folder created/opened: " << path << endl;
    // } else {
    //     cout << "Failed to create/open folder." << endl;
    // }
    // return 0;
    
// }

int main() {
    string input;
    
    while (true) {
        getline(cin, input);
        
        if (input.find("open(") == 0 && input[input.length() - 1] == ')') {
            if (input.size() <= 8){
                cout << "invalid\n";
                continue;
            }
            string dbname = input.substr(input.find_first_of("\"") + 1, input.find_last_of("\"") - input.find_first_of("\"") - 1);
            cout << "OPEN" << endl;
            cout  << dbname << endl;
        }
        else if (input.find("put(") == 0 && input[input.length() - 1] == ')') {
            if (input.size() <= 10){
                cout << "invalid\n";
                continue;
            }
            string result = input.substr(4, input.size() - 5);
            stringstream ss(result);
            vector<string> tokens;
            string token;
            while (getline(ss, token, ',')) {
                tokens.push_back(token);
            }
            if (tokens.size() != 2){
                cout << "Put invalid template\n";
                continue;
            }
            cout << "PUT" << endl;
            cout <<"first: " << helperStrip(tokens[0]) << endl;
            cout << "second: " <<helperStrip(tokens[1]) << endl;

        }

        else if (input.find("get(") == 0 && input[input.length() - 1] == ')') {
            if (input.size() <= 7){
                cout << "invalid\n";
                continue;
            }
            string result = input.substr(4, input.size() - 5);
            cout << "GET" << endl;
            cout << helperStrip(result) << endl;
        }
        else if (input.find("scan(") == 0 && input[input.length() - 1] == ')') {
            if (input.size() <= 12){
                cout << "invalid\n";
                continue;
            }
            string result = input.substr(5, input.size() - 6);
            stringstream ss(result);
            vector<string> tokens;
            string token;
            while (getline(ss, token, ',')) {
                tokens.push_back(token);
            }
            cout << "SCAN" << endl;
            
            cout <<"first: " << helperStrip(tokens[0]) << endl;
            cout << "second: " <<helperStrip(tokens[1]) << endl;
        }
        else if (input.find("close(") == 0 && input[input.length() - 1] == ')') {
            if (input.size() <= 9){
                cout << "invalid\n";
                continue;
            }
            string result = input.substr(6, input.size() - 7);
            cout << result << endl;
            cout << helperStrip(result) << endl;
            
        }
        else if(input == "help"){
            cout << "helper" << endl;
        }
        else if (input == "quit"){
            break;
        }
        else {
            cout << "Invalid input" << endl;
            cout << "Type \"help\" to see instructions" << endl;
        }
    }
    
    return 0;
}
