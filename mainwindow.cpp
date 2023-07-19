#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Params_of_task = load_params_of_task(Params_of_task);

    scene1 = new custom_paintscene(&tip_postroyeniya, &Params_of_task[2]);
    scene1->setSceneRect(0,0,window_width,window_height); // Устанавливаем размер сцены
    ui->graphicsView->setScene(scene1);
    ui->graphicsView->viewport()->installEventFilter(this);
    ui->graphicsView->setAlignment(Qt::AlignTop|Qt::AlignLeft); // выравнивание координат сцены по левому верхнему углу ([0, 0] в верхнем левом углу)
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->graphicsView->setMouseTracking(true); // включает непрерывное отслеживание мыши внутри граф.вида (выполнение mouseMoveEvent внутри переопределённого класса сцены)

    okno_parametrov_GA = new Form_vvod_param_GA(Params_GA);
    connect(okno_parametrov_GA, &Form_vvod_param_GA::peredat_parametry_GA, this, &MainWindow::slot_priyoma_Param_GA);

    okno_parametrov_zadachi = new form_of_task_parameters(Params_of_task);
    connect(okno_parametrov_zadachi, &form_of_task_parameters::transmit_param_of_task, this, &MainWindow::slot_priyoma_Param_of_task);
}

MainWindow::~MainWindow()
{
    delete ui;
}


// Фильтр, перехватывающий событие изменения размеров (любой управляющей командой откуда угодно) - заменяет стандартный ресайз
bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    if(event->type() == QEvent::Resize )
    {
        QRectF bounds = scene1->sceneRect();
        QRectF bounds2 = {bounds.x(), bounds.y(), bounds.width()-4, bounds.height()-4};
        //QRectF bounds = {QPointF(-500,-500), QPointF(300,300)};
        ui->graphicsView->fitInView(bounds2, Qt::IgnoreAspectRatio);
        return true;
    }
    return false;
}


void MainWindow::on_action_exit_triggered()
{
    MainWindow::close();
}


void MainWindow::on_action_full_small_screen_triggered()
{
    if (!polnoekran) this->showFullScreen();
    else this->showNormal();
    polnoekran = !polnoekran;
    //update();
}


void MainWindow::on_action_start_GA_triggered()
{
    scene1->delete_solution();

    Params_GA = zagruzit_params(Params_GA);

    //int kol_PPPM = 3;

unsigned long TIC = clock();

    QVector<double> nabor_PPPM = GenAlg(Params_GA, scene1->nabor_ZZP, scene1->zona_puska, scene1->sektor_zapuska, Params_of_task);

double TOC = (clock() - TIC)/1000.0;

    scene1->draw_solution(nabor_PPPM, {0, 140, 240});

    qDebug() << "Время: " << TOC;

    qDebug() << nabor_PPPM;
//}
}


void MainWindow::on_action_change_params_GA_triggered()
{
    Params_GA = zagruzit_params(Params_GA);
    //qDebug() << QString::number(Params_GA[0]);
    okno_parametrov_GA->obnovit_params(Params_GA);
    okno_parametrov_GA->show();
}


void MainWindow::slot_priyoma_Param_GA(QVector<double> new_param_GA)
{
    Params_GA = new_param_GA;
    sokhranit_params(Params_GA);
    //qDebug() << QString::number(Params_GA[0]);
    qDebug() << "Новые параметры ГА сохранены";
}


void MainWindow::on_action_change_task_parameters_triggered()
{
    Params_of_task = load_params_of_task(Params_of_task);
    //qDebug() << QString::number(Params_GA[0]);
    okno_parametrov_zadachi->update_params(Params_of_task);
    okno_parametrov_zadachi->show();
}


void MainWindow::slot_priyoma_Param_of_task(QVector<double> new_param_of_task)
{
    Params_of_task = new_param_of_task;
    save_params_of_task(Params_of_task);
    //qDebug() << QString::number(Params_GA[0]);
    qDebug() << "Новые параметры задачи сохранены";
}


void MainWindow::on_action_screenshot_triggered()
{
    QImage image(scene1->width()*4, scene1->height()*4, QImage::Format_RGB32);
    image.fill(0xffffff);
    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing);
    scene1->render(&painter);

    QString file_name = QFileDialog::getSaveFileName(nullptr, tr("Сохранение изображения сцены"),
                                QDir::currentPath(), tr("Файл png (*.png);;"));

    if (image.save(file_name)) {
        QMessageBox::about(this, "Готово", "Изображение сохранено");}
    else QMessageBox::about(this, "Ошибка", "Не удалось сохранить изображение");
}


void MainWindow::on_action_save_data_triggered()
{
    // Сохранение в файл
    QString file_name = QFileDialog::getSaveFileName(nullptr, tr("Сохранение файла данных"),
                                QDir::currentPath(), tr("Файл PoDa (*.PoDa);;"));
    if (sokhranit_dannye(file_name, scene1->nabor_ZZP, scene1->zona_puska, scene1->sektor_zapuska)) {
        QMessageBox::about(this, "Готово", "Сохранение входных данных успешно завершено");}
    else QMessageBox::about(this, "Ошибка", "Не удалось сохранить данные");
}


void MainWindow::on_action_load_data_triggered()
{
    // загрузка из файла
    QString file_name = QFileDialog::getOpenFileName(nullptr, QObject::tr("Укажите файл начальных данных"),
                   QDir::currentPath(), QObject::tr("Файл PoDa (*.PoDa);;Все файлы (*.*)"));
    struct_dannykh data = zagr_dannye(file_name);
    if (data.flag_korrektnosti == true) {
        scene1->add_data_from_file(data);
        QMessageBox::about(this, "Готово", "Загрузка входных данных успешно завершена");
    }
    else QMessageBox::about(this, "Ошибка", "Данные не загружены");
}


void MainWindow::on_action_B_zzp_triggered()
{
    tip_postroyeniya = 1;
}


void MainWindow::on_action_B_rzp_triggered()
{
    tip_postroyeniya = 2;
}


void MainWindow::on_action_B_sp_triggered()
{
    tip_postroyeniya = 3;
}

