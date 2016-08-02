//
//  JString.hpp
//  JStringProject
//
//  Created by JiangZhongjin on 16/7/17.
//  Copyright © 2016年 JiangZhongjin. All rights reserved.
//

#ifndef JString_hpp
#define JString_hpp

#include <stdio.h>
#include <iostream>

namespace grady {

    class JString
    {
    public:
        JString();
        
        //带参构造函数
        JString(const char *str);
                
        ~JString();
        
        //拷贝构造
        JString(const JString &obj);
        //复制初始化
        JString &operator=(const JString &obj);
        
        //把后面字符串加在*this上
        JString &operator+=(const JString &obj);
        //把后面字符串加在前面
        friend JString operator+(const JString &obj,const JString &obj1);
        //==判断字符串是否相等
        bool operator==(const JString &str)const;
        //!=判断字符串是否相等
        bool operator!=(const JString &str)const;
        //[]下标运算符重载
        char operator[](int index);
        //<<运算符重载
        friend std::ostream &operator<<(std::ostream &os,const JString &obj);
        //>>运算符重载
        friend std::istream &operator>>(std::istream &is,const JString &obj);
        //返回字符串长度
        int leng()const;
        //取从position所指位置连续取len个字符组成子串返回
        JString &subString(int position,int len);
        
        void UpperCase();
        void LowerCase();
    private:
        char *data;
        int length;
        
    };
    
    //JString operator+(const JString &obj,const JString &obj1);
    
    //std::ostream &operator<<(std::ostream &os,const JString &obj);
}


#endif /* JString_hpp */
