    //
    //  iBS_Matrix.h
    //  https://github.com/iBeanSoftware/iBS_LIB/blob/master/iBS_Matrix.h
    //
    //  Created by nash(https://github.com/NashBean) on 11/29/15.
    //  Copyright 2015 iBean Software (https://ibeansoftware.github.io/),
    //  All rights reserved.
    //

    #ifndef iBS_Matrix_h
    #define iBS_Matrix_h

    const int Matrix_MAJOR_VERSION = 1;
    const int Matrix_MINOR_VERSION = 1;

    #include <iostream>
    #include <vector>
    namespace iBS
    {
    typedef  struct Matrix 
    {
        std::vector<std::vector<int> > a; 
        
        Matrix():a(0){};
        Matrix(int r, int c):a(r)
        {
            for(int rs=0; rs<a.size(); ++rs) 
            {
                a[rs].resize(c);
            }
        };
        ~Matrix(){if(a.size()) clear();};

        void clear()
        {
            if(a.size())
            {
                for(int rs=0; rs<a.size(); ++rs) 
                {
                    if(a[rs].size()) a[rs].clear();
                }
                a.clear();
            }
        };
        
        void resize(int r, int c)
        {
            a.resize(r);
            for (int rs=0; rs<r; ++rs) 
            {
                a[rs].resize(c);
            }
        }
        
        Matrix& operator =(Matrix& o)
        {
            resize(o.a.size(), o.a[0].size());
            for(int i=0;i<a.size();i++) 
                for(int j=0;j<a[i].size();j++) 
                {
                    a[i][j] = o.a[i][j];
                }
            return *this;
        }
        
        Matrix& operator +(Matrix& o)
        {
            for(int i=0;i<a.size();i++) 
                for(int j=0;j<a[i].size();j++) 
                {
                    a[i][j] = a[i][j] + o.a[i][j];
                }
            return *this;
        }
        Matrix& operator -(Matrix& o)
        {
            for(int i=0;i<a.size();i++) 
                for(int j=0;j<a[i].size();j++) 
                {
                    a[i][j] = a[i][j] - o.a[i][j];
                }
            return *this;
        }
        Matrix& operator *(Matrix& o)
        {
            if(a[0].size() != o.a.size()) return *this;
            
            Matrix tm;
            resize(a.size(), o.a[0].size());
            
            for(int i=0;i<tm.a.size();i++) 
                for(int j=0;j<tm.a[i].size();j++) 
                {
                    tm.a[i][j] = 0;
                    for (int c=0; c<a[i].size(); c++) 
                    {
                        tm.a[i][j] += a[i][c] * o.a[c][j];
                    }
                    
                }
            *this = tm;
            return *this;
        }
        Matrix& operator ^(int power)
        {
            Matrix  tM2;
            tM2 = *this;

        //   not <= below \/ because first time counts as 2
            for(int i=1; i<power; ++i)
                *this = (*this) * (tM2);
            
            return *this;
        }
        
        void print()
        {
            for(int i=0;i<a.size();i++) 
            {
                for(int j=0;j<a[i].size();j++) 
                {
                    std::cout << a[i][j] << ' ';
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
    };

    }; // end of namespace iBS

    #endif // iBS_Matrix_h
