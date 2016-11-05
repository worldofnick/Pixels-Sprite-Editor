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

protected:
    void closeEvent(QCloseEvent*);

signals:
    void selectedStamp(int id);
private slots:
    void on_pushButton_clicked();
};

#endif // STAMPSELECTOR_H
