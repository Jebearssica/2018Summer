#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_IGGE.h"

class IGGE : public QMainWindow   //����������
{
	Q_OBJECT

public:
	IGGE(QWidget *parent = Q_NULLPTR);

private:
	Ui::IGGEClass ui;
};
