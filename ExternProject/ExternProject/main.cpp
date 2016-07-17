//
//  main.cpp
//  ExternProject
//
//  Created by JiangZhongjin on 16/7/16.
//  Copyright © 2016年 JiangZhongjin. All rights reserved.
//

#include <iostream>
#include "DownloadManager.hpp"
#include "PlayData.hpp"
#include <memory>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n" << std::endl;
    
    
    downloadManager::dmDownloadTest();
    
    downloadManager::dmDownloadTestTwo();
    
    downloadManager::dmDownloadIPlayData();
    
    downloadManager::dmDownloadIPlayDataTwo();
    
    
    downloadManager::DownloadManager dm;
    dm.downloadTestClass();
    
    downloadManager::iPlayData *playData = downloadManager::dmCreatePlayData();
    
    playData->printPlayDataTwo();
    
    playData->printPlayData();

    delete playData;

    downloadManager::iPlayData *play = new downloadManager::iPlayData;
    play->printPlayDataTwo();
    
    delete play;
    
    std::shared_ptr<downloadManager::iPlayData> smartPlay =
            downloadManager::dmCreateSmartPlayData();
    
    smartPlay->printPlayDataTwo();
    
    return 0;
}

