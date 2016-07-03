//
//  Consumer.cpp
//  ThreadsProject
//
//  Created by JiangZhongjin on 16/7/3.
//  Copyright © 2016年 JiangZhongjin. All rights reserved.
//

#include <stdio.h>
#include "Consumer.h"
#include <iostream>
#include <thread>

Consumer::Consumer(Storehouse &store):store(store)
{
    
}

Consumer::~Consumer()
{
    
}

void Consumer::Speak()
{
    std::cout << "I am Consumer ." << std::endl;
}

void Consumer::Consume()
{
    std::cout << "I am Consumer . start consume product" << std::endl;
    while (1)
    {
        store.DecreaseCount();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}