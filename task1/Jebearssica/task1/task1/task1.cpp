#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>

#include "task1.h"
#define MENU_NUMBER 3
task1::task1(QWidget *parent): QMainWindow(parent) {
	ui.setupUi(this);	//�Զ����ɵ�UI���棬�൱�ڳ�ʼ��������֮��Ĵ��븲���޸�

	QMenu *Menu[MENU_NUMBER];											//�˵�
	Menu[0]	= menuBar()->addMenu(tr("New"));
	Menu[1] = menuBar()->addMenu(tr("File"));
	Menu[2] = menuBar()->addMenu(tr("Exit"));
	//Menu[0]->addAction(NewWindowAction);
	//Menu[1]->addAction(OpenAction);
	//Menu[2]->addAction(ExitAction);

	//��ť(������)
	OpenAction = new QAction(QIcon(":/images/test.jpg"), NULL, this);	//û�п�ݼ�
	OpenAction->setStatusTip(tr("Waiting to be completed"));			//״̬����ʾ
	connect(OpenAction, &QAction::triggered, this, &task1::OpenFile);	//����ļ�����

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
