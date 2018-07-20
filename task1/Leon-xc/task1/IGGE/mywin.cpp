#include "mywin.h"

mywin::mywin(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

mywin::~mywin()
{
}

void mywin::on_pushButton_clicked()                               //�򿪰�ť�����ʱ�亯��
{
	
	QString fileName = QFileDialog::getOpenFileName(this, tr("OpenFile"), QDir::currentPath());
	if (!fileName.isEmpty())
	{
		loadedImage.load(fileName);
		QSize newSize = loadedImage.size();
	}
	//����image

	//QPainter painter(ui.widget);                                                        //��������painter ����pixmap
	//QPixmap pix;

	//pix = pix.fromImage(loadedImage);// 2

	//painter.drawPixmap(0, 0, (ui.widget->size()).width(), (ui.widget->size()).height(), pix);
	//update();
	
	ui.label_2->setScaledContents(true);
	ui.label_2->setPixmap((QPixmap::fromImage(loadedImage)).scaled(ui.label_2->size().width(),ui.label_2->size().height()));             //��ʾ��Ϊlabel,��һ
	                                                                                                                                     //��label����ʾpixmap
	
	
	/*ui.widget->setAutoFillBackground(true);                     //��ʾ����Ϊwidget������
	QPalette palette;                                             //��QPalette������image��
	palette.setBrush(this->backgroundRole(), QBrush(loadedImage));
	ui.widget->setPalette(palette);*/

	record.append( "open a picture !!!\n");                //��record��¼����
	ui.textBrowser->setText(record);               //��¼������ÿ�ε����¼open a picture
}

void mywin::on_toolButton_clicked()
{
	record.append( "a toolbutton is clicked !!!\n");                //��record��¼����

	ui.textBrowser->setText(record);
}
void mywin::on_horizontalSlider_valueChanged(int value)
{
	record.append("horizontalSlider value Changed !!!\n");                //��record��¼����	

	ui.textBrowser->setText(record);
}
void mywin::on_verticalSlider_valueChanged(int value)
{
	record.append("verticalSlider value Changed !!!\n");                //��record��¼����

	ui.textBrowser->setText(record);
}
void mywin::on_buttonBox_clicked()
{
    record.append("buttonBox is clicked !!!\n");                //��record��¼����

	ui.textBrowser->setText(record);
}
