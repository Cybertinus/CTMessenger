/*
 * =====================================================================================
 *
 *       Filename:  newmessage.cpp
 *
 *    Description:  A class for sending a new message
 *
 *         Author:  Cybertinus
 *
 *        Licence:  BSD
 * =====================================================================================
 */

#include "newmessage.h"

NewMessage::NewMessage(QWidget *parent)
	: QDialog(parent)
{
	QLabel *toLabel = new QLabel(tr("To:"));
	toLineEdit = new QLineEdit;

	QLabel *messageLabel = new QLabel(tr("Message:"));
	messageTextEdit = new QTextEdit;

	sendButton = new QPushButton(tr("Send"));
	cancelButton = new QPushButton(tr("Cancel"));
	connect(sendButton, SIGNAL(clicked()), this, SLOT(send()));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));

	QGridLayout *messageLayout = new QGridLayout;
	messageLayout->addWidget(toLabel, 0, 0);
	messageLayout->addWidget(toLineEdit, 0, 1);
	messageLayout->addWidget(messageLabel, 1, 0, Qt::AlignTop);
	messageLayout->addWidget(messageTextEdit, 1, 1);

	QHBoxLayout *buttonLayout = new QHBoxLayout;
	buttonLayout->addWidget(sendButton);
	buttonLayout->addWidget(cancelButton);

	QVBoxLayout *outerLayout = new QVBoxLayout;
	outerLayout->addLayout(messageLayout);
	outerLayout->addLayout(buttonLayout);

	setLayout(outerLayout);
	setWindowTitle(tr("New Message"));
}

void NewMessage::send()
{
	accept();
}

void NewMessage::cancel()
{
	reject();
}
