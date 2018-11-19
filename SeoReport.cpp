#include <iostream>
#include <algorithm>
#include "SeoReport.h"

size_t SeoReport::findUrlBegin(const string& line)
{
  size_t starth = line.find("http://");
  size_t starts = line.find("https://");
  size_t startH = line.find("HTTP://");
  size_t startS = line.find("HTTPS://");
	
  size_t urlStart;
  if(starth != string::npos)
    urlStart = starth;
  else if(starts != string::npos)
    urlStart = starts;
  else if(startH != string::npos)
    urlStart = startH;
  else if(startS != string::npos)
    urlStart = startS;
  else
    return string::npos;
}

size_t SeoReport::findUrlEnd(const string& fromUrl)
{
  size_t urlCommaEnd = fromUrl.find(',');
  size_t urlSpaceEnd = fromUrl.find(' ');
  size_t urlLineEnd = fromUrl.length();
  size_t urlEnd = min(min(urlCommaEnd, urlSpaceEnd), urlLineEnd);
  return urlEnd;
}

bool SeoReport::isLastSlash(const string& url)
{
  auto pos = url.find_last_of('/');
  ++pos;
  return(url.length() == pos);
}

bool SeoReport::isInvalid(const string& line)
{
  const unsigned int MAX_SLASHES = 4;
  size_t beginUrl = findUrlBegin(line);
  string fromUrl;
  if(string::npos != beginUrl)
    fromUrl = line.substr(beginUrl);
  else
    return true;
  
  size_t endUrl = findUrlEnd(fromUrl);
  bool ret = true;
  if(string::npos != endUrl)
  {
    string url = fromUrl.substr(0, endUrl);
    cout << "URL:" << url << endl;
    auto n = std::count(url.begin(), url.end(), '/');
    if(MAX_SLASHES > n)
      ret = false;
    else if(MAX_SLASHES == n)
      if(isLastSlash(url))
	ret = false;
  }
  cout << "isInvalid: " << (ret ? "YES" : "NOT") << endl;
  cout << endl;
  return ret;
}
