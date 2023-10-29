#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <sqlite3.h>

using namespace std;

int main() {
    sqlite3 *db;

    //Connect to SQLite DB containing MAC
    if (sqlite3_open("MacAddresses.db", &db)) {
        cout << "ERROR: Unable to connect to DB" << endl;
    } else {
        cout << "Successfully connected to DB" << endl;
    }

    //Open MAC Address file
    ifstream macFile;
    macFile.open("manuf");
    if (macFile.is_open()) {
        string line;
        while (getline(macFile, line)) {
            istringstream lineStream(line);
            string MAC, shortName, fullName;
            lineStream >> MAC >> shortName;
            string temp;
            while (lineStream >> temp) {
                fullName += temp + " ";
            }
            fullName = fullName.substr(0, fullName.length() - 1); //just to trim last space 
            
            int pos = 0;
            while (true) {
                pos = shortName.find("'", pos + 2);
                if (pos == string::npos) {
                    break;
                }
                shortName.insert(pos, "'");
            }
            pos = 0;
            while (true) {
                pos = fullName.find("'", pos + 2);
                if (pos == string::npos) {
                    break;
                }
                fullName.insert(pos, "'");
            }

            string sqlStatement = "INSERT INTO MACtoVendors VALUES (\'" + MAC + "\', \'" + shortName + "\', \'" + fullName + "\');";
            cout << sqlStatement << endl;
            char* errMsg;
            int status = sqlite3_exec(db, sqlStatement.c_str(), NULL, 0, &errMsg);

            if (status != SQLITE_OK) {
                cout << "ERROR: Did not successfully add to table -- " << errMsg << endl;
                sqlite3_free(errMsg);
            }
        }
    } else {
        cout << "ERROR: Unable to open MAC file" << endl;
    }


    sqlite3_close(db);

}