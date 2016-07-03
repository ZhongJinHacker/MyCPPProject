//
//  Storehouse.cpp
//  ThreadsProject
//
//  Created by JiangZhongjin on 16/7/3.
//  Copyright © 2016年 JiangZhongjin. All rights reserved.
//

#include "Storehouse.hpp"
#include <iostream>
#include <thread>

Storehouse::Storehouse()
{
}

Storehouse::~Storehouse()
{

}

const int Storehouse::MAX_COUNT = 100;

void Storehouse::Speak()
{
    std::cout << "I am Storehouse ." << std::endl;
}

void Storehouse::AddCount()
{
    std::unique_lock<std::mutex> lock(mMutex);
    while (MAX_COUNT <= count)
    {
        isFull.wait(lock);
    }
    count++;
    isEmpty.notify_all();
    std::cout << "AddCount : count = " << count
    << "          currentThread id = " << std::this_thread::get_id()  << std::endl;
}

void Storehouse::DecreaseCount()
{
    std::unique_lock<std::mutex> lock(mMutex);
    while (0 >= count)
    {
        isEmpty.wait(lock);
    }
    count--;
    isFull.notify_all();
    std::cout << "DecreaseCount : count = " << count
    << "          currentThread id = " << std::this_thread::get_id()  << std::endl;
}