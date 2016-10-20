#ifndef CONFIGFILE_H
#define CONFIGFILE_H


/*
 *
 *  read configure file
 *
 */

#include <QString>
#include <QMap>


class ConfigFile
{
public:
    QMap<QString,QString> m_content;
    ConfigFile(const QString& fileName);
    QString getValue(const QString &key,const QString& section="")const;
private:
    std::string trim(const std::string &source,const char* delims=" \t\r\n");
    std::string makeLower(const std::string &str);

};

#endif // CONFIGFILE_H
