#include <iostream>
#include <sstream>

#include "InputOutput.h"
#include "NetworkInterface.h"
#include "ProvidedFunctions.h"
#include "UDP.h"

using namespace std;

void studentExample();
void testProvidedFunctions();
void testUDP();
void testNetworkInterface();
void testInputOutput();

int main() {
  studentExample();

  // ADDITIONAL TESTS

  testProvidedFunctions();
  testUDP();
  testInputOutput();
  testNetworkInterface();

  return 0;
}

void studentExample() {
  istringstream mockInput("7822\n6674\nHelloWorld\n");
  cin.rdbuf(mockInput.rdbuf());

  string udpPacket = formUDPFromUserInput();
  cout << endl;
  prettyPrint(udpPacket);
  cout << endl;
  packetPrint(udpPacket);
  cout << endl;
}

void testProvidedFunctions() {
  cout << "---- Testing ProvidedFunctions -----" << endl;

  cout << "bitToInt('1') -> " << bitToInt('1') << endl;
  cout << "bitToInt('0') -> " << bitToInt('0') << endl;

  cout << "intToBin(5, 4) -> " << intToBin(5, 4) << endl;
  cout << "intToBin(15, 4) -> " << intToBin(15, 4) << endl;

  cout << "stringToBin(\"AB\", 16) -> " << stringToBin("AB", 16) << endl;
  cout << "binToString(\"0100000101000010\", 16) -> "
       << binToString("0100000101000010", 16) << endl;
}

void testUDP() {
  cout << "---- Testing UDP functions -----" << endl;

  string udpPacket =
      "000111101000111000011010000100100000000000110010111111110000000000111001"
      "000101101011011101011001110100010101100011";

  cout << "extractSourcePortBin -> " << extractSourcePortBin(udpPacket) << endl;
  cout << "extractDestinationPortBin -> "
       << extractDestinationPortBin(udpPacket) << endl;
  cout << "extractDataBin -> " << extractDataBin(udpPacket) << endl;
  cout << "extractLengthBin -> " << extractLengthBin(udpPacket) << endl;
  cout << "extractCheckSumBin -> " << extractCheckSumBin(udpPacket) << endl;

  cout << "extractSourcePortInt -> " << extractSourcePortInt(udpPacket) << endl;
  cout << "extractDestinationPortInt -> "
       << extractDestinationPortInt(udpPacket) << endl;
  cout << "extractDataStr -> " << extractDataStr(udpPacket) << endl;
  cout << "extractLengthInt -> " << extractLengthInt(udpPacket) << endl;
  cout << "extractCheckSumInt -> " << extractCheckSumInt(udpPacket) << endl;
}

void testNetworkInterface() {
  cout << "---- Testing NetworkInterface -----" << endl;

  istringstream mockInput("7822\n6674\nHelloWorld\n");
  cin.rdbuf(mockInput.rdbuf());

  cout << "askUserForSourcePort -> " << askUserForSourcePort() << endl;
  cout << "askUserForDestinationPort -> " << askUserForDestinationPort()
       << endl;
  cout << "askUserForData -> " << askUserForData() << endl;

  // cout << "formUDPFromUserInput -> " << formUDPFromUserInput() << endl;

  string samplePacket =
      "000111101000111000011010000100100000000000110010111111110000000000111001"
      "000101101011011101011001110100010101100011";
  prettyPrint(samplePacket);
  packetPrint(samplePacket);
}

void testInputOutput() {
  istringstream mockInput("7822\n6674\nHelloWorld\n");
  cin.rdbuf(mockInput.rdbuf());

  cout << "---- Testing InputOutput -----" << endl;

  printOut("This is a test message from printOut().");

  cout << "askForStringInput(\"Enter test string: \") -> "
       << askForStringInput("Enter test string: ") << endl;
  cout << "askForIntInput(\"Enter test number: \") -> "
       << askForIntInput("Enter test number: ") << endl;
}
