#pragma once

#include <QWidget>
#include <QPainter>
#include <QDebug>

class WidgetCanvas : public QWidget
{
	Q_OBJECT

public:
	WidgetCanvas(QWidget *parent);
	~WidgetCanvas();

	

public slots:
	void GetPixelstream(QString, int w, int h);
	void SetEffectRGB();
	void SetEffectRed();
	void SetEffectGreen();
	void SetEffectBlue();
	void SetEffectBright();
	void SetEffectGreyscale();
	void SetEffectDither();



protected:
	void paintEvent(QPaintEvent* event);
	int HextoInt(std::string hex);

private:
	std::string pixels;
	int width;
	int height;

	int paintmode;
	// None		= -1
	// RGB		= 0
	// R		= 1
	// G		= 2
	// B		= 3
	// Bright	= 4
	// Grey		= 5
	// Dither	= 6

	
};
