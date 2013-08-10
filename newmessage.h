/*
 * =====================================================================================
 * 
 *       Filename:  newmessage.h
 * 
 *    Description:  A class for sending a new message
 * 
 *         Author:  Cybertinus
 *
 *        Licence:  BSD
 * 
 * =====================================================================================
 */

#include <QtGui>

class NewMessage : public QDialog
{
	Q_OBJECT

public:
	NewMessage(QWidget *parent = 0);

public slots:
	void send();
	void cancel();

private:
	QLineEdit *toLineEdit;
	QTextEdit *messageTextEdit;

	QPushButton *sendButton;
	QPushButton *cancelButton;
};
