#pragma once

#include <qglobal.h>

#if defined(MYPLUGIN_LIBRARY)
#define MYPLUGIN_EXPORT Q_DECL_EXPORT
#else
#define MYPLUGIN_EXPORT Q_DECL_IMPORT
#endif
