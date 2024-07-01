#include "mypluginconstants.h"
#include "myplugintr.h"

#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/coreconstants.h>
#include <coreplugin/icontext.h>
#include <coreplugin/icore.h>

#include <extensionsystem/iplugin.h>

#include <QAction>
#include <QMainWindow>
#include <QMenu>
#include <QMessageBox>

namespace Myplugin::Internal {

class MypluginPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "Myplugin.json")

public:
    MypluginPlugin();
    ~MypluginPlugin() final;

    void initialize() final;
    void extensionsInitialized() final;
    ShutdownFlag aboutToShutdown() final;

private:
    void triggerAction();
};

MypluginPlugin::MypluginPlugin()
{
    // Create your members
}

MypluginPlugin::~MypluginPlugin()
{
    // Unregister objects from the plugin manager's object pool
    // Delete members
}

void MypluginPlugin::initialize()
{
    // Register objects in the plugin manager's object pool
    // Load settings
    // Add actions to menus
    // Connect to other plugins' signals
    // In the initialize function, a plugin can be sure that the plugins it
    // depends on have initialized their members.

    // If you need access to command line arguments or to report errors, use the
    //    bool IPlugin::initialize(const QStringList &arguments, QString *errorString)
    // overload.

    auto action = new QAction(Tr::tr("Myplugin Action"), this);
    Core::Command *cmd = Core::ActionManager::registerAction(
        action, Constants::ACTION_ID, Core::Context(Core::Constants::C_GLOBAL));
    cmd->setDefaultKeySequence(QKeySequence(Tr::tr("Ctrl+Alt+Meta+A")));
    connect(action, &QAction::triggered, this, &MypluginPlugin::triggerAction);

    Core::ActionContainer *menu = Core::ActionManager::createMenu(Constants::MENU_ID);
    menu->menu()->setTitle(Tr::tr("Myplugin"));
    menu->addAction(cmd);
    Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);
}

void MypluginPlugin::extensionsInitialized()
{
    // Retrieve objects from the plugin manager's object pool
    // In the extensionsInitialized function, a plugin can be sure that all
    // plugins that depend on it are completely initialized.
}

ExtensionSystem::IPlugin::ShutdownFlag MypluginPlugin::aboutToShutdown()
{
    // Save settings
    // Disconnect from signals that are not needed during shutdown
    // Hide UI (if you add UI that is not in the main window directly)
    return SynchronousShutdown;
}

void MypluginPlugin::triggerAction()
{
    QMessageBox::information(
        Core::ICore::mainWindow(),
        Tr::tr("Action Triggered"),
        Tr::tr("This is an action from Myplugin."));
}

} // namespace Myplugin::Internal

#include <myplugin.moc>
