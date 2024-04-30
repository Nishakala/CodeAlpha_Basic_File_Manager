#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

using namespace std;

// Function to list all files and directories in a given directory
void listFiles(const string& directory) {
    vector<string> files;
    vector<string> directories;

    DIR* dir = opendir(directory.c_str());
    if (dir != nullptr) {
        dirent* entry;
        while ((entry = readdir(dir)) != nullptr) {
            if (entry->d_type == DT_DIR) {
                directories.push_back(entry->d_name);
            } else if (entry->d_type == DT_REG) {
                files.push_back(entry->d_name);
            }
        }
        closedir(dir);
    } else {
        cerr << "Error opening directory " << directory << endl;
        return;
    }

    cout << "Files:" << endl;
    for (const string& file : files) {
        cout << file << endl;
    }

    cout << "\nDirectories:" << endl;
    for (const string& dir : directories) {
        cout << dir << endl;
    }
}

// Function to create a new directory
bool createDirectory(const string& directory) {
    if (mkdir(directory.c_str(), 0777) == 0) {
        cout << "Directory created successfully!" << endl;
        return true;
    } else {
        cerr << "Failed to create directory " << directory << endl;
        return false;
    }
}

// Function to copy a file
bool copyFile(const string& sourceFile, const string& destinationFile) {
    ifstream source(sourceFile, ios::binary);
    ofstream destination(destinationFile, ios::binary);

    if (source && destination) {
        destination << source.rdbuf();
        cout << "File copied successfully!" << endl;
        return true;
    } else {
        cerr << "Failed to copy file " << sourceFile << " to " << destinationFile << endl;
        return false;
    }
}

// Function to move a file
bool moveFile(const string& sourceFile, const string& destinationFile) {
    if (rename(sourceFile.c_str(), destinationFile.c_str()) == 0) {
        cout << "File moved successfully!" << endl;
        return true;
    } else {
        cerr << "Failed to move file " << sourceFile << " to " << destinationFile << endl;
        return false;
    }
}

int main() {
    // Get the current working directory
    char currentDirectory[FILENAME_MAX];
    if (getcwd(currentDirectory, sizeof(currentDirectory)) != nullptr) {
        cout << "Current working directory: " << currentDirectory << endl;
    } else {
        cerr << "Failed to get current working directory" << endl;
        return 1;
    }

    // List all files and directories in the current working directory
    listFiles(currentDirectory);

    // Create a new directory
    string newDirectory = "new_directory";
    if (createDirectory(newDirectory)) {
        // Copy a file
        if (copyFile("file.txt", newDirectory + "/file.txt")) {
            // Move a file
            if (moveFile("file.txt", newDirectory + "/file.txt")) {
                return 0;
            }
        }
    }

    return 1;
}
