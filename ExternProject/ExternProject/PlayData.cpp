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
    //std::shared_ptr<CPlayData> playData = std::make_shared<CPlayData>();
    return playData;
}

std::shared_ptr<downloadManager::iPlayData> downloadManager::dmCreateSmartPlayData()
{
    std::cout << "downloadManager : dmCreateSmartPlayData : CPlayData"<< std::endl;
    //CPlayData *playData = new CPlayData;
    //std::shared_ptr<downloadManager::iPlayData> smartPlayData(playData);
    //或 以下方式可以，说明在 share_ptr 模板类中会进行隐式转换，不需要强转
    std::shared_ptr<downloadManager::iPlayData> smartPlayData(new CPlayData);
    return smartPlayData;
}


