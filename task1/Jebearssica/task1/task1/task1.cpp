#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>

#include "task1.h"
#define MENU_NUMBER 3
task1::task1(QWidget *parent): QMainWindow(parent) {
	ui.setupUi(this);	//自动生成的UI界面，相当于初始化，可在之后的代码覆盖修改

	QMenu *Menu[MENU_NUMBER];											//菜单
	Menu[0]	= menuBar()->addMenu(tr("New"));
	Menu[1] = menuBar()->addMenu(tr("File"));
	Menu[2] = menuBar()->addMenu(tr("Exit"));
	//Menu[0]->addAction(NewWindowAction);
	//Menu[1]->addAction(OpenAction);
	//Menu[2]->addAction(ExitAction);

	//按钮(工具栏)
	OpenAction = new QAction(QIcon(":/images/test.jpg"), NULL, this);	//没有快捷键
	OpenAction->setStatusTip(tr("Waiting to be completed"));			//状态栏显示
	connect(OpenAction, &QAction::triggered, this, &task1::OpenFile);	//与打开文件关联

	QToolBar *ToolBar = addToolBar(tr("File_ToolBar"));
	ToolBar->addAction(OpenAction);

}

task1::~task1() {
	delete OpenAction;
}

void task1::OpenFile() {
	QDialog *Dialog = new QDialog;
	Dialog->setAttribute(Qt::WA_DeleteOnClose);
	Dialog->setWindowTitle(tr("Open a picture"));
	Dialog->exec();
}
