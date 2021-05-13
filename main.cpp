#include "DicomViewerDemo.h"
#include <QtWidgets/QApplication>
#include "QtWidgets/qmainwindow.h"
#include <QDesktopWidget>
#include <QApplication>

#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2);

VTK_MODULE_INIT(vtkRenderingFreeType);

VTK_MODULE_INIT(vtkInteractionStyle);

#include <vtkOutputWindow.h>
using namespace std;

#pragma execution_character_set("utf-8")//显示中文

int main(int argc, char* argv[])
{
	vtkOutputWindow::SetGlobalWarningDisplay(0); //不弹出vtkOutputWindow窗口
	QApplication a(argc, argv);
	DicomViewerDemo w;
	QDesktopWidget* deskdop = QApplication::desktop();
	w.move( w.width() / 5, (w.height() / 2 + w.height()) );
	w.show();

	return a.exec();
}
