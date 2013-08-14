/*
 * =====================================================================================
 * 
 *       Filename:  mainwindow.h
 * 
 *    Description:  The main window definition for CTMessenger
 * 
 *         Author:  Cybertinus
 *
 *        Licence:  BSD, see LICENCE for more info
 * 
 * =====================================================================================
 */

#include <QtGui>

class mainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    mainWindow();

public slots:
	void quit();
	void showAboutQt();
};   
