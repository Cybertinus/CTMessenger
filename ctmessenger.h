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
	void recieveConnection();
	void recieveMessage();

private:
	QLabel *fromText;
	QLabel *messageText;
	QPushButton *newMessageButton;
	NewMessage *newMessageWindow;
	QTcpServer *tcpServer;
	QTcpSocket *clientConnection;
	int blocksize;
};
