#ifndef STAMPSELECTOR_H
#define STAMPSELECTOR_H

#include <QDialog>

namespace Ui {
class StampSelector;
}

class StampSelector : public QDialog
{
    Q_OBJECT

public:
    explicit StampSelector(QWidget *parent = 0);
    ~StampSelector();

private:
    Ui::StampSelector *ui;
    int whichStampSelected;

protected:
    void closeEvent(QCloseEvent*);
    bool eventFilter(QObject *watched, QEvent *event);

signals:
    void selectedStamp(int id);
private slots:
    //void on_selectButton_clicked();
    void resolution(QRect geometry);
};

#endif // STAMPSELECTOR_H
