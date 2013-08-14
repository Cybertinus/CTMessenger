/*
 * =====================================================================================
 * 
 *       Filename:  ctmessenger.h
 * 
 *    Description:  The main class for CTMessenger
 * 
 *         Author:  Cybertinus
 *
 *        Licence:  BSD, see LICENCE for more info
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
	QLineEdit *fromText;
	QTextEdit *messageText;
	NewMessage *newMessageWindow;
	QTcpServer *tcpServer;
	QTcpSocket *clientConnection;
	int blocksize;
};
