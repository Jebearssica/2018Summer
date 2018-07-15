#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_task1.h"

class task1 : public QMainWindow
{
	Q_OBJECT

public:
	task1(QWidget *parent = Q_NULLPTR);

private:
	Ui::task1Class ui;
};
