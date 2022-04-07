#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newdialog.h"

unsigned int rdex=0;
unsigned int wdex=0;
#define  rwmax 10
void MainWindow::on_PutMessage_clicked()
{

    QString debugstring("Write@");
    if(((wdex+1)%rwmax)==rdex)//满
    {
        // debugstring=debugstring+" None";

    }else
    {
        wdex++;
        if(wdex>=rwmax)wdex=0;
        unsigned char ysdex=0;//原来的下标
        debugstring=debugstring+"["+QString::number((wdex>0)?(wdex-1):(rwmax-1))+"] +1--> "+QString::number(wdex);
    }

}

void MainWindow::on_SendMessage_clicked()
{
    QString debugstring("Read @");
    if(rdex!=wdex)//不空
    {
        rdex++;
        if(rdex>=rwmax)rdex=0;
        debugstring=debugstring+"["+QString::number((rdex>0)?(rdex-1):(rwmax-1))+"] +1--> "+QString::number(rdex);

    }else
    {
        // debugstring=debugstring+" None";
    }

    //if(rdex>=rwmax)rdex=0;
}
