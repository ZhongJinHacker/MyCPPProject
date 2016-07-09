//
//  main.cpp
//  NetClientProject
//
//  Created by JiangZhongjin on 16/7/9.
//  Copyright © 2016年 JiangZhongjin. All rights reserved.
//

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define  MAXLINE 4096

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n" << "客户端代码" << std::endl;
    
    int sockfd;
    ssize_t n;
    char recvline[MAXLINE];
    struct sockaddr_in serveraddr;
    
    if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
    {
        perror("socket");
        exit(1);
    }
    
    bzero(&serveraddr, sizeof(serveraddr));
    
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(9347);
    
    if (inet_pton(AF_INET, "127.0.0.1", &serveraddr.sin_addr) < 0)
    {
        perror("inet_pton");
        exit(1);
    }
    
    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0)
    {
        perror("connect");
        exit(1);
    }
    
    while ( (n = read(sockfd, recvline, MAXLINE - 1)) )
    {
        recvline[n] = '\0';
        printf("%s\n", recvline);
    }
    
    if (n < 0)
    {
        printf("read error\n");
    }
    
    return 0;
}
