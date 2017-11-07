#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

const int PORT = 9002;

int main()
{
while(1==1){
    char clientMessage[256];

    fgets(clientMessage, sizeof(clientMessage), stdin);

    int networkSocket; //Make an int to store the network socket
    networkSocket = socket(AF_INET, SOCK_STREAM, 0); //Makes a socket and stores it in the Var we made

    struct sockaddr_in serverAddress; //Holds the address for the socket
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    int connectionStatus = connect(networkSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

    if (connectionStatus == -1){
        printf("Error connecting to server!\n");
    }

    char serverResponse[256];
    recv(networkSocket, &serverResponse, sizeof(serverResponse), 0);

    printf("%s\n", serverResponse);

    send(networkSocket, clientMessage, sizeof(clientMessage), 0);

    close(networkSocket);



}
    return 0;
}


