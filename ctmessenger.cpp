/*
 * =====================================================================================
 *
 *       Filename:  ctmessenger.cpp
 *
 *    Description:  The main class for CTMessenger
 *
 *         Author:  Cybertinus
 *
 *        Licence:  BSD, see LICENCE for more info
 *
 * =====================================================================================
 */

#include "ctmessenger.h"

CTMessenger::CTMessenger(QWidget *parent)
	: QWidget(parent)
{
	QLabel *fromLabel = new QLabel(tr("From:"));
	fromText = new QLineEdit();
	fromText->setMinimumWidth(100);
	fromText->setReadOnly(true);

	QLabel *messageLabel = new QLabel(tr("Message:"));
	messageText = new QTextEdit();
	messageText->setMinimumWidth(100);
	messageText->setMinimumHeight(200);
	messageText->setReadOnly(true);

	QGridLayout *mainLayout = new QGridLayout;
	mainLayout->addWidget(fromLabel, 0, 0);
	mainLayout->addWidget(fromText, 0, 1);
	mainLayout->addWidget(messageLabel, 1, 0, Qt::AlignTop);
	mainLayout->addWidget(messageText, 1, 1);

	setLayout(mainLayout);
	setWindowTitle("CTMessenger");

	// Start the TCP Server, to recieve new messages
	tcpServer = new QTcpServer(this);
	if(!tcpServer->listen(QHostAddress::Any, 1337))
	{
		QMessageBox::critical(this, tr("CTMessenger"),
		                      tr("Unable to start the server: %1.")
							  .arg(tcpServer->errorString()));
		close();
		exit(1);
	}
	connect(tcpServer, SIGNAL(newConnection()), this, SLOT(recieveConnection()));

	// Set up the UDP socket, to recieve maintenance broadcasts
	broadcastListener = new QUdpSocket(this);
	broadcastListener->bind(1337, QUdpSocket::ShareAddress);
	connect(broadcastListener, SIGNAL(readyRead()), this, SLOT(recieveBroadcast()));

	// Set up the UDP socket for sending maintenance broadcasts
	broadcastSender = new QUdpSocket(this);

	// Send the maintenance broadcasts every minute
	broadcastTimer = new QTimer(this);
	connect(broadcastTimer, SIGNAL(timeout()), this, SLOT(sendBroadcast()));
	broadcastTimer->start(60000);
	sendBroadcast();

	this->localpcs = QList<pc *> ();
}

void CTMessenger::newMessage()
{
	newMessageWindow = new NewMessage();
	newMessageWindow->show();
	newMessageWindow->exec();
}

void CTMessenger::recieveConnection()
{
	clientConnection = tcpServer->nextPendingConnection();
	connect(clientConnection, SIGNAL(disconnected()), clientConnection, SLOT(deleteLater()));
	connect(clientConnection, SIGNAL(readyRead()), this, SLOT(recieveMessage()));
}

void CTMessenger::recieveMessage()
{
	QString incomingMessage = "";
	while(clientConnection->canReadLine())
	{
		incomingMessage.append(clientConnection->readLine());
	}

	fromText->setText(clientConnection->peerAddress().toString());
	messageText->setText(incomingMessage);

	clientConnection->close();
}

void CTMessenger::recieveBroadcast()
{
	while(broadcastListener->hasPendingDatagrams())
	{
		QByteArray datagram;
		QHostAddress sourceAddress;
		datagram.resize(broadcastListener->pendingDatagramSize());
		broadcastListener->readDatagram(datagram.data(), datagram.size(), &sourceAddress);
		QString broadcastdata = datagram.data();
		QStringList dataparts = broadcastdata.split(',');
		bool foundpc = false;
		for(int i = 0; i < localpcs.size(); ++i)
		{
			if(localpcs.at(i)->name == dataparts.at(1))
			{
				foundpc = true;
				if(dataparts.at(0) == "DOWN")
				{
					localpcs.removeAt(i);
				}
				else if(dataparts.at(0) == "UP")
				{
					localpcs.at(i)->lastseen = QDateTime::currentDateTime();
				}
			}
		}

		if(foundpc == false && dataparts.at(0) == "UP")
		{
			pc newpc;
			newpc.name = dataparts.at(1);
			newpc.lastseen = QDateTime::currentDateTime();
			newpc.ipaddr = sourceAddress.toString();
			localpcs.append(&newpc);
		}
	}
}

void CTMessenger::sendBroadcast()
{
	QByteArray datagram = "UP,cybertinus";
	broadcastSender->writeDatagram(datagram.data(), datagram.size(), QHostAddress::Broadcast, 1337);
}
