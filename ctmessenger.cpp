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
	QLabel *fromText = new QLabel("");
	fromText->setMinimumWidth(50);

	QLabel *messageLabel = new QLabel(tr("Message:"));
	QLabel *messageText = new QLabel("");
	messageText->setMinimumWidth(50);
	messageText->setMinimumHeight(100);

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
}

void CTMessenger::newMessage()
{
	newMessageWindow = new NewMessage();
	newMessageWindow->show();
	newMessageWindow->exec();
}
