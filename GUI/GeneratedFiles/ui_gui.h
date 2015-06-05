/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabDirectory;
    QWidget *tabQuickPlay;
    QFrame *frmQuickPlay;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *hBoxQuickPlay;
    QPushButton *pBtnPlayPause;
    QSlider *volSlider;
    QLabel *lblVolume;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pBtnPrev;
    QPushButton *pBtnNext;
    QSlider *timeSlider;
    QLabel *label_2;
    QLabel *label_3;
    QFrame *frmPlaylist;
    QLabel *lblPlayList;
    QTableWidget *currentListTable;
    QPushButton *btnMonterCurrentList;
    QPushButton *btnDescendreCurrentList;
    QPushButton *btnRetirerCurrentList;
    QPushButton *btnViderCurrent;
    QPushButton *pbtnPutNext;
    QPushButton *pbtnShuffle;
    QFrame *frmSFML;
    QWidget *tab_3;
    QPushButton *btnSupprimerChansonBiblio;
    QPushButton *btnAjouterChansonBiblio;
    QTableWidget *directoryTable;
    QPushButton *btnAjouterCurrentBiblio;
    QWidget *tabCollections;
    QTabWidget *tabCollectionList;
    QWidget *tab_2;
    QTableWidget *affichageCollectionTable;
    QTableWidget *collectionTable;
    QPushButton *btnSupprimerCollection;
    QPushButton *btnAjouterCollection;
    QPushButton *btnJouerCollection;
    QWidget *tab;
    QTableWidget *createCollectionTable;
    QGroupBox *groupBox;
    QPushButton *btnSupprimerChansonCollection;
    QPushButton *btnAjouterChansonCollection;
    QGroupBox *groupBox_2;
    QLineEdit *txtName;
    QPushButton *btnSauvegarderCollection;
    QLabel *lblNom;
    QWidget *tabModificator;
    QTabWidget *tabModif;
    QWidget *tabVizualizer;
    QFrame *frmSFMLVisualizer;
    QGroupBox *gBoxVisualizer;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *lblSampleSize;
    QComboBox *cboxSample;
    QSpacerItem *verticalSpacer;
    QLabel *lblSoundBar;
    QPushButton *pbtnSoundBars;
    QSpacerItem *verticalSpacer_2;
    QLabel *lblJumpers;
    QPushButton *pbtnJumpers;
    QSpacerItem *verticalSpacer_3;
    QLabel *lblBackGround;
    QPushButton *pbtnBackground;
    QWidget *tabKeyboard;
    QLabel *label_4;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *hboxKeyboard;
    QWidget *tabEqualizer;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_3;
    QSlider *vSlider_Volume;
    QSlider *vSlider_Speed;
    QSlider *vSlider_Distortion;
    QSlider *vSlider_Flange;
    QSlider *vSlider_Echo;
    QSlider *vSlider_Tremolo;
    QSlider *vSlider_Pitch;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pBtnReset;
    QLabel *label_9;
    QLabel *label_10;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mainWindow)
    {
        if (mainWindow->objectName().isEmpty())
            mainWindow->setObjectName(QStringLiteral("mainWindow"));
        mainWindow->resize(1256, 624);
        mainWindow->setMinimumSize(QSize(1256, 624));
        mainWindow->setMaximumSize(QSize(1256, 624));
        centralWidget = new QWidget(mainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabDirectory = new QTabWidget(centralWidget);
        tabDirectory->setObjectName(QStringLiteral("tabDirectory"));
        tabDirectory->setMovable(true);
        tabQuickPlay = new QWidget();
        tabQuickPlay->setObjectName(QStringLiteral("tabQuickPlay"));
        frmQuickPlay = new QFrame(tabQuickPlay);
        frmQuickPlay->setObjectName(QStringLiteral("frmQuickPlay"));
        frmQuickPlay->setGeometry(QRect(0, 410, 761, 121));
        frmQuickPlay->setFrameShape(QFrame::StyledPanel);
        frmQuickPlay->setFrameShadow(QFrame::Raised);
        horizontalLayoutWidget = new QWidget(frmQuickPlay);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 20, 731, 31));
        hBoxQuickPlay = new QHBoxLayout(horizontalLayoutWidget);
        hBoxQuickPlay->setSpacing(50);
        hBoxQuickPlay->setContentsMargins(11, 11, 11, 11);
        hBoxQuickPlay->setObjectName(QStringLiteral("hBoxQuickPlay"));
        hBoxQuickPlay->setContentsMargins(0, 0, 0, 0);
        pBtnPlayPause = new QPushButton(horizontalLayoutWidget);
        pBtnPlayPause->setObjectName(QStringLiteral("pBtnPlayPause"));

        hBoxQuickPlay->addWidget(pBtnPlayPause);

        volSlider = new QSlider(horizontalLayoutWidget);
        volSlider->setObjectName(QStringLiteral("volSlider"));
        volSlider->setOrientation(Qt::Horizontal);

        hBoxQuickPlay->addWidget(volSlider);

        lblVolume = new QLabel(frmQuickPlay);
        lblVolume->setObjectName(QStringLiteral("lblVolume"));
        lblVolume->setGeometry(QRect(140, 10, 51, 16));
        horizontalLayoutWidget_3 = new QWidget(frmQuickPlay);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(20, 50, 731, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pBtnPrev = new QPushButton(horizontalLayoutWidget_3);
        pBtnPrev->setObjectName(QStringLiteral("pBtnPrev"));

        horizontalLayout_2->addWidget(pBtnPrev);

        pBtnNext = new QPushButton(horizontalLayoutWidget_3);
        pBtnNext->setObjectName(QStringLiteral("pBtnNext"));

        horizontalLayout_2->addWidget(pBtnNext);

        timeSlider = new QSlider(horizontalLayoutWidget_3);
        timeSlider->setObjectName(QStringLiteral("timeSlider"));
        timeSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(timeSlider);

        label_2 = new QLabel(frmQuickPlay);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(180, 70, 31, 29));
        label_3 = new QLabel(frmQuickPlay);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(730, 80, 41, 16));
        frmPlaylist = new QFrame(tabQuickPlay);
        frmPlaylist->setObjectName(QStringLiteral("frmPlaylist"));
        frmPlaylist->setGeometry(QRect(760, 10, 461, 511));
        frmPlaylist->setFrameShape(QFrame::StyledPanel);
        frmPlaylist->setFrameShadow(QFrame::Raised);
        lblPlayList = new QLabel(frmPlaylist);
        lblPlayList->setObjectName(QStringLiteral("lblPlayList"));
        lblPlayList->setGeometry(QRect(20, 0, 111, 16));
        currentListTable = new QTableWidget(frmPlaylist);
        if (currentListTable->columnCount() < 3)
            currentListTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        currentListTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        currentListTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        currentListTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        currentListTable->setObjectName(QStringLiteral("currentListTable"));
        currentListTable->setGeometry(QRect(20, 20, 431, 391));
        currentListTable->setAutoFillBackground(false);
        currentListTable->setFrameShape(QFrame::StyledPanel);
        currentListTable->setFrameShadow(QFrame::Sunken);
        currentListTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        currentListTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        currentListTable->setDragEnabled(true);
        currentListTable->setSelectionMode(QAbstractItemView::SingleSelection);
        currentListTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        currentListTable->setGridStyle(Qt::SolidLine);
        currentListTable->setSortingEnabled(false);
        btnMonterCurrentList = new QPushButton(frmPlaylist);
        btnMonterCurrentList->setObjectName(QStringLiteral("btnMonterCurrentList"));
        btnMonterCurrentList->setGeometry(QRect(30, 430, 93, 28));
        btnDescendreCurrentList = new QPushButton(frmPlaylist);
        btnDescendreCurrentList->setObjectName(QStringLiteral("btnDescendreCurrentList"));
        btnDescendreCurrentList->setGeometry(QRect(180, 430, 93, 28));
        btnRetirerCurrentList = new QPushButton(frmPlaylist);
        btnRetirerCurrentList->setObjectName(QStringLiteral("btnRetirerCurrentList"));
        btnRetirerCurrentList->setGeometry(QRect(30, 470, 93, 28));
        btnViderCurrent = new QPushButton(frmPlaylist);
        btnViderCurrent->setObjectName(QStringLiteral("btnViderCurrent"));
        btnViderCurrent->setGeometry(QRect(180, 470, 93, 28));
        pbtnPutNext = new QPushButton(frmPlaylist);
        pbtnPutNext->setObjectName(QStringLiteral("pbtnPutNext"));
        pbtnPutNext->setGeometry(QRect(340, 430, 111, 28));
        pbtnShuffle = new QPushButton(frmPlaylist);
        pbtnShuffle->setObjectName(QStringLiteral("pbtnShuffle"));
        pbtnShuffle->setGeometry(QRect(340, 470, 111, 28));
        frmSFML = new QFrame(tabQuickPlay);
        frmSFML->setObjectName(QStringLiteral("frmSFML"));
        frmSFML->setGeometry(QRect(10, 10, 751, 401));
        frmSFML->setFrameShape(QFrame::StyledPanel);
        frmSFML->setFrameShadow(QFrame::Raised);
        tabDirectory->addTab(tabQuickPlay, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        btnSupprimerChansonBiblio = new QPushButton(tab_3);
        btnSupprimerChansonBiblio->setObjectName(QStringLiteral("btnSupprimerChansonBiblio"));
        btnSupprimerChansonBiblio->setGeometry(QRect(1060, 250, 121, 31));
        btnAjouterChansonBiblio = new QPushButton(tab_3);
        btnAjouterChansonBiblio->setObjectName(QStringLiteral("btnAjouterChansonBiblio"));
        btnAjouterChansonBiblio->setGeometry(QRect(1060, 210, 121, 31));
        directoryTable = new QTableWidget(tab_3);
        if (directoryTable->columnCount() < 4)
            directoryTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        directoryTable->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        directoryTable->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        directoryTable->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        directoryTable->setHorizontalHeaderItem(3, __qtablewidgetitem6);
        directoryTable->setObjectName(QStringLiteral("directoryTable"));
        directoryTable->setGeometry(QRect(10, 10, 991, 491));
        directoryTable->setAutoFillBackground(false);
        directoryTable->setFrameShape(QFrame::StyledPanel);
        directoryTable->setFrameShadow(QFrame::Sunken);
        directoryTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        directoryTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        directoryTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        directoryTable->setDragEnabled(true);
        directoryTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        directoryTable->setGridStyle(Qt::SolidLine);
        directoryTable->setSortingEnabled(false);
        btnAjouterCurrentBiblio = new QPushButton(tab_3);
        btnAjouterCurrentBiblio->setObjectName(QStringLiteral("btnAjouterCurrentBiblio"));
        btnAjouterCurrentBiblio->setGeometry(QRect(1060, 170, 121, 31));
        tabDirectory->addTab(tab_3, QString());
        tabCollections = new QWidget();
        tabCollections->setObjectName(QStringLiteral("tabCollections"));
        tabCollectionList = new QTabWidget(tabCollections);
        tabCollectionList->setObjectName(QStringLiteral("tabCollectionList"));
        tabCollectionList->setGeometry(QRect(0, 0, 1241, 521));
        tabCollectionList->setTabsClosable(false);
        tabCollectionList->setMovable(true);
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        affichageCollectionTable = new QTableWidget(tab_2);
        if (affichageCollectionTable->columnCount() < 4)
            affichageCollectionTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        affichageCollectionTable->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        affichageCollectionTable->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        affichageCollectionTable->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        affichageCollectionTable->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        affichageCollectionTable->setObjectName(QStringLiteral("affichageCollectionTable"));
        affichageCollectionTable->setGeometry(QRect(320, 0, 901, 481));
        affichageCollectionTable->setAutoFillBackground(false);
        affichageCollectionTable->setFrameShape(QFrame::StyledPanel);
        affichageCollectionTable->setFrameShadow(QFrame::Sunken);
        affichageCollectionTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        affichageCollectionTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        affichageCollectionTable->setDragEnabled(true);
        affichageCollectionTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        affichageCollectionTable->setGridStyle(Qt::SolidLine);
        affichageCollectionTable->setSortingEnabled(false);
        collectionTable = new QTableWidget(tab_2);
        if (collectionTable->columnCount() < 1)
            collectionTable->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        collectionTable->setHorizontalHeaderItem(0, __qtablewidgetitem11);
        collectionTable->setObjectName(QStringLiteral("collectionTable"));
        collectionTable->setGeometry(QRect(0, 0, 281, 301));
        collectionTable->setAutoFillBackground(false);
        collectionTable->setFrameShape(QFrame::StyledPanel);
        collectionTable->setFrameShadow(QFrame::Sunken);
        collectionTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        collectionTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        collectionTable->setDragEnabled(true);
        collectionTable->setSelectionMode(QAbstractItemView::SingleSelection);
        collectionTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        collectionTable->setGridStyle(Qt::SolidLine);
        collectionTable->setSortingEnabled(false);
        btnSupprimerCollection = new QPushButton(tab_2);
        btnSupprimerCollection->setObjectName(QStringLiteral("btnSupprimerCollection"));
        btnSupprimerCollection->setGeometry(QRect(60, 420, 121, 31));
        btnAjouterCollection = new QPushButton(tab_2);
        btnAjouterCollection->setObjectName(QStringLiteral("btnAjouterCollection"));
        btnAjouterCollection->setGeometry(QRect(60, 380, 121, 31));
        btnJouerCollection = new QPushButton(tab_2);
        btnJouerCollection->setObjectName(QStringLiteral("btnJouerCollection"));
        btnJouerCollection->setGeometry(QRect(60, 340, 121, 31));
        tabCollectionList->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        createCollectionTable = new QTableWidget(tab);
        if (createCollectionTable->columnCount() < 4)
            createCollectionTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        createCollectionTable->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        createCollectionTable->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        createCollectionTable->setHorizontalHeaderItem(2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        createCollectionTable->setHorizontalHeaderItem(3, __qtablewidgetitem15);
        createCollectionTable->setObjectName(QStringLiteral("createCollectionTable"));
        createCollectionTable->setGeometry(QRect(0, 0, 971, 491));
        createCollectionTable->setAutoFillBackground(false);
        createCollectionTable->setFrameShape(QFrame::StyledPanel);
        createCollectionTable->setFrameShadow(QFrame::Sunken);
        createCollectionTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        createCollectionTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        createCollectionTable->setDragEnabled(true);
        createCollectionTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        createCollectionTable->setGridStyle(Qt::SolidLine);
        createCollectionTable->setSortingEnabled(false);
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(1020, 20, 161, 161));
        btnSupprimerChansonCollection = new QPushButton(groupBox);
        btnSupprimerChansonCollection->setObjectName(QStringLiteral("btnSupprimerChansonCollection"));
        btnSupprimerChansonCollection->setGeometry(QRect(20, 100, 121, 31));
        btnAjouterChansonCollection = new QPushButton(groupBox);
        btnAjouterChansonCollection->setObjectName(QStringLiteral("btnAjouterChansonCollection"));
        btnAjouterChansonCollection->setGeometry(QRect(20, 30, 121, 31));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(1020, 300, 161, 161));
        txtName = new QLineEdit(groupBox_2);
        txtName->setObjectName(QStringLiteral("txtName"));
        txtName->setGeometry(QRect(10, 60, 141, 22));
        btnSauvegarderCollection = new QPushButton(groupBox_2);
        btnSauvegarderCollection->setObjectName(QStringLiteral("btnSauvegarderCollection"));
        btnSauvegarderCollection->setGeometry(QRect(20, 110, 121, 31));
        lblNom = new QLabel(groupBox_2);
        lblNom->setObjectName(QStringLiteral("lblNom"));
        lblNom->setGeometry(QRect(20, 40, 46, 13));
        tabCollectionList->addTab(tab, QString());
        tabDirectory->addTab(tabCollections, QString());
        tabModificator = new QWidget();
        tabModificator->setObjectName(QStringLiteral("tabModificator"));
        tabModif = new QTabWidget(tabModificator);
        tabModif->setObjectName(QStringLiteral("tabModif"));
        tabModif->setGeometry(QRect(0, 0, 1231, 521));
        tabModif->setMovable(true);
        tabVizualizer = new QWidget();
        tabVizualizer->setObjectName(QStringLiteral("tabVizualizer"));
        frmSFMLVisualizer = new QFrame(tabVizualizer);
        frmSFMLVisualizer->setObjectName(QStringLiteral("frmSFMLVisualizer"));
        frmSFMLVisualizer->setGeometry(QRect(0, 0, 981, 491));
        frmSFMLVisualizer->setFrameShape(QFrame::StyledPanel);
        frmSFMLVisualizer->setFrameShadow(QFrame::Raised);
        gBoxVisualizer = new QGroupBox(tabVizualizer);
        gBoxVisualizer->setObjectName(QStringLiteral("gBoxVisualizer"));
        gBoxVisualizer->setGeometry(QRect(990, 10, 221, 481));
        layoutWidget = new QWidget(gBoxVisualizer);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 181, 431));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lblSampleSize = new QLabel(layoutWidget);
        lblSampleSize->setObjectName(QStringLiteral("lblSampleSize"));

        verticalLayout->addWidget(lblSampleSize);

        cboxSample = new QComboBox(layoutWidget);
        cboxSample->setObjectName(QStringLiteral("cboxSample"));

        verticalLayout->addWidget(cboxSample);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        lblSoundBar = new QLabel(layoutWidget);
        lblSoundBar->setObjectName(QStringLiteral("lblSoundBar"));

        verticalLayout->addWidget(lblSoundBar);

        pbtnSoundBars = new QPushButton(layoutWidget);
        pbtnSoundBars->setObjectName(QStringLiteral("pbtnSoundBars"));

        verticalLayout->addWidget(pbtnSoundBars);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        lblJumpers = new QLabel(layoutWidget);
        lblJumpers->setObjectName(QStringLiteral("lblJumpers"));

        verticalLayout->addWidget(lblJumpers);

        pbtnJumpers = new QPushButton(layoutWidget);
        pbtnJumpers->setObjectName(QStringLiteral("pbtnJumpers"));

        verticalLayout->addWidget(pbtnJumpers);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        lblBackGround = new QLabel(layoutWidget);
        lblBackGround->setObjectName(QStringLiteral("lblBackGround"));

        verticalLayout->addWidget(lblBackGround);

        pbtnBackground = new QPushButton(layoutWidget);
        pbtnBackground->setObjectName(QStringLiteral("pbtnBackground"));

        verticalLayout->addWidget(pbtnBackground);

        tabModif->addTab(tabVizualizer, QString());
        tabKeyboard = new QWidget();
        tabKeyboard->setObjectName(QStringLiteral("tabKeyboard"));
        label_4 = new QLabel(tabKeyboard);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(490, 390, 46, 13));
        label_4->setBaseSize(QSize(592, 260));
        horizontalLayoutWidget_4 = new QWidget(tabKeyboard);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(0, 110, 1201, 291));
        hboxKeyboard = new QHBoxLayout(horizontalLayoutWidget_4);
        hboxKeyboard->setSpacing(6);
        hboxKeyboard->setContentsMargins(11, 11, 11, 11);
        hboxKeyboard->setObjectName(QStringLiteral("hboxKeyboard"));
        hboxKeyboard->setContentsMargins(0, 0, 0, 0);
        tabModif->addTab(tabKeyboard, QString());
        tabEqualizer = new QWidget();
        tabEqualizer->setObjectName(QStringLiteral("tabEqualizer"));
        horizontalLayoutWidget_2 = new QWidget(tabEqualizer);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 20, 1211, 341));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_3 = new QGroupBox(horizontalLayoutWidget_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        vSlider_Volume = new QSlider(groupBox_3);
        vSlider_Volume->setObjectName(QStringLiteral("vSlider_Volume"));
        vSlider_Volume->setGeometry(QRect(1110, 18, 20, 311));
        vSlider_Volume->setValue(99);
        vSlider_Volume->setOrientation(Qt::Vertical);
        vSlider_Speed = new QSlider(groupBox_3);
        vSlider_Speed->setObjectName(QStringLiteral("vSlider_Speed"));
        vSlider_Speed->setGeometry(QRect(100, 20, 19, 311));
        vSlider_Speed->setMinimum(22050);
        vSlider_Speed->setMaximum(66150);
        vSlider_Speed->setValue(44100);
        vSlider_Speed->setOrientation(Qt::Vertical);
        vSlider_Distortion = new QSlider(groupBox_3);
        vSlider_Distortion->setObjectName(QStringLiteral("vSlider_Distortion"));
        vSlider_Distortion->setGeometry(QRect(710, 20, 20, 311));
        vSlider_Distortion->setMinimum(0);
        vSlider_Distortion->setMaximum(80);
        vSlider_Distortion->setValue(0);
        vSlider_Distortion->setOrientation(Qt::Vertical);
        vSlider_Flange = new QSlider(groupBox_3);
        vSlider_Flange->setObjectName(QStringLiteral("vSlider_Flange"));
        vSlider_Flange->setGeometry(QRect(340, 18, 20, 311));
        vSlider_Flange->setMinimum(1);
        vSlider_Flange->setMaximum(100);
        vSlider_Flange->setValue(1);
        vSlider_Flange->setOrientation(Qt::Vertical);
        vSlider_Echo = new QSlider(groupBox_3);
        vSlider_Echo->setObjectName(QStringLiteral("vSlider_Echo"));
        vSlider_Echo->setGeometry(QRect(220, 18, 20, 311));
        vSlider_Echo->setMaximum(200);
        vSlider_Echo->setValue(0);
        vSlider_Echo->setOrientation(Qt::Vertical);
        vSlider_Tremolo = new QSlider(groupBox_3);
        vSlider_Tremolo->setObjectName(QStringLiteral("vSlider_Tremolo"));
        vSlider_Tremolo->setGeometry(QRect(590, 20, 20, 311));
        vSlider_Tremolo->setMinimum(0);
        vSlider_Tremolo->setMaximum(100);
        vSlider_Tremolo->setValue(0);
        vSlider_Tremolo->setOrientation(Qt::Vertical);
        vSlider_Pitch = new QSlider(groupBox_3);
        vSlider_Pitch->setObjectName(QStringLiteral("vSlider_Pitch"));
        vSlider_Pitch->setGeometry(QRect(460, 18, 20, 311));
        vSlider_Pitch->setMinimum(25);
        vSlider_Pitch->setMaximum(100);
        vSlider_Pitch->setValue(50);
        vSlider_Pitch->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(groupBox_3);

        label = new QLabel(tabEqualizer);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(1110, 370, 51, 21));
        label_5 = new QLabel(tabEqualizer);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(100, 370, 46, 21));
        label_6 = new QLabel(tabEqualizer);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(220, 370, 46, 21));
        label_7 = new QLabel(tabEqualizer);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(460, 370, 51, 21));
        label_8 = new QLabel(tabEqualizer);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(340, 370, 46, 21));
        pBtnReset = new QPushButton(tabEqualizer);
        pBtnReset->setObjectName(QStringLiteral("pBtnReset"));
        pBtnReset->setGeometry(QRect(1090, 430, 81, 41));
        pBtnReset->setFlat(false);
        label_9 = new QLabel(tabEqualizer);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(590, 370, 51, 21));
        label_10 = new QLabel(tabEqualizer);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(710, 370, 71, 21));
        tabModif->addTab(tabEqualizer, QString());
        tabDirectory->addTab(tabModificator, QString());

        gridLayout->addWidget(tabDirectory, 0, 0, 1, 1);

        mainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(mainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1256, 21));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        mainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(mainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        mainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menu->menuAction());

        retranslateUi(mainWindow);

        tabDirectory->setCurrentIndex(0);
        tabCollectionList->setCurrentIndex(0);
        tabModif->setCurrentIndex(0);
        cboxSample->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(mainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *mainWindow)
    {
        mainWindow->setWindowTitle(QApplication::translate("mainWindow", "Feed The Beat!", 0));
        pBtnPlayPause->setText(QApplication::translate("mainWindow", "Jouer/Pause", 0));
        lblVolume->setText(QApplication::translate("mainWindow", "Volume", 0));
        pBtnPrev->setText(QApplication::translate("mainWindow", "Pr\303\251c\303\251dent", 0));
        pBtnNext->setText(QApplication::translate("mainWindow", "Suivant", 0));
        label_2->setText(QApplication::translate("mainWindow", "0:00", 0));
        label_3->setText(QApplication::translate("mainWindow", "0:00", 0));
        lblPlayList->setText(QApplication::translate("mainWindow", "Liste de lecture", 0));
        QTableWidgetItem *___qtablewidgetitem = currentListTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("mainWindow", "Titre", 0));
        QTableWidgetItem *___qtablewidgetitem1 = currentListTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("mainWindow", "Album", 0));
        QTableWidgetItem *___qtablewidgetitem2 = currentListTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("mainWindow", "Artiste", 0));
        btnMonterCurrentList->setText(QApplication::translate("mainWindow", "Monter", 0));
        btnDescendreCurrentList->setText(QApplication::translate("mainWindow", "Descendre", 0));
        btnRetirerCurrentList->setText(QApplication::translate("mainWindow", "Retirer", 0));
        btnViderCurrent->setText(QApplication::translate("mainWindow", "Vider", 0));
        pbtnPutNext->setText(QApplication::translate("mainWindow", "Monter prochaine", 0));
        pbtnShuffle->setText(QApplication::translate("mainWindow", "M\303\251lange de fruits", 0));
        tabDirectory->setTabText(tabDirectory->indexOf(tabQuickPlay), QApplication::translate("mainWindow", "Feed me", 0));
        btnSupprimerChansonBiblio->setText(QApplication::translate("mainWindow", "Supprimer", 0));
        btnAjouterChansonBiblio->setText(QApplication::translate("mainWindow", "Ajouter", 0));
        QTableWidgetItem *___qtablewidgetitem3 = directoryTable->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("mainWindow", "Titre", 0));
        QTableWidgetItem *___qtablewidgetitem4 = directoryTable->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("mainWindow", "Album", 0));
        QTableWidgetItem *___qtablewidgetitem5 = directoryTable->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("mainWindow", "Artiste", 0));
        QTableWidgetItem *___qtablewidgetitem6 = directoryTable->horizontalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("mainWindow", "Dur\303\251e", 0));
        btnAjouterCurrentBiblio->setText(QApplication::translate("mainWindow", "Mettre en attente", 0));
        tabDirectory->setTabText(tabDirectory->indexOf(tab_3), QApplication::translate("mainWindow", "Biblioth\303\250que", 0));
        QTableWidgetItem *___qtablewidgetitem7 = affichageCollectionTable->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("mainWindow", "Titre", 0));
        QTableWidgetItem *___qtablewidgetitem8 = affichageCollectionTable->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("mainWindow", "Album", 0));
        QTableWidgetItem *___qtablewidgetitem9 = affichageCollectionTable->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QApplication::translate("mainWindow", "Artiste", 0));
        QTableWidgetItem *___qtablewidgetitem10 = affichageCollectionTable->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QApplication::translate("mainWindow", "Dur\303\251e", 0));
        QTableWidgetItem *___qtablewidgetitem11 = collectionTable->horizontalHeaderItem(0);
        ___qtablewidgetitem11->setText(QApplication::translate("mainWindow", "Collection", 0));
        btnSupprimerCollection->setText(QApplication::translate("mainWindow", "Supprimer", 0));
        btnAjouterCollection->setText(QApplication::translate("mainWindow", "Ajouter", 0));
        btnJouerCollection->setText(QApplication::translate("mainWindow", "Mettre en attente", 0));
        tabCollectionList->setTabText(tabCollectionList->indexOf(tab_2), QApplication::translate("mainWindow", "Collection", 0));
        QTableWidgetItem *___qtablewidgetitem12 = createCollectionTable->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QApplication::translate("mainWindow", "Titre", 0));
        QTableWidgetItem *___qtablewidgetitem13 = createCollectionTable->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QApplication::translate("mainWindow", "Album", 0));
        QTableWidgetItem *___qtablewidgetitem14 = createCollectionTable->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QApplication::translate("mainWindow", "Artiste", 0));
        QTableWidgetItem *___qtablewidgetitem15 = createCollectionTable->horizontalHeaderItem(3);
        ___qtablewidgetitem15->setText(QApplication::translate("mainWindow", "Dur\303\251e", 0));
        groupBox->setTitle(QApplication::translate("mainWindow", "Modifier", 0));
        btnSupprimerChansonCollection->setText(QApplication::translate("mainWindow", "Supprimer", 0));
        btnAjouterChansonCollection->setText(QApplication::translate("mainWindow", "Ajouter", 0));
        groupBox_2->setTitle(QApplication::translate("mainWindow", "Sauvegarder", 0));
        btnSauvegarderCollection->setText(QApplication::translate("mainWindow", "Sauvegarder", 0));
        lblNom->setText(QApplication::translate("mainWindow", "Nom :", 0));
        tabCollectionList->setTabText(tabCollectionList->indexOf(tab), QApplication::translate("mainWindow", "Cr\303\251er une collection", 0));
        tabDirectory->setTabText(tabDirectory->indexOf(tabCollections), QApplication::translate("mainWindow", "Collections", 0));
        gBoxVisualizer->setTitle(QApplication::translate("mainWindow", "Options", 0));
        lblSampleSize->setText(QApplication::translate("mainWindow", "Nombre de barres :", 0));
        cboxSample->clear();
        cboxSample->insertItems(0, QStringList()
         << QApplication::translate("mainWindow", "64", 0)
         << QApplication::translate("mainWindow", "128", 0)
         << QApplication::translate("mainWindow", "256", 0)
         << QApplication::translate("mainWindow", "512", 0)
        );
        lblSoundBar->setText(QApplication::translate("mainWindow", "Couleur des barres : ", 0));
        pbtnSoundBars->setText(QApplication::translate("mainWindow", "Selectionner...", 0));
        lblJumpers->setText(QApplication::translate("mainWindow", "Couleur des jumpers : ", 0));
        pbtnJumpers->setText(QApplication::translate("mainWindow", "Selectionner...", 0));
        lblBackGround->setText(QApplication::translate("mainWindow", "Couleur de fond : ", 0));
        pbtnBackground->setText(QApplication::translate("mainWindow", "Selectionner...", 0));
        tabModif->setTabText(tabModif->indexOf(tabVizualizer), QApplication::translate("mainWindow", "Vizualizer", 0));
        label_4->setText(QString());
        tabModif->setTabText(tabModif->indexOf(tabKeyboard), QApplication::translate("mainWindow", "Clavier", 0));
        groupBox_3->setTitle(QApplication::translate("mainWindow", "Equalizer", 0));
        label->setText(QApplication::translate("mainWindow", "Volume", 0));
        label_5->setText(QApplication::translate("mainWindow", "Vitesse", 0));
        label_6->setText(QApplication::translate("mainWindow", "  Echo", 0));
        label_7->setText(QApplication::translate("mainWindow", "Hauteur", 0));
        label_8->setText(QApplication::translate("mainWindow", "Flanger", 0));
        pBtnReset->setText(QApplication::translate("mainWindow", "R\303\251initialiser", 0));
        label_9->setText(QApplication::translate("mainWindow", "Tremolo", 0));
        label_10->setText(QApplication::translate("mainWindow", "Distortion", 0));
        tabModif->setTabText(tabModif->indexOf(tabEqualizer), QApplication::translate("mainWindow", "Equalizer", 0));
        tabDirectory->setTabText(tabDirectory->indexOf(tabModificator), QApplication::translate("mainWindow", "DJs House", 0));
        menuMenu->setTitle(QApplication::translate("mainWindow", "\303\200 Propos", 0));
        menu->setTitle(QApplication::translate("mainWindow", "?", 0));
    } // retranslateUi

};

namespace Ui {
    class mainWindow: public Ui_mainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
