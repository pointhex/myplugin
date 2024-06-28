#pragma once

#include "myplugin_global.h"

#include <extensionsystem/iplugin.h>

namespace Myplugin::Internal {

class MypluginPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "Myplugin.json")

public:
    MypluginPlugin();
    ~MypluginPlugin() override;

    void initialize() override;
    void extensionsInitialized() override;
    ShutdownFlag aboutToShutdown() override;

private:
    void triggerAction();
};

} // namespace Myplugin::Internal
