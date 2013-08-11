/*
 * =====================================================================================
 *
 *       Filename:  ctmessenger.cpp
 *
 *    Description:  The main class for CTMessenger
 *
 *         Author:  Cybertinus
 *
 *        Licence:  BSD
 *
 * =====================================================================================
 */

#include "ctmessenger.h"

CTMessenger::CTMessenger(QWidget *parent)
	: QWidget(parent)
{
	QLabel *fromLabel = new QLabel(tr("From:"));
	fromText = new QLabel("");
	fromText->setMinimumWidth(100);

	QLabel *messageLabel = new QLabel(tr("Message:"));
	messageText = new QLabel("");
	messageText->setMinimumWidth(100);
	messageText->setMinimumHeight(200);

	newMessageButton = new QPushButton(tr("New message"));
	connect(newMessageButton, SIGNAL(clicked()), this, SLOT(newMessage()));

	QGridLayout *mainLayout = new QGridLayout;
	mainLayout->addWidget(fromLabel, 0, 0);
	mainLayout->addWidget(fromText, 0, 1);
	mainLayout->addWidget(newMessageButton, 0, 2);
	mainLayout->addWidget(messageLabel, 1, 0, Qt::AlignTop);
	mainLayout->addWidget(messageText, 1, 1);

	setLayout(mainLayout);
	setWindowTitle("CTMessenger");

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
	blocksize = 0;
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
