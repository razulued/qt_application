#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "screens/generic_window.h"



MainMenu::MainMenu(socket_client *socket, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    this->socket = socket;
    rutinas = new rutinas_mantenimiento(tr("rutinas.db"));

    this->setObjectName("PtarMain");
    this->setStyleSheet("#PtarMain{background-color: black;"
                        "border: none;}");
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowCloseButtonHint);

    this->show();
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_launch_view1_clicked()
{
    main_view_init();
}

void MainMenu::on_launch_view2_clicked()
{
    filtro_view_init();
}


void MainMenu::on_launch_view3_clicked()
{
    graph_demo_init();
}

void MainMenu::on_launch_view4_clicked()
{

}

void MainMenu::detailed_closed()
{
    mutex_detailed.unlock();
}

void MainMenu::create_detailed_window(int element)
{
    qDebug() << "Create detailed win";
    if(mutex_detailed.tryLock(0))
    {
        if (detail_window != NULL) {
            delete detail_window;
        }
        detail_window = new detailedwindow((detailed_elements_t)element, rutinas, this);
        connect(detail_window, SIGNAL(release_lock()), this, SLOT(detailed_closed()));
        detail_window->show();
    }
}

/** CREATE A NEW FUNCTION LIKE THIS FOR EACH NEW WINDOW **/

void MainMenu::main_view_init()
{
    //Create screens
    generic_window *win = new generic_window("MainView",this);

    win->add_image(":/gifs/1 Carcamo y Regulador/screen800x600/gifs/1 Carcamo y Regulador/regul hi quiet water 03.png",
                   QSize(180,180), QPoint(20,210), false);
    win->add_image(":/gifs/1 Carcamo y Regulador/screen800x600/gifs/1 Carcamo y Regulador/regul hi quiet water 03.png",
                   QSize(180,180), QPoint(149,177), false);
    win->add_image(":/gifs/2 Reactor/screen800x600/gifs/2 Reactor/reac hi quiet water 03.png",
                   QSize(180,180), QPoint(300,140), false);
    win->add_image(":/gifs/3 Clarificador/screen800x600/gifs/3 Clarificador/clarifier vacio.png",
                   QSize(180,180), QPoint(440,108), false);
    win->add_image(":/gifs/4 Clorador/screen800x600/gifs/4 Clorador/chlorination quiet.png",
                   QSize(180,180), QPoint(570,80), false);
    win->add_image(":/gifs/5 Digestor/screen800x600/gifs/5 Digestor/digester empty.png",
                   QSize(180,180), QPoint(599,217), false);
    win->add_image(":/gifs/6 Lechos/screen800x600/gifs/6 Lechos/sand bed 03.png",
                   QSize(151,101), QPoint(383,381), false);

    QSignalMapper *detailed_view_Mapper = new QSignalMapper(this);

    QPushButton *carcamo_module = win->add_clickeable_module(QSize(111,91), QPoint(60,260), "carcamo", "blue");
    connect(carcamo_module, SIGNAL(clicked(bool)), detailed_view_Mapper, SLOT(map()));
    detailed_view_Mapper->setMapping(carcamo_module, ELEMENT_CARCAMO);

    QPushButton *regulador_module = win->add_clickeable_module(QSize(111,91), QPoint(190,230), "regulador", "green");
    connect(regulador_module, SIGNAL(clicked(bool)), detailed_view_Mapper, SLOT(map()));
    detailed_view_Mapper->setMapping(regulador_module, ELEMENT_REGULADOR);

    QPushButton *reactor_module = win->add_clickeable_module(QSize(111,91), QPoint(330,190), "reactor", "green");
    connect(reactor_module, SIGNAL(clicked(bool)), detailed_view_Mapper, SLOT(map()));
    detailed_view_Mapper->setMapping(reactor_module, ELEMENT_REACTOR);

    QPushButton *clarificador_module = win->add_clickeable_module(QSize(111,91), QPoint(475,152), "clarificador", "white");
    connect(clarificador_module, SIGNAL(clicked(bool)), detailed_view_Mapper, SLOT(map()));
    detailed_view_Mapper->setMapping(clarificador_module, ELEMENT_CLARIFICADOR);

    QPushButton *clorador_module = win->add_clickeable_module(QSize(111,91), QPoint(610,120), "clorador", "white");
    connect(clorador_module, SIGNAL(clicked(bool)), detailed_view_Mapper, SLOT(map()));
    detailed_view_Mapper->setMapping(clorador_module, ELEMENT_CLORADOR);

    QPushButton *digestor_module = win->add_clickeable_module(QSize(111,91), QPoint(649,267), "digestor", "white");
    connect(digestor_module, SIGNAL(clicked(bool)), detailed_view_Mapper, SLOT(map()));
    detailed_view_Mapper->setMapping(digestor_module, ELEMENT_DIGESTOR);

    QPushButton *deshidratador_module = win->add_clickeable_module(QSize(111,91), QPoint(390,380), "deshidratador", "white");
    connect(deshidratador_module, SIGNAL(clicked(bool)), detailed_view_Mapper, SLOT(map()));
    detailed_view_Mapper->setMapping(deshidratador_module, ELEMENT_DESHIDRATADOR);

    // Connect all buttons to mapper
    connect(detailed_view_Mapper, SIGNAL(mapped(int)), this, SLOT(create_detailed_window(int)));

    QList<configuration_id> parameter_list;
    parameter_list << configuration::conf_car_fisic << configuration::conf_car_elect;
    win->InitToolTips(parameter_list);

    // Connect socket for updates
    connect(socket, SIGNAL(new_data_comming()), win, SLOT(new_data_comming()));

    win->show();
    //this->hide();
}

void MainMenu::filtro_view_init()
{
    //Create screens
    generic_window *win = new generic_window("FiltroView",this);

    win->add_image(":/diagrama/screen800x600/diagrama/motor_filtro.png",
                   QSize(211,131), QPoint(80,310), false);
    win->add_image(":/diagrama/screen800x600/diagrama/Filtro 5SDF portátil_1.png",
                   QSize(321,411), QPoint(250,91), false);

    QSignalMapper *detailed_view_Mapper = new QSignalMapper(this);

    QPushButton *motor_module = win->add_clickeable_module(QSize(211,131), QPoint(80,310), "filtro bomba", "blue");
    connect(motor_module, SIGNAL(clicked(bool)), detailed_view_Mapper, SLOT(map()));
    detailed_view_Mapper->setMapping(motor_module, ELEMENT_FILTRO_BOMBA);

    QPushButton *filtro_module = win->add_clickeable_module(QSize(181,221), QPoint(310,190), "filtro", "green");
    connect(filtro_module, SIGNAL(clicked(bool)), detailed_view_Mapper, SLOT(map()));
    detailed_view_Mapper->setMapping(filtro_module, ELEMENT_FILTRO);


    // Connect all buttons to mapper
    connect(detailed_view_Mapper, SIGNAL(mapped(int)), this, SLOT(create_detailed_window(int)));

    QList<configuration_id> parameter_list;
    parameter_list << configuration::conf_car_fisic << configuration::conf_car_elect;
    win->InitToolTips(parameter_list);

    // Connect socket for updates
    connect(socket, SIGNAL(new_data_comming()), win, SLOT(new_data_comming()));

    win->show();
    //this->hide();
}

void MainMenu::graph_demo_init()
{
    //Create screens
    generic_window *win = new generic_window("Graph",this);

    win->add_graph();
    win->show();
    //this->hide();
}
