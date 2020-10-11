#ifndef CARPI_QT_UTILS_H
#define CARPI_QT_UTILS_H

#ifdef UTILS_LOADABLE
#include "Utils_global.h"
#endif

#include <QFile>
#include <QWidget>

#ifdef UTILS_LOADABLE
QT_BEGIN_NAMESPACE
namespace Ui { class Utils; }
QT_END_NAMESPACE
#endif

class Utils : public QWidget
{
Q_OBJECT
private:
#ifdef UTILS_LOADABLE
    Ui::Utils *ui;
#endif

public:
    explicit Utils(QWidget *parent = nullptr);
    ~Utils() override;

    static bool isCPUIntel();
    static float getCPUTemp();
    static bool isPi();
};

#ifdef UTILS_LOADABLE
extern "C" {
    UTILS_EXPORT int getDefaultIndex();
    UTILS_EXPORT char* getName();
    UTILS_EXPORT QWidget* create();
    UTILS_EXPORT int getVersion();
    UTILS_EXPORT QStringList getSettingsKeys();
    UTILS_EXPORT QStringList getDependencies();
};
#endif

#endif //CARPI_QT_UTILS_H
