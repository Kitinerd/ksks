#pragma comment(lib, "Ws2_32.lib")
#pragma warning( disable : 4996)
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <winsock2.h>
#include <iostream>
#include <clocale>
#include <string.h>
#include <sstream>
#include <Windows.h>
#include "Parser.h"
#define PORT 777 // порт сервера

using namespace std;

void command_selection_(DATA data) {
    switch (data.number_command) {
        /*clear display*/
    case 1:
        system("cls");
        break;
        /*draw pixel*/
    case 2:
        /*draw line*/
    case 3:
        break;
        /*draw rectangle*/
    case 4:
        break;
        /*fill rectangle*/
    case 5:
        break;
        /*draw ellipse*/
    case 6:
        break;
        /*fill ellipse*/
    case 7:
        break;
        /*draw circle*/
    case 8:
        break;
        /*fill circle*/
    case 9:
        break;
        /*draw rounded rectangle*/
    case 10:
        break;
        /*fill rounded rectangle*/
    case 11:
        break;
        /*draw text*/
    case 14:
        break;
        /*get width*/
    case 15:
        break;
        /*get height*/
    case 16:
        break;
    default:
        break;
    }
}
int main(int argc, char* argv[]) {
    char buff[10 * 1014];
    setlocale(LC_ALL, "Rus");
    string command_client;
    DATA data;
    printf("UDP DEMO echo_Server \n");
    if (WSAStartup(0x202, (WSADATA*)&buff[0]))
    {
        printf("WSAStartup error : %d \n", WSAGetLastError());
        return -1;
    }
    SOCKET my_sock;
    my_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (my_sock == INVALID_SOCKET)
    {
        printf("Socket() error: %d \n", WSAGetLastError());
        WSACleanup();
        return -1;
    }
    sockaddr_in local_addr;
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = INADDR_ANY;
    local_addr.sin_port = htons(PORT);
    if (bind(my_sock, (sockaddr*)&local_addr, sizeof(local_addr)))
    {
        printf("bind error : %d \n", WSAGetLastError());
        closesocket(my_sock);
        WSACleanup();
        return -1;
    }
    while (1) {
        sockaddr_in client_addr;
        int client_addr_size = sizeof(client_addr);
        int bsize = recvfrom(my_sock, &buff[0], sizeof(buff) - 1, 0, (sockaddr*)&client_addr, &client_addr_size);
        command_client = string(buff);
        int answer = parser(command_client, &data);
        if (answer == OK) {
            cout << "Ok!" << endl;
        }
        if (answer == INCORRECT_PARAMETERS) {
            cout << "Ошибка! Некорректные парамметры функции!" << endl;
        }
        if (answer == COMMAND_NOT_FOUND) {
            cout << "Ошибка! Функция не найдена!" << endl;
        }
        if (bsize == SOCKET_ERROR)
            printf("recvfrom() error: %d \n", WSAGetLastError());
        HOSTENT* hst;
        hst = gethostbyaddr((char*)&client_addr.sin_addr, 4, AF_INET);
        buff[bsize] = 0;
        sendto(my_sock, &buff[0], bsize, 0, (sockaddr*)&client_addr, sizeof(client_addr));
    }
    return 0;
}
