#include "ConfigFile.h"

#include <fstream>

ConfigFile::ConfigFile(const QString& fileName)
{
    std::ifstream file(fileName.toStdString().c_str());
    std::string line,key,value,insection;
    int posEqual;

    while(std::getline(file,line))
    {
        line =trim(line);// beside space enter table ..
        if(!line.length())continue;
        if(line[0]=='#')continue;
        if(line[0]=='[')
        {
            insection=trim(line.substr(1,line.find(']')-1));
            continue;
        }

        posEqual = line.find('=');
        key = trim(line.substr(0,posEqual));
        value = trim(line.substr(posEqual+1));
        m_content[QString((insection+'/'+key).c_str())]=QString(value.c_str());
    }
    file.close();
}

std::string ConfigFile::trim(const std::string &source, const char *delims)
{
    std::string res(source);
    res = makeLower(res);
    std::string::size_type index = res.find_last_not_of(delims);
    if(index !=std::string::npos)
    {
        res.erase(++index);
    }
    index = res.find_first_not_of(delims);
    if(index !=std::string::npos)
    {
        res.erase(0,index);
    }
    else
    {
        res.erase();
    }
    return res;
}

QString ConfigFile::getValue(const QString &key,const QString& section) const
{
    QMap<QString,QString>::const_iterator constIter=m_content.find(section+'/'+key);
    if(constIter ==m_content.end())
    {
       // throw "not exist";
        return NULL;
    }
    return constIter.value();
}

std::string ConfigFile::makeLower(const std::string &str)
{
    std::string s = str;
    for(std::string::iterator iter =s.begin();iter!=s.end();++iter)
    {
        if(tolower(*iter) != (int)*iter)// beside number
        {
            *iter = (char)tolower(*iter);
        }
    }
    return s;
}
