//
//  DownloadManager.cpp
//  ExternProject
//
//  Created by JiangZhongjin on 16/7/16.
//  Copyright © 2016年 JiangZhongjin. All rights reserved.
//

#include "DownloadManager.hpp"
#include <iostream>

using namespace std;

downloadManager::DownloadManager::DownloadManager()
{
    cout << "contruct DownloadManager" << endl;
}

downloadManager::DownloadManager::~DownloadManager()
{
    cout << "Descontruct DownloadManager" << endl;
}

void downloadManager::DownloadManager::downloadTestClass()
{
    cout << "DownloadManager : downloadTestClass" << endl;
}

void downloadManager::dmDownloadTest()
{
    cout << "extern : downloadTest" << endl;
}
