//
//  Productor.cpp
//  ThreadsProject
//
//  Created by JiangZhongjin on 16/7/3.
//  Copyright © 2016年 JiangZhongjin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Productor.h"
#include <thread>

Productor::Productor(Storehouse &store) : store(store)
{
    
}

Productor::~Productor()
{
    
}

void Productor::Speak()
{
    std::cout << "I am Productor ." << std::endl;
}

void Productor::Product()
{
    std::cout << "I am Productor . start product" << std::endl;
    while(1)
    {
        store.AddCount();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}
