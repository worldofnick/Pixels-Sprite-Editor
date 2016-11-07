#include "Preview.h"
#include "ui_Preview.h"

// Constructs a preview window object. It contains the live animation preview
// running at user selected FPS.
Preview::Preview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Preview)
{
    ui->setupUi(this);
    ui->previewLabel->setScaledContents(false);
    this->resize(this->width(), this->heightForWidth(this->width()));
}

// Destructor
Preview::~Preview()
{
    delete ui;
}

// Set the drawing to the preview window's placeholder (a QLabel)
void Preview::setPixmap(const QPixmap &map)
{
    ui->previewLabel->setPixmap(map.copy());
}

// Slot that executes when scale to window button is clicked.
// Contains the scaling to perform when the scale to window button is clicked.
void Preview::on_zoomInButton_clicked()
{
    ui->previewLabel->setScaledContents(true);
    ui->previewLabel->setPixmap(ui->previewLabel->pixmap()->copy());
}

// Slot that executes when 1:1 button is clicked.
// Resets the preview to 1:1 aspect ratio (original size).
void Preview::on_zoomOutButton_clicked()
{
    ui->previewLabel->setScaledContents(false);
    ui->previewLabel->setPixmap(ui->previewLabel->pixmap()->copy());
}

// Slot that executes when close button is clicked.
// Closes this window and set scaling to true
void Preview::on_closeButton_clicked()
{
    ui->previewLabel->setScaledContents(true);
    this->close();
}

// Sets the FPS of the animation to the user selected value.
void Preview::setFps(int fps)
{
    ui->fpsSliderPreview->setValue(fps);
}

// This is a slot called when the user triggers a GUI slider action.
// It emits a signal with the value of the slider.
void Preview::on_fpsSliderPreview_valueChanged(int value)
{
    emit fpsChanged(value);
}
