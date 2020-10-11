#ifndef CARPI_QT_UTILS_GLOBAL_H
#define CARPI_QT_UTILS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(UTILS_LIBRARY)
#  define UTILS_EXPORT Q_DECL_EXPORT
#else
#  define UTILS_EXPORT Q_DECL_IMPORT
#endif

#endif //CARPI_QT_UTILS_GLOBAL_H
