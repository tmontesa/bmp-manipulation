#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

// SLOTS

void MainWindow::GetFile() {
	// Open file picker to get file path.
	filename = QFileDialog::getOpenFileName(this, tr("Open File"),
		"/home",
		tr("Images (*.bmp)"));
	
	// Open file and stop if it does not exist.
	QFile file(filename);

	if (!file.exists()) {
		return;
	}

	file.open(QIODevice::ReadOnly);

	// Turn the raw binary of the file into a string of hex characters.
	QDataStream data(&file);   
	filestream = file.readAll();
	filestreamString = filestream.toHex();

	// Extract file information from the hex string and send it to the "info display" label.
	width = LittleHextoInt(filestream, 18 * 2, 4 * 2);
	height = LittleHextoInt(filestream, 22 * 2, 4 * 2);
	bitsperpixel = LittleHextoInt(filestream, 28 * 2, 2 * 2);
	dataoffset = LittleHextoInt(filestream, 10 * 2, 4 * 2);
	info = QString::number(width) + " x " + QString::number(height)
		+ " image (" + QString::number(bitsperpixel) + "-bit) ";


	pixelstream = filestream.mid(dataoffset);
	pixelstreamString = filestreamString.mid(dataoffset * 2);


	emit OpenFile(filename);
	emit PassInfo(info);
	emit StreamFile(filestreamString);
	// Send the "data" portion of the hex string to the canvas display widget.
	emit StreamPixels(pixelstreamString, width, height);
	file.close();
}


// HELPER FUNCTIONS
// Changing a little endian value to big endian.
// Takes a string of hex, and reverses the order of pairs of hex.
// ie. 0xaabbcc -> 0xccbbaa
std::string MainWindow::LittleEndiantoBigEndian(std::string little) {
	std::string big;
	for (int i = little.length() - 1; i > 0; i -= 2) {
		big.append(little.substr(i-1, 2));
	}
	return big;
}

// Converts a little endian hex string to int, then to string.
QString MainWindow::LittleHextoIntQString(QByteArray bytearray, int pos, int len) {
	// ByteArray -> Hex String -> Extract "Substring -> Hex String as Standard String -> Convert Little Endian to Big Endian --> Convert Big Endian Hex to Int -> Convert to QString
	return QString::number(std::stoi(LittleEndiantoBigEndian(filestreamString.mid(pos, len).toStdString()), nullptr, 16));
}

// Converts a little endian hex string to int.
int MainWindow::LittleHextoInt(QByteArray bytearray, int pos, int len) {
	// ByteArray -> Hex String -> Extract "Substring -> Hex String as Standard String -> Convert Little Endian to Big Endian --> Convert Big Endian Hex to Int -> Convert to QString
	return std::stoi(LittleEndiantoBigEndian(filestreamString.mid(pos, len).toStdString()), nullptr, 16);
}

