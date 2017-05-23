#include "tableauaffichage.h"
#include <QTableWidget>
#include<mainwindow.h>



TableauAffichage::TableauAffichage(MainWindow m ):
{
    m.ui->tableau_->setColumnCount(5);

}

