/*
 * =====================================================================================
 *
 *       Filename:  mainwindow.cpp
 *
 *    Description:  The main window definition for CTMessenger
 *
 *         Author:  Cybertinus
 *
 *        Licence:  BSD, see LICENCE for more info
 *
 * =====================================================================================
 */

#include "mainwindow.h"
#include "ctmessenger.h"

mainWindow::mainWindow()
{
    CTMessenger *ctmessenger = new CTMessenger();
	setCentralWidget(ctmessenger);

	QAction *newMessageAction = new QAction(QIcon("envelope.ico"), tr("&New message"), this);
	QAction *exitAction = new QAction(tr("E&xit"), this);

	connect(newMessageAction, SIGNAL(triggered()), ctmessenger, SLOT(newMessage()));
	connect(exitAction, SIGNAL(triggered()), this, SLOT(quit()));

	QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(newMessageAction);
	fileMenu->addSeparator();
	fileMenu->addAction(exitAction);

	QAction *aboutQtAction = new QAction(tr("About &Qt"), this);
	
	connect(aboutQtAction, SIGNAL(triggered()), this, SLOT(showAboutQt()));

	QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
	helpMenu->addAction(aboutQtAction);

	QToolBar *tb = new QToolBar(tr("Tool Bar"), this);
	tb->addAction(newMessageAction);
	addToolBar(tb);
}

void mainWindow::quit()
{
	qApp->quit();
}

void mainWindow::showAboutQt()
{
	QMessageBox::aboutQt(this, tr("About Qt"));
}
