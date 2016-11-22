// uva-10340-all in all.cpp : 定义控制台应用程序的入口点。
//

// poj-1936-all in all.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
  
int main(long i,long j)  
{  
    char s1[100000],s2[100000];  
    while(cin>>s1>>s2)  
    {  
        long len1=strlen(s1);  //s2中找s1
        long len2=strlen(s2);  
        i=0;  
        j=0;  
        while(true)  
        {  
            if(i==len1)  
            {  
                cout<<"Yes"<<endl;  
                break;  
            }  
            else if(i<len1 && j==len2)  
            {  
                cout<<"No"<<endl;  
                break;  
            }  
            if(s1[i]==s2[j])  
            {  
                i++;  
                j++;  
            }  
            else  
                j++;  
        }  
        memset(s1,'\0',sizeof(s1));  
        memset(s2,'\0',sizeof(s2));  
    }  
    return 0;  
} 



