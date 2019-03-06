#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"


#include <iostream>
#include <string>
#include <cstdlib>
#include <string>
#include <QDebug>
#include <QFileDialog>
#include <QTextCodec>
#include <QtEndian>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);

	

public slots:
	void GetFile();

protected:
	std::string LittleEndiantoBigEndian(std::string little);
	QString LittleHextoIntQString(QByteArray bytearray, int pos, int len);\
	int LittleHextoInt(QByteArray bytearray, int pos, int len);

signals:
	void OpenFile(QString);
	void PassInfo(QString);
	void StreamFile(QString);
	void StreamPixels(QString, int, int);

private:
	Ui::MainWindowClass ui;

	QString filename;
	QByteArray filestream;
	QString filestreamString;
	QByteArray pixelstream;
	QString pixelstreamString;

	int width;
	int height;
	int bitsperpixel;
	int dataoffset;
	QString info;
};
