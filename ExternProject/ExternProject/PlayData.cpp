//
//  PlayData.cpp
//  ExternProject
//
//  Created by JiangZhongjin on 16/7/16.
//  Copyright © 2016年 JiangZhongjin. All rights reserved.
//

#include "PlayData.hpp"
#include "DownloadManager.hpp"

class CPlayData : public downloadManager::iPlayData
{
public:
    CPlayData()
    {
        std::cout << "construct CPlayData" << std::endl;
    }
    
    ~CPlayData()
    {
        std::cout << "Decontruct CPlayData" << std::endl;
    }
    
    virtual void printPlayData()
    {
        std::cout << "CPlayData : printPlayData" << std::endl;
    }
    
    virtual void printPlayDataTwo()
    {
        std::cout << "CPlayData : printPlayDataTwo" << std::endl;
    }
    
};

void downloadManager::dmDownloadTestTwo()
{
    std::cout << "downloadManager : dmDownloadTestTwo : CPlayData" << std::endl;
}


void downloadManager::dmDownloadIPlayData()
{
    std::cout << "downloadManager : dmDownloadIPlayData : CPlayData"<< std::endl;
}

void downloadManager::dmDownloadIPlayDataTwo()
{
    std::cout << "downloadManager : dmDownloadIPlayData : CPlayData"<< std::endl;
}

downloadManager::iPlayData *downloadManager::dmCreatePlayData()
{
    std::cout << "downloadManager : dmCreatePlayData : CPlayData"<< std::endl;
    CPlayData *playData = new CPlayData;    
    return playData;
}



