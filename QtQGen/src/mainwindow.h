#ifndef _MAIN_WINDOW_H_
#define _MAIN_WINDOW_H_

#define TITLE "QGen"
#define QSP_CONFIG "qspgui.cfg"

enum
{
	ID_MAINDESC,
	ID_VARSDESC,
	ID_OBJECTS,
	ID_ACTIONS,
	ID_VIEWPIC,
	ID_INPUT,
	ID_TIMER,

	ID_DUMMY
};

namespace Ui
{

	class MainWindow : public QMainWindow
	{
		Q_OBJECT

	public:
		MainWindow();
		//~MainWindow();

	private:
		void CreateMenuBar();
		void CreateToolBar();
		void CreateStatusBar();
		void CreateDockWindows();
	};
} // namespace Ui

#endif // _MAIN_WINDOW_H_