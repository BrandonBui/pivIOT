# pivIOT
Packet Inspection for Vulnerable IOT...or pivIOT for short

## Usage
Updated method...clone repository -> run execute.sh with path to file (or filename if in same directory) as an argument
EX - sh execute.sh sample.json

Old method...clone the repository -> compile main.cpp -> execute output with JSON formatted PCAP file
EX - ./a.out sample.json

*Note that parsing the JSON takes some time ~1 min or so depending on the size of the JSON file*
*Also, if you only have a .PCAP/.PCAPNG you can use WireShark to convert it to JSON. Just open the .PCAP file with wireshark and then export it ass JSON.*
