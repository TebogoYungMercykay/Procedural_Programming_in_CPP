#ifndef UDP_H
#define UDP_H

#include <cmath>
#include <string>

#include "ProvidedFunctions.h"

int hexBinToInt(std::string bits);

std::string extractSourcePortBin(std::string UDPPacket);
std::string extractDestinationPortBin(std::string UDPPacket);
std::string extractDataBin(std::string UDPPacket);
std::string extractLengthBin(std::string UDPPacket);
std::string extractCheckSumBin(std::string UDPPacket);

int extractSourcePortInt(std::string UDPPacket);
int extractDestinationPortInt(std::string UDPPacket);
std::string extractDataStr(std::string UDPPacket);
int extractLengthInt(std::string UDPPacket);
int extractCheckSumInt(std::string UDPPacket);

#endif /*UDP_H*/