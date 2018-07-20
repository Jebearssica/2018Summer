#include "First.h"
#include"ui_First.h"
#include<string>
First::First(QWidget *parent)
	: QMainWindow(parent) 

{
	ui.setupUi(this);
	connect(ui.pushButton,SIGNAL(clicked()) ,this, SLOT(on_OpenImage_trigger()));
	//connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(quit()));
	QHBoxLayout* mainLayout = new QHBoxLayout;
	mainLayout->addWidget(ui.pushButton);
	mainLayout->addWidget(ui.graphicsView);
	mainLayout->addWidget(ui.textBrowser);
	//mainLayout->addWidget(ui.pushButton_2);
	ui.centralWidget->setLayout(mainLayout);
    QAction* openAction = new QAction(tr("&open"), this);
	QAction* newAction = new QAction(tr("&new"), this);
	QAction* saveAction = new QAction(tr("&save"), this);
	ui.menuBar->addAction(openAction);
	ui.menuBar->addSeparator();
	ui.menuBar->addAction(newAction);
	ui.menuBar->addSeparator();
	ui.menuBar->addAction(saveAction);
	ui.menuBar->addSeparator();
	
}
void First::on_OpenImage_trigger() {
	//�ҵĴ����У�������ͼƬ��ʱ�򣬾�ͼƬ����ʧ�ˣ������ҵĴ����б༭���ܣ�����û�������ʧȥ�˸Ķ������ͷ��
	int selt;
	if (ui.graphicsView->scene()!=0) {
		selt=saveOrDiscard();
		sence->clear();
	}
	if (selt == QMessageBox::Cancel) {
		ui.textBrowser->setText("operation cancel");   //ȡ����ͼƬ
		return;
	} 
	if (selt == QMessageBox::Discard) {
		sence->clear();  
	}
	QFileDialog* seltOpenFile = new QFileDialog(this, tr("��ͼƬ"), ".", tr("Image File(*.jpg *.png *.bmp)"));
	//����һ��ѡ����ļ��ĶԻ��򣬸�������������򴰿ڣ������Ǵ�ͼƬ��Ĭ��·��Ϊ����㣬�ļ����͹���Ϊ�����ļ�
	QString path = seltOpenFile->getOpenFileName();

	//����4���ǿ�yangcrazy30�Ĵ��룬��û���ü�ȥ��opencv��ֻ�ǿ�����ӱ������˽������ڸ�ʲô����ͷ��ȥѧ

	img = cv::imread(path.toStdString());  //��ʼ��ͼƬ����
	cv::cvtColor(img, img, CV_BGR2RGB);//��BGR˳���opencvͼƬתΪRGB��˳�򣬲���Ϊ����ͼƬ�����ͼƬ����ʽ��PS:Ҳ���ǽ�imgת����ķ���ֵ��ͷ����QImg
	QImage QImg = QImage((const unsigned char*)(img.data), img.cols, img.rows, QImage::Format_RGB888);//��MAT��ʽת��ΪQImage��ʽ��
	QImage scaledImg = QImg.scaled(ui.graphicsView->size(), Qt::KeepAspectRatio);   //��ͼƬ����������Ϊ�Ӵ���С

    sence = new QGraphicsScene;        //������������ͼƬ���볡��
	sence->addPixmap(QPixmap::fromImage(scaledImg));
	ui.graphicsView->setScene(sence);//graphicsView�󶨳���
	ui.graphicsView->show();
	ui.textBrowser->setText("open" + path);
}

int First::saveOrDiscard(){
	QMessageBox msg;
	msg.setText("save the picture?");
	msg.setStandardButtons(QMessageBox::Save
		| QMessageBox::Discard
		| QMessageBox::Cancel);
	msg.setDefaultButton(QMessageBox::Save);
	int selt = msg.exec();
	QString savePath; std::string ;
	std::string fileAsSave;
	//QScreen *screen = QGuiApplication::primaryScreen();
	switch (selt) {
	case QMessageBox::Save:
		savePath = QFileDialog::getSaveFileName(this, tr("Save Image"), "", tr("Images (*.png *.bmp *.jpg)"));
		fileAsSave = savePath.toStdString();
		cv::imwrite(fileAsSave, img);
		ui.textBrowser->setText(savePath + "saved");
		return QMessageBox::Save;
		break;
	case QMessageBox::Discard:
		return QMessageBox::Discard;
		break;
	case QMessageBox::Cancel:
		return QMessageBox::Cancel;
		break;
	}
}
