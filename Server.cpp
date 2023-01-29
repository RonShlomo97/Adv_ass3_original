#include <bits/stdc++.h>
using namespace std;
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "KnnSysRun.h"
#define MAX 4096

/// @brief method that check if the string is can be valid int of port and return port
/// @param strp 
/// @return port or -1 is this is not valid port
int cast_to_port(string strp){
    int port;
    try{
        port = stoi(strp);
    }    
    catch(...){return -1;}
    //generly the system use pors from 0 to 1023
    if(port < 1023 || port > 65535){return -1;}
    return port;
}

int main(int argc, char const *argv[])
{
    //init port and check valid
    int port;
    port = cast_to_port(argv[2]);
    if(port< 0){
        std::cout << "invalid port" << endl;
        exit(1);
    }
    //try to loud the file
    KnnSysRun knnsr;
    int x = knnsr.loudDataFile(argv[1]);
    // if there was error when try to open the file
    if (x == -1)
    {
        std::cout << "cant opent file" << endl;
        exit(1);
    }

    int serverSocketHandler = socket(AF_INET, SOCK_STREAM, 0);
    // creating a socket and assigning it to the socket handler
    if (serverSocketHandler < 0)
    { // socket methode return -1 if the creation was not successful
        cout << "Socket creation has failed.";
        return 0;
    }
    struct sockaddr_in serverAddr, clientAddr;
    // specifying address and type for the server to operate under
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    int bindStatus = bind(serverSocketHandler, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    if (bindStatus < 0)
    {
        cout << "Socket binding has failed" << endl;
        return 0;
    }
    while (true)
    {
        // listen to the client while others are waiting in queue of size 5
        int listenStatus = listen(serverSocketHandler, 5);
        if (listenStatus < 0)
        { // when queue is full listen fails
            cout << "Listner has failed" << endl;
            return 0;
        }
        char buff[MAX];
        int clientSocketHandler;
        socklen_t len = sizeof(clientAddr);
        int connection;
        if ((connection = accept(serverSocketHandler, (struct sockaddr *)&clientAddr, &len)) < 0)
        {
            cout << "Server didn't accept the request." << endl;
            return 0;
        }
        else
        {
            //cout << "Server accepted the request. \n";
        }
        bool stop = false;
        while (!stop)
        {
            // infinite loop for chatting
            int rMsgSize;

            if ((rMsgSize = recv(connection, buff, MAX, 0)) > 0)
            {

                if (buff[0] == '-' && buff[1] == '1' && buff[2] == '\0')
                {
                    send(connection, buff, strlen(buff) + 1, 0);
                    stop = true;
                }
                else
                {
                    string s = knnsr.run(buff);
                    int n = s.size();
                    char res[n + 1];
                    for (int i = 0; i < n; i++)
                    {
                        res[i] = s[i];
                    }
                    res[n] = '\0';

                    send(connection, res, strlen(res) + 1, 0);
                }
            }
        }
    }
    close(serverSocketHandler);
    return 0;
}