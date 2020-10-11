#include "Utils.h"

#ifdef UTILS_LOADABLE
#include "ui_utils.h"
#endif

Utils::Utils(QWidget *parent): QWidget(parent), 
#ifdef UTILS_LOADABLE
ui(new Ui::Utils)
#endif
{
#ifdef UTILS_LOADABLE
    ui->setupUi(this);
#endif
    // todo signals and slots for labels
}

Utils::~Utils()
{
#ifdef UTILS_LOADABLE
    delete ui;
#endif
}

bool Utils::isPi() {
    return QFile::exists("/sys/firmware/devicetree/base/model");
}

float Utils::getCPUTemp() {
    if(Utils::isPi() || Utils::isCPUIntel()){
        QFile t("/sys/class/thermal/thermal_zone0/temp");
        if(t.open(QIODevice::ReadOnly | QIODevice::Text)) return t.readAll().toFloat() / 1000;
    }
    return -1;
}

bool Utils::isCPUIntel() {
    QFile t("/proc/cpuinfo");
    if(t.open(QIODevice::ReadOnly | QIODevice::Text)) return t.readAll().contains("Intel");
    return false;
}


#ifdef UTILS_LOADABLE
extern "C" UTILS_EXPORT QWidget* create() {
    return new Utils();
}

extern "C" UTILS_EXPORT char* getName() {
    return (char*) "Utils";
}

extern "C" UTILS_EXPORT int getDefaultIndex(){
    return -1;
}

extern "C" UTILS_EXPORT QStringList getSettingsKeys(){
    return QStringList(); // << KEY_SOMETHING_SOMETHING
}

extern "C" UTILS_EXPORT QStringList getDependencies(){
    return QStringList(); // << "something"
}

extern "C" UTILS_EXPORT int getVersion(){
    return 1;
}
#endif
