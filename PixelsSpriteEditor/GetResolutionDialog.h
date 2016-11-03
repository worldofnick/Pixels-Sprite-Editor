#ifndef GETRESOLUTIONDIALOG_H
#define GETRESOLUTIONDIALOG_H

#include <QDialog>
#include <QButtonGroup>

namespace Ui {
class GetResolutionDialog;
}

class GetResolutionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GetResolutionDialog(QWidget *parent = 0);
    ~GetResolutionDialog();

private:
    Ui::GetResolutionDialog *ui;
    QButtonGroup* resButtonsGroup;

protected:
    void closeEvent(QCloseEvent*);

public slots:
    void resolution();

signals:
    void okClicked(int width, int height, int backColor);
};

#endif // GETRESOLUTIONDIALOG_H
