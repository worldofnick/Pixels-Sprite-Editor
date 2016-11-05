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
    void okClicked(int width, int backColor);
private slots:
    void on_widthInputBox_textChanged(const QString &arg1);
};

#endif // GETRESOLUTIONDIALOG_H
