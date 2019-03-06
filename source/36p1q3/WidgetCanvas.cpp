#include "WidgetCanvas.h"

WidgetCanvas::WidgetCanvas(QWidget *parent)
	: QWidget(parent)
{
	paintmode = -1;
	width = 0;
	height = 0;
}

WidgetCanvas::~WidgetCanvas()
{
}

// Get data hex string from MainWindow, as well as additional values necessary for rendering image.
void WidgetCanvas::GetPixelstream(QString s, int w, int h) {
	pixels = s.toStdString();
	width = w;
	height = h;
	paintmode = 0;
	this->update();
	return;
}

// This function is executed on selection of effect.
void WidgetCanvas::SetEffectRGB() {
	paintmode = 0;
	this->update();
	return;
}

// This function is executed on selection of effect.
void WidgetCanvas::SetEffectRed() {
	paintmode = 1;
	this->update();
	return;
}

// This function is executed on selection of effect.
void WidgetCanvas::SetEffectBlue() {
	paintmode = 2;
	this->update();
	return;
}

// This function is executed on selection of effect.
void WidgetCanvas::SetEffectGreen() {
	paintmode = 3;
	this->update();
	return;
}

// This function is executed on selection of effect.
void WidgetCanvas::SetEffectBright() {
	paintmode = 4;
	this->update();
	return;
}

// This function is executed on selection of effect.
void WidgetCanvas::SetEffectGreyscale() {
	paintmode = 5;
	this->update();
	return;
}

// This function is executed on selection of effect.
void WidgetCanvas::SetEffectDither() {
	paintmode = 6;
	this->update();
	return;
}

// This event draws the image according to the "drawmode".
void WidgetCanvas::paintEvent(QPaintEvent* event) {
	QPainter painter(this);
	QImage image(width, height, QImage::Format_RGB32);			// This image is for the normal size painting.
	QImage largeimage(width*2, height*2, QImage::Format_RGB32); // This image is for the 2x size dither painting.
	int x, y, i, j, m, n = 0;	
	int r, g, b = 0;
	int Y_, Co, Cg, tmp = 0;
	int Y__, U, V, t = 0;
	int D[2][2] = { { int(256 * 1 / 5), int(256 * 2/ 5) }, { int(256 * 3 / 5), int(256 * 4 / 5) } };	// Dither Matrix of [1, 2], [3, 4].

	switch (paintmode) {
	case 0:
		qDebug() << "Painting: RGB";

		// Set pixels.
		for (x = 0; x < width; x++) {
			for (y = 0; y < height; y++){
				// Go through pixel by pixel.
				// For each triplet of bytes, get the 0-255 RGB value.
				r = HextoInt(pixels.substr(((height*y) + x) * 6 + 4, 2));
				b = HextoInt(pixels.substr(((height*y) + x) * 6 + 2, 2));
				g = HextoInt(pixels.substr(((height*y) + x) * 6, 2));
				image.setPixel(x, height-1-y, qRgb(r, b, g));
			}
		}

		// Draw image.
		painter.drawImage(QPoint(0, 0), image);
		qDebug() << "Done: RGB";
		break;

	case 1:
		qDebug() << "Painting: Red Channel";

		// Set pixels.
		for (x = 0; x < width; x++) {
			for (y = 0; y < height; y++) {
				// Go through pixel by pixel.
				// For each triplet of bytes, get the 0-255 R value.
				// Set others to 0.
				r = HextoInt(pixels.substr(((height*y) + x) * 6 + 4, 2));
				g = 0;
				b = 0;
				image.setPixel(x, height - 1 - y, qRgb(r, b, g));
			}
		}

		// Draw image.
		painter.drawImage(QPoint(0, 0), image);
		qDebug() << "Done: Red Channel";
		break;

	case 2:
		qDebug() << "Painting: Green Channel";

		// Set pixels.
		for (x = 0; x < width; x++) {
			for (y = 0; y < height; y++) {
				// Go through pixel by pixel.
				// For each triplet of bytes, get the 0-255 G value.
				// Set others to 0.
				r = 0;
				b = 0;
				g = HextoInt(pixels.substr(((height*y) + x) * 6, 2));
				image.setPixel(x, height - 1 - y, qRgb(r, b, g));
			}
		}

		// Draw image.
		painter.drawImage(QPoint(0, 0), image);
		qDebug() << "Done: Green Channel";
		break;

	case 3:
		qDebug() << "Painting: Blue Channel";

		// Set pixels.
		for (x = 0; x < width; x++) {
			for (y = 0; y < height; y++) {
				// Go through pixel by pixel.
				// For each triplet of bytes, get the 0-255 B value.
				// Set others to 0.
				r = 0;
				b = HextoInt(pixels.substr(((height*y) + x) * 6 + 2, 2));
				g = 0;
				image.setPixel(x, height - 1 - y, qRgb(r, b, g));
			}
		}

		// Draw image.
		painter.drawImage(QPoint(0, 0), image);
		qDebug() << "Done: Blue Channel";
		break;

	case 4:
		qDebug() << "Painting: 1.5x Brightness";

		// Set pixels.
		for (x = 0; x < width; x++) {
			for (y = 0; y < height; y++) {
				// Go through pixel by pixel.
				// For each triplet of bytes, get the 0-255 RGB value.
				r = HextoInt(pixels.substr(((height*y) + x) * 6 + 4, 2));
				b = HextoInt(pixels.substr(((height*y) + x) * 6 + 2, 2));
				g = HextoInt(pixels.substr(((height*y) + x) * 6, 2));
				
				// Convert to YUV using formula from:
				// https://en.wikipedia.org/wiki/YUV
				Y__ = (0.299 * r) + (0.587 * g) + (0.114 * b);
				U   = (-0.147 * r) + (-0.289 * g) + (0.436 * b);
				V   = (0.615 * r) + (-0.515 * g) + (-0.100 * b);

				// Increase YUV to 1.5 (with 255 upper limit).
				Y__ = std::min(255, int(Y__ * 1.5));

				// Convert back to RGB.
				r = std::min(255, int(Y__ + (1.140 * V)));
				g = std::min(255, int(Y__ - (-0.395 * U) + (-0.581 * V)));
				b = std::min(255, int(Y__ + (2.032 * U)));

				image.setPixel(x, height - 1 - y, qRgb(r, b, g));
			}
		}

		// Draw image.
		painter.drawImage(QPoint(0, 0), image);
		qDebug() << "Done: 1.5x Brightness";
		break;

	case 5:
		qDebug() << "Painting: Greyscale (Luminance Only)";

		// Set pixels.
		for (x = 0; x < width; x++) {
			for (y = 0; y < height; y++) {
				// Go through pixel by pixel.
				// For each triplet of bytes, get the 0-255 RGB value.
				r = HextoInt(pixels.substr(((height*y) + x) * 6 + 4, 2));
				b = HextoInt(pixels.substr(((height*y) + x) * 6 + 2, 2));
				g = HextoInt(pixels.substr(((height*y) + x) * 6, 2));

				// Convert RGB to YCoCg (we will only need the Y/luminance for greyscale).
				Y_ = (b + (r - g) / 2) + (g - (b + (r - g) / 2)) / 2;

				// Set RGB to the luminance value.
				r = Y_;
				b = Y_;
				g = Y_;

				image.setPixel(x, height - 1 - y, qRgb(r, b, g));
			}
		}

		// Draw image.
		painter.drawImage(QPoint(0, 0), image);
		qDebug() << "Done: Greyscale (Luminance Only)";
		break;

	case 6:
		qDebug() << "Painting: Dither (2x2)";

		// Set pixels.
		for (x = 0; x < width*2; x++) {
			for (y = 0; y < height*2; y++) {
				i = floor(x / 2);
				j = floor(y / 2);

				// Go through pixel by pixel.
				// For each triplet of bytes, get the 0-255 RGB value.
				r = HextoInt(pixels.substr(((height*j) + i) * 6 + 4, 2));
				b = HextoInt(pixels.substr(((height*j) + i) * 6 + 2, 2));
				g = HextoInt(pixels.substr(((height*j) + i) * 6, 2));

				// Convert RGB to YCoCg (we will only need the Y/luminance for greyscale).
				Y_ = (b + (r - g) / 2) + (g - (b + (r - g) / 2)) / 2;

				// Pick which entry in the dither matrix to compare.
				if (x % 2 == 0) {
					m = 0;
				}
				else {
					m = 1;
				}

				if (y % 2 == 0) {
					n = 0;
				}
				else {
					n = 1;
				}

				// "Enable" the pixel if it meets the range.
				if (Y_ > D[m][n]) {
					Y_ = 255;
				} else {
					Y_ = 0;
				}


				// Set RGB to the luminance value.
				r = Y_;
				b = Y_;
				g = Y_;

				largeimage.setPixel(x, height*2 - 1 - y, qRgb(r, b, g));
			}
		}

		// Draw image.
		painter.drawImage(QPoint(0, 0), largeimage);
		qDebug() << "Done: Dither (2x2)";
		break;

	default:
		break;
		
	}
	
}

int WidgetCanvas::HextoInt(std::string hex) {
	return std::stoi(hex, nullptr, 16);
}
