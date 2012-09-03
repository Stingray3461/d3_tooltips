#ifndef D3_TOOLTIP_H
#define D3_TOOLTIP_H

#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <QThread>
#include <QObject>
#include <QStandardItemModel>

class D3_Item;

class D3_ToolTip : public QThread
{
    Q_OBJECT

public:
    enum TT_TYPE {D3_NAME, D3_TYPE, D3_SLOT, D3_RATING, D3_RATING_LABEL, D3_SPECIAL_STATS, D3_STATS, D3_REQUIRED_LEVEL, D3_COST, D3_DURABILITY, D3_REQUIRED_CLASS, ENUM_END};
    static const char *type_string[ENUM_END];
    QStandardItemModel *model;

    D3_ToolTip();
    void resetPtr();
    char *init();
    void run();
    bool chkUnik(char *buffer, int offset);
    long getProcID();
    bool makeItem(QString custom);
    char *slug(char *str);

signals:
     void progress(int);

private:
    HANDLE hndl;
    int *ptr;
    char *ptr_count;
    static const unsigned char hash[11][8], parent_hash[11][8], unik0[4], unik1[24];

};

#endif // D3_TOOLTIP_H