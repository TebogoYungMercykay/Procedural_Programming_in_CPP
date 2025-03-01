#ifndef NETWORKINTERFACE_H
#define NETWORKINTERFACE_H

#include <cmath>
#include <string>

#include "InputOutput.h"
#include "ProvidedFunctions.h"
#include "UDP.h"

extern std::string dataSourceRequest;
extern std::string dataDestRequest;
extern std::string dataDataRequest;

std::string askUserForSourcePort();
std::string askUserForDestinationPort();
std::string askUserForData();

std::string formUDPFromUserInput();

void prettyPrint(std::string UDPPacket);
void packetPrint(std::string UDPPacket);

#endif /*NETWORKINTERFACE_H*/