//
//  JString.cpp
//  JStringProject
//
//  Created by JiangZhongjin on 16/7/17.
//  Copyright © 2016年 JiangZhongjin. All rights reserved.
//

#include "JString.hpp"

using namespace grady;

JString::JString()
{
    data = new char[1];
    length = 0;
}

JString::~JString()
{
    delete [] data;
    length = 0;
}

//带参构造函数
JString::JString(const char *str){
    data = new char[strlen(str) + 1];
    if(!data)
    {
        std::cerr<<"Allocation Error!\n";
        exit(1);
    }
    length = (int)strlen(str);
    strcpy(data,str);
}

JString::JString(const JString &obj)
{
    if (this == &obj)
    {
        return;
    }
    
    //delete  data; 这里这么写是错误的
    //这么写看似可以，其实有一个隐患，就是obj析构以后会导致本对象的data成为野指针
    //data = obj.data;
    data = new char[obj.length + 1];
    
    if(!data)
    {
        std::cerr<<"Allocation Error!\n";
        exit(1);
    }
    
    length = obj.length;
    strncpy(data, obj.data, length);
}

JString &JString::operator=(const JString &obj)
{
    if (this == &obj)
    {
        return *this;
    }
    
    delete [] data;
    //这么写看似可以，其实有一个隐患，就是obj析构以后会导致本对象的data成为野指针
    //data = obj.data;
    data = new char[obj.length + 1];
    
    if(!data)
    {
        std::cerr<<"Allocation Error!\n";
        exit(1);
    }
    
    length = obj.length;
    strncpy(data, obj.data, length);
    
    return *this;
}

JString &JString::operator+=(const JString &obj)
{
    char *temp = data;
    length = length + obj.length;
    data = new char[length + 1];
    
    if (!data)
    {
        std::cerr<<"Allocation Error!\n";
        exit(1);
    }
    
    memset(data, 0, length + 1);
    strncpy(data, temp, strlen(temp));
    strncat(data, obj.data, strlen(obj.data));
    
    delete [] temp;
    
    return *this;
}

JString grady::operator+(const JString &obj,const JString &obj1)
{
    int len = obj.length + obj1.length;
    char *str = new char[len + 1];
    if (!str)
    {
        std::cerr<<"Out of memory!\n";
        exit(1);
    }
    
    strncpy(str, obj.data, strlen(obj.data));
    strncat(str, obj1.data, strlen(obj1.data));
    
    JString jStr(str);
    
    return jStr;
}

bool JString::operator==(const JString &str) const
{
    if (this == &str)
    {
        return true;
    }
    
    if (strcmp(data, str.data)==0)
    {
        return true;
    }
    
    return false;
}

//<<运算符重载
std::ostream &grady::operator<<(std::ostream &os,const JString &obj)
{
    os << obj.data;
    return os;
}

char JString::operator[](int index)
{
    if (index >= length || index < 0)
    {
        std::cout << "error index" << std::endl;
        return NULL;
    }
    return data[index];
}

bool JString::operator!=(const grady::JString &str) const
{
    if (this == &str)
    {
        return false;
    }
    
    if (length != str.length)
    {
        return true;
    }
    
    for (int i = 0; i < length; i++)
    {
        if (data[i] != str.data[i])
        {
            return true;
        }
    }
    
    return false;
}

int JString::leng() const
{
    return length;
}

JString JString::subString(int position, int len)
{

//    if (position < 0 || len < 0 || position + len > length)
//    {
//        delete data;
//        data   = new char[1];
//        length = 0;
//        return *this;
//    }
//    
//    length = len;
//    for (int i = 0; i < length; i++)
//    {
//        data[i] = data[position + i];
//    }
//    data[length] = '\0';
//    
//    return *this;

    if (position < 0 || len < 0 || position + len > length)
    {
        return NULL;
    }
    
    JString tmp;
    tmp.data = new char[len + 1];
    tmp.length = len;
    
    for (int i = 0; i < len; i++)
    {
        tmp.data[i] = data[position + i];
    }
    tmp.data[len] = '\0';
    return tmp;

}

void JString::UpperCase()
{
    for (int i = 0; i < length; i++) {
        if (islower(*(data + i)))
        {
            *(data + i) = toupper( *(data + i) );
        }
    }
}

void JString::LowerCase()
{
    for (int i = 0; i < length; i++)
    {
        if (isupper(*(data + i)))
        {
            *(data + i) = tolower( *(data + i) );
        }
    }
}






