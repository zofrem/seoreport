#ifndef SEOREPORT_H
#define SEOREPORT_H

#include <string>
using namespace std;
/////////////////////////////////////////////////////////
/// SeoReport
/// parse CVS and find SEO incorrect URLs 
/////////////////////////////////////////////////////////

class SeoReport {
  public:
    static bool isInvalid(const string& line);

  
  private:
    static size_t findUrlBegin(const string& line);
    static size_t findUrlEnd(const string& fromUrl);
    static bool isLastSlash(const string& url);
};

#endif
