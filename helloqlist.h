#ifndef HELLOQLIST_H
#define HELLOQLIST_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include <QTreeWidget>

namespace Ui {
class helloqlist;
}

class helloqlist : public QDialog
{
    Q_OBJECT

    void AddRoot(QString name, QString Description);
    void AddChild(QTreeWidgetItem *parent, QString name, QString Description);

public:
    explicit helloqlist(QWidget *parent = 0);
    ~helloqlist();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::helloqlist *ui;
};

#endif // HELLOQLIST_H
