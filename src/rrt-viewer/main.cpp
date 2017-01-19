
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QtQuick>
#include <QtWidgets>
#include <iostream>
#include "MainWindow.hpp"

using namespace std;

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    app.setOrganizationName("RoboJackets");
    app.setApplicationName("Interactive RRT");

    // load qml
    QQmlApplicationEngine engine(nullptr);
    engine.rootContext()->setContextProperty("main", &engine);
    engine.addImportPath("./src/rrt-viewer");  // TODO: fix
    engine.load("./src/rrt-viewer/main.qml");

    // get reference to main window from qml
    auto r = engine.rootObjects()[0];
    cout << r->objectName().toStdString() << endl;
    auto win = static_cast<QQuickView*>(r);
    if (!win) {
        cerr << "Failed to load qml" << endl;
        exit(1);
    }

    win->show();

    return app.exec();
}
