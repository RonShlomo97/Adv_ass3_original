#include <bits/stdc++.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include "Stream.h"
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAX 4096

/// @brief method that check if the string is can be valid int of port and return port
/// @param strp 
/// @return port or -1 is this is not valid port
int cast_to_port(string strp)
{
	int port;
	try
	{
		port = stoi(strp);
	}
	catch (...)
	{
		return -1;
	}
	// generly the system use pors from 0 to 1023
	if (port < 1023 || port > 65535)
	{
		return -1;
	}
	return port;
}


/// @brief method that check if this is valid input of IP, there are 4 numbers in the range [0,255]
/// @param ipaddr 
/// @return true if is good ip
bool isIPAddress(std::string ipaddr)
{
	int x;
	int count = 0;
	string n = "";
	int i = 0;
	for (;i<ipaddr.length();i++){
		//when try we get to a dot, check if we have valid number
		if(ipaddr[i] != '.'){n += ipaddr[i];}
		else{
			try{
				x = stoi(n);
			}
			catch(...){return false;}
			if(x <0 || x > 255){return false;}
			count++;
			n = "";
		}
	}
	//check that there were 4 numbers
	if(count != 3){return false;}
	return true;
}

/// @brief method that get char* and cast it to string
/// @param des 
/// @param from 
void copyToStarChar(char* &des,std::string from){
	des = new char[from.length()];
    int i =0 ;
	for(;i<from.length();i++){
		des[i] = from[i];
	}
}

int main(int argc, char const *argv[])
{
	// check that there are the amount of arguments
	if (argc != 3){cout<<"args error\n";exit(1);}
	//check the ip
	std::string ip = argv[1];
	if(!isIPAddress(ip)){
		cout<<"invalid ip"<<endl;
		exit(1);
	}
	char* ipToSend;
	copyToStarChar(ipToSend, ip);

	//check valid port
	int port;
    port = cast_to_port(argv[2]);
    if(port< 0){
        std::cout << "invalid port" << endl;
        exit(1);
    }
	

	// open socket for the client
	int clientSocket, serverSocket, receiveMsgSize;
	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (clientSocket < 0)
	{
		cout << "Creation of client socket failed" << endl;
		return 0;
	}

	struct sockaddr_in serverAddr, clientAddr;
	serverAddr.sin_family = AF_INET;
	// init the ip and port
	serverAddr.sin_addr.s_addr = inet_addr(ipToSend);
	serverAddr.sin_port = htons(port);

	if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
	{
		cout << "Connection Error..." << endl;
		return 0;
	}

	while (true)
	{
		// temo string s for reading from the client
		string s;
		char input[MAX];
		getline(cin, s);
		// copy the input to array of chars
		int n = s.size();
		for (int i = 0; i < n; i++)
		{
			input[i] = s[i];
		}
		input[n] = '\0';
		// send the array that full with the input to the server.
		int isSend = send(clientSocket, input, strlen(input) + 1, 0);
		if (isSend < 0)
		{ /*error*/
		}
		// make array for the resalt from the server
		char receiveMessage[MAX];
		// get the resalt to receiveMessage
		int rMsgSize = recv(clientSocket, receiveMessage, MAX, 0);
		if (rMsgSize < 0)
		{
			cout << "recieve failed." << endl;
			return 0;
		}
		else if (rMsgSize == 0)
		{
			cout << "Server is off." << endl;
			return 0;
		}

		if (receiveMessage[0] == '-' && receiveMessage[1] == '1' && receiveMessage[2] == '\0')
		{
			// end the conection
			break;
		}
		cout<<receiveMessage<<endl;
	}
	close(clientSocket);
	return 0;
}