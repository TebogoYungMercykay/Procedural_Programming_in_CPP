#include "NetworkInterface.h"

std::string dataSourceRequest = "Please enter the source port: ";
std::string dataDestRequest = "Please enter the destination port: ";
std::string dataDataRequest = "Please enter the message: ";

std::string askUserForSourcePort() {
  int t = askForIntInput(dataSourceRequest);
  int k = 16;
  return intToBin(t, k);
}

std::string askUserForDestinationPort() {
  return intToBin(askForIntInput(dataDestRequest), 16);
}

std::string askUserForData() {
  return stringToBin(askForStringInput(dataDataRequest), 5);
}

std::string formUDPFromUserInput() {
  std::string sourcePort = askUserForSourcePort();
  std::string destPort = askUserForDestinationPort();
  std::string data = askUserForData();

  int dataLength = data.length();
  std::string length = intToBin(dataLength, 16);
  std::string checksum = "1111111100000000";

  return sourcePort + destPort + length + checksum + data;
}

void prettyPrint(const std::string UDPPacket) {
  std::string temp = extractSourcePortBin(UDPPacket);
  std::string temp2 = extractDestinationPortBin(UDPPacket);
  printOut("Source Port: " + temp);
  printOut("Destination Port: " + temp2);
  printOut("Length: " + extractLengthBin(UDPPacket));
  printOut("Checksum: " + extractCheckSumBin(UDPPacket));
  printOut("Message: " + extractDataBin(UDPPacket));
}

void packetPrint(const std::string UDPPacket) {
  std::cout << "Source Port: " << extractSourcePortInt(UDPPacket) << std::endl;
  std::cout << "Destination Port: " << extractDestinationPortInt(UDPPacket)
            << std::endl;
  std::cout << "Length: " << extractLengthInt(UDPPacket) << std::endl;
  std::cout << "Checksum: " << extractCheckSumInt(UDPPacket) << std::endl;
  std::cout << "Message: " << extractDataStr(UDPPacket) << std::endl;
}
