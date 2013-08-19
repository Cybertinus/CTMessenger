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
#include <QtNetwork>
#include <QUdpSocket>
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
	void recieveBroadcast();
	void sendBroadcast();

private:
	struct pc {
		QString name;
		QDateTime lastseen;
		QString ipaddr;
	};
	
	QList<pc *> localpcs;
	QLineEdit *fromText;
	QTextEdit *messageText;
	NewMessage *newMessageWindow;
	QTcpServer *tcpServer;
	QTcpSocket *clientConnection;
	QUdpSocket *broadcastListener;
	QUdpSocket *broadcastSender;
	QTimer *broadcastTimer;
};
