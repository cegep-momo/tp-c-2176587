#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

#include "library.h"

using namespace std;

class FileManager {
private:
    string booksFileName;
    string usersFileName;
    string booksCSVFileName;
    string usersCSVFileName;
    string logFileName;

public:
    // Constructor
    FileManager(const string& booksFile = "books.txt", 
                const string& usersFile = "users.txt",
                const string& booksCSVFile = "books.csv",
                const string& usersCSVFile = "users.csv",
                const string& logFile = "biblio.log");
    
    // File operations
    bool saveLibraryData(Library& library);
    bool saveLibraryDataCSV(Library& library);
    bool loadLibraryData(Library& library);
    bool loadLibraryDataCSV(Library& library);
    
    // Individual file operations
    bool saveBooksToFile(Library& library);
    bool saveUsersToFile(Library& library);
    bool loadBooksFromFile(Library& library);
    bool loadUsersFromFile(Library& library);
    bool saveBooksToCSV(Library& library);
    bool saveUsersToCSV(Library& library);
    bool loadBooksFromCSV(Library& library);
    bool loadUsersFromCSV(Library& library);
  

    // Utility methods
    bool fileExists(const string& filename);
    void createBackup();
    void logToFile(const string& message);
};

#endif
