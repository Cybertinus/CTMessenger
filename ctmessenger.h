/*
 * =====================================================================================
 * 
 *       Filename:  ctmessenger.h
 * 
 *    Description:  The main class for CTMessenger
 * 
 *         Author:  Cybertinus
 *
 *        Licence:  BSD
 * 
 * =====================================================================================
 */

#include <QtGui>
#include "newmessage.h"

class CTMessenger : public QWidget
{
	Q_OBJECT

public:
	CTMessenger(QWidget *parent = 0);

public slots:
	void newMessage();

private:
	QPushButton *newMessageButton;
	NewMessage *newMessageWindow;
};
