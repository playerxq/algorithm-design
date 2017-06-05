// leetcode-591-字符串处理.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution {
private:
	bool validHeader(const string &code){
		return code.empty() || code[0] == '<';
	}
	bool validTag(const string &Tag){
		//validated  size
		if (Tag.size() <= 0 || Tag.size() > 9)
			return false;

		//validated  uppercase
		for (int i = 0; i < Tag.size(); ++i){
			if (!isupper(Tag[i]))
				return false;
		}
		return true;
	}
public:
	bool isValid(string code) {
		if (!validHeader(code)){
			return false;
		}
		int index = 0;
		while (index != string::npos){
			index = code.find("<![CDATA[");
			if (index == 0)
				return false;
			if (index != string::npos){
				int lindex = code.find("]]>", index);
				if (lindex == string::npos || lindex == code.size() - 3){ //找到尾或者没有字符
					return false;
				}
				code.erase(index, lindex - index + 3);
			}
		} //erase(<![CDATA]>)
		int TagHeaderFIdx = 0, TagHeaderRIdx = code.find('>');
		if (TagHeaderRIdx == string::npos){
			return false; //Can find '>'
		}
		string TAGHeader = code.substr(1, TagHeaderRIdx - 1);
		int TAGEnderFIdx = code.size() - TagHeaderRIdx - 2;
		if (TAGEnderFIdx < 0){
			return false; // case : "<123456>"
		}
		string TAGEnder = code.substr(code.size() - TagHeaderRIdx - 2);
		if (!validTag(TAGHeader) || "</" + TAGHeader + ">" != TAGEnder){
			return false;
		}
		stack<string> st;
		index = TagHeaderRIdx + 1;
		while (index < TAGEnderFIdx)
		{
			index = code.find("<", index);
			if (index < TAGEnderFIdx)
			{
				int lindex = code.find(">", index);
				if (lindex >= TAGEnderFIdx)
				{
					return false; //can't find '>'
				}
				string Tag = code.substr(index + 1, lindex - index - 1);
				if (Tag[0] != '/' && !validTag(Tag))
				{
					return false; //invalid tag name 
				}
				if (Tag[0] == '/')
				{
					string endTag = Tag.substr(1);
					if (st.empty() || endTag != st.top()){ //validated lastTAG == this EndTAG
						return false;
					}
					st.pop();
				}
				else
				{
					st.push(Tag);
				}
				index++;
			}
		}
		return st.empty();
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

