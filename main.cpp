#include "nlohmann/json.hpp" //for json parsing
#include <fstream>
#include <iostream>

using json = nlohmann::json;
using namespace std;

int main(int argc, char* argv[]) {
    string fileName = argv[1];

    ifstream file(fileName);
    json pcap = json::parse(file);

    for (int i = 0; i < pcap.size(); i++) {
        cout << "Destination: " << pcap[i]["_source"]["layers"]["eth"]["eth.dst_tree"]["eth.dst.oui_resolved"] << endl;
        cout << "Source: " << pcap[i]["_source"]["layers"]["eth"]["eth.src_tree"]["eth.src.oui_resolved"] << endl;
    }
}