/*
 * =====================================================================================
 * 
 *       Filename:  newmessage.h
 * 
 *    Description:  A class for sending a new message
 * 
 *         Author:  Cybertinus
 *
 *        Licence:  BSD, see LICENCE for more info
 * 
 * =====================================================================================
 */

#include <QtGui>
#include <QtNetwork>
#include <QTcpSocket>

class NewMessage : public QDialog
{
	Q_OBJECT

public:
	NewMessage(QWidget *parent = 0);

public slots:
	void send();
	void cancel();
	void sendMessage();

private:
	QLineEdit *toLineEdit;
	QTextEdit *messageTextEdit;

	QPushButton *sendButton;
	QPushButton *cancelButton;
	QTcpSocket client;
};
