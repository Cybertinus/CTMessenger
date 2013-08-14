/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  The main file for the CTMessenger
 *
 *         Author:  Cybertinus
 *
 *        Licence:  BSD, see LICENCE for more info
 *
 * =====================================================================================
 */

#include "mainwindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	mainWindow mainwindow;
	mainwindow.show();

	return app.exec();
}
