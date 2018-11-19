#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "SeoReport.h"
using namespace std;

vector<string> explode(string const & s, const char delim)
{
  vector<std::string> result;
  istringstream iss(s);
  for(string token; getline(iss, token, delim); )
  {
    result.push_back(token);
  }
  return result;
}

int main (int argc, char *argv[]) 
{
  vector<string> lines;
  string filename;
  if(argv[1])
  {
    filename.assign(argv[1]);
  	cout << "Going to open file: " << filename << endl;
  }
  else
  {
    cout << "Missing filename" << endl;
    return 0;
  }
  
  ifstream infile(filename, std::ifstream::in);

  if(infile.is_open())
  {
    std::vector<std::string> splitName = explode(filename, '.');
    string line;
    while(getline (infile,line) )
    {
      lines.push_back(line);
    }
    infile.close();
    ofstream outfile;
    stringstream exportFile;
    exportFile << splitName[0] << "_report." << splitName[1];
    outfile.open(exportFile.str());
    unsigned int invalidCount = 0;
    for(string const& value : lines)
    {
      if(SeoReport::isInvalid(value))
      {
        outfile << value << endl;
        ++invalidCount;
      }
    }
    outfile.close();
    cout << "From all: " << lines.size() << " was invalid: " << invalidCount << endl;
  }
  else 
    cout << "Unable to open file: " << filename << endl;

  return 0;
}
