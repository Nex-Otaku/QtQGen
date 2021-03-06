#include "stdafx.h"
#include "controls.h"
#include "mainwindow.h"

int main(int argc, char **argv)
{
	setlocale (LC_CTYPE,"rus");

	QApplication application(argc, argv);

	QTranslator qtTranslator;
	qtTranslator.load("qt_" + QLocale::system().name(),
		QLibraryInfo::location(QLibraryInfo::TranslationsPath));
	application.installTranslator(&qtTranslator);

	application.setApplicationName("QGen");
	application.setApplicationVersion("0.0.1");
	Ui::Controls *_controls = new Ui::Controls(application.applicationDirPath());

    if(_controls->UpdateLocale(_controls->GetSettings()->GetLangId()))
        application.installTranslator(_controls->GetTranslator());

	Ui::MainWindow *window = new Ui::MainWindow(_controls);
	_controls->SetMainWindow(window);
	_controls->SetLocListBox(window->GetLocListBox());
	_controls->SetTabsWisget(window->GetTabsWidget());
	_controls->NewGame();
	window->UpdateTitle();
	window->show();

	return application.exec();
}




