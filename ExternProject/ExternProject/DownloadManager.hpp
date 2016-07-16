//
//  DownloadManager.hpp
//  ExternProject
//
//  Created by JiangZhongjin on 16/7/16.
//  Copyright © 2016年 JiangZhongjin. All rights reserved.
//

#ifndef DownloadManager_hpp
#define DownloadManager_hpp

#include <stdio.h>

namespace downloadManager
{
    extern void dmDownloadTest();
    
    extern void dmDownloadTestTwo();
    
    class DownloadManager
    {
    public:
        DownloadManager();
        ~DownloadManager();
        
        void downloadTestClass();
    private:
    };
    
}
#endif /* DownloadManager_hpp */
