    #include <QtWidgets>
     
    int main(int argc, char *argv[]) {
     
        QApplication app(argc, argv);

        QSpinBox *spinBox = new QSpinBox();
        spinBox->setRange(0,150); 

        QSlider *sliderH = new QSlider(Qt::Horizontal);
        sliderH->setRange(0,150);
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), sliderH, SLOT(setValue(int)));
        QObject::connect(sliderH , SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));

        QSlider *sliderV = new QSlider(Qt::Vertical);
        sliderV->setRange(0,150);
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), sliderV, SLOT(setValue(int)));
        QObject::connect(sliderV , SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));

        QPushButton *Button1 = new QPushButton("Close");
        QObject::connect(Button1, SIGNAL(clicked()), &app, SLOT(quit()));
        Button1->show();

        spinBox->setValue(50);

        QHBoxLayout *layout = new QHBoxLayout{};
        layout->addWidget(spinBox);
        layout->addWidget(sliderH);
        layout->addWidget(sliderV);
        layout->addWidget(Button1);

        QWidget *window = new QWidget();
        window->setWindowTitle("Programm1");
        window->setLayout(layout);
        window->show();

        return app.exec();
    }