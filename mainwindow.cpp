/*
 * =====================================================================================
 *
 *       Filename:  mainwindow.cpp
 *
 *    Description:  The main window definition for CTMessenger
 *
 *         Author:  Cybertinus
 *
 *        Licence:  BSD
 *
 * =====================================================================================
 */

#include "mainwindow.h"
#include "ctmessenger.h"

mainWindow::mainWindow()
{
    CTMessenger *ctmessenger = new CTMessenger();
	setCentralWidget(ctmessenger);

	/*
	QWidget *widget = new QWidget
	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(ctmessenger);
	widget->setLayout(layout);
    setCentralWidget(widget);
	*/
}
