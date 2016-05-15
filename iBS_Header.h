//
//  iBS_Header.h
//  iBS_LIB
//
//  Created by nash on 5/15/16.
//  Copyright 2016 iBean Software. 
//  All rights reserved.
//  http://www.NashBean.github.io/index.html 
//
#ifndef iBS_Header_h
#define iBS_Header_h


namespace iBS 
{
    
    struct uint 
    {
        
        uint():value(0){}; 
        uint(int v):value((uint32_t)v){}; 
        uint(long v):value((uint32_t)v){}; 
        uint(char v):value((uint32_t)v){}; 
        uint(uint const &v):value(v.value){}; 
        uint(uint32_t v):value(v){}; 
        
        uint& operator=(uint unicode)
        {
            set(unicode.value); 
            return *this;
        };
        uint& operator=(uint32_t unicode)
        {
            set(unicode); 
            return *this;
        };
        
        bool operator==(char c)
        {
            return (value == (uint32_t)c);
        };
        bool operator==(int i)
        {
            return (value == (uint32_t)i);
        };
        bool operator==(uint32_t unicode)
        {
            return (value == unicode);
        };
        
        uint32_t get()
        {
            return value;
        };
        void set(uint32_t v)
        {
            value = v;
        };
        
    private:    
        uint32_t value;
        
    };
    
    
}// end of iBS namespace
#endif // iBS_Header_h