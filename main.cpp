/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  The main file for the CTMessenger
 *
 *         Author:  Cybertinus
 *
 *        Licence:  BSD
 *
 * =====================================================================================
 */

#include "ctmessenger.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	CTMessenger ctmessenger;
	ctmessenger.show();

	return app.exec();
}
