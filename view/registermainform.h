#ifndef REGISTERMAINFORM_H
#define REGISTERMAINFORM_H

#include <QMainWindow>

namespace Ui {
class RegisterMainForm;
}

class RegisterMainForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegisterMainForm(QWidget *parent = nullptr);
    ~RegisterMainForm();

private:
    void registerTableInitiate();
    Ui::RegisterMainForm *ui;
};

#endif // REGISTERMAINFORM_H
