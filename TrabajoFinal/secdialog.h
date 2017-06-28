#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>
#include <QListView>
#include <QMap>
#include <string>

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecDialog(QWidget *parent = 0);
    ~SecDialog();

    void Editmap(QStringList valo, int resul[32]);

private:
    Ui::SecDialog *ui;
};

#endif // SECDIALOG_H
