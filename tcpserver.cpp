#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newdialog.h"
bool OK;
int   addr=1;
quint16 yport=9999;
quint16 port=9999;
unsigned char haveClient=0;
//掉线后的槽函数
void MainWindow::client_dis()
{
    qDebug()<<"掉线";
    QTcpSocket *obj = (QTcpSocket*)sender();//掉线对象
    
    ui->serEdit->append("掉线"+obj->peerAddress().toString());
}
//链接后的槽函数
void MainWindow::new_client()
{
    qDebug()<<"在线";
    haveClient=1;
    mSocket = mServer->nextPendingConnection();//与客户端通信的套接字
    ui->serEdit->append("在线"+mSocket->peerAddress().toString());
    //关联接收客户端数据信号readyRead信号（客户端有数据就会发readyRead信号）
    connect(mSocket,SIGNAL(readyRead()),this,SLOT(read_client_data()));
    //检测掉线信号
    connect(mSocket,SIGNAL(disconnected()),this,SLOT(client_dis()));
    
}
//作为服务器收到客户端发来的数据后的槽函数
void MainWindow::read_client_data()
{
    //可以实现同时读取多个客户端发送过来的消息
    QTcpSocket *obj = (QTcpSocket*)sender();
    QByteArray msg = obj->readAll();
    QString message=ByteArrayToHexString(msg);//ByteArrayTo0xHexString
    ui->serEdit->append(message);
    
    unsigned char *buf= (unsigned char *)msg.data();
    int len = msg.size();

    switch(recstate)
    {
        case 0://接收文件长度信息
            if(
            len==16&&
            buf[0]==0xF0&&
            buf[1]==0xF1&&
            buf[2]==0xF2&&
            buf[3]==0xF3&&
            buf[4]==0xF4&&
            buf[5]==0xF5&&
            buf[6]==0xF6&&
            buf[7]==0xF7)
            {

                recpartnum=*(unsigned int *)&buf[8];
                recfileSize=*(unsigned int *)&buf[12];
                recstate=1;


                //recfileName = QFileDialog::getOpenFileName( this,tr("文件对话框！"),"D:",tr("烧录文件(*txt *bin *hex);;""所有文件(*)"));
                ui->FilePath->setText(recfileName);
                recfileName=ui->recFilePath->text();
                //recfileName="rec.bin";
                recfile.setFileName(recfileName);
                recfile.remove();
                bool isOk = recfile.open(QIODevice::WriteOnly);

                if (false == isOk)
                {
                    ui->serEdit->append("文件失败");
                    return ;//如果打开文件失败，中断函数
                }else
                {

                    QString str =QString("接收文件开始： [%1 : %2KB],%3Bytes]").arg(recfileName).arg(recpartnum).arg(recfileSize);
                    ui->serEdit->append(str);
                    //QMessageBox::information(this,"文件信息",str);

                }
                QTextStream stream(&recfile);

                stream << "const unsigned char  BootLoaderCode[][1024] = {"<< endl; //
            }
        break;
        case 1:
            if(recfileSize>recedSize)//正在接收
            {


                QTextStream stream(&recfile);
                stream << "{"+ByteArrayTo0xHexString(msg)+"},"<< endl; //

                //recfile.write(msg);
                recedSize=recedSize+len;
                recstate=1;
            }else//接收完成
            {
                QString str =QString("接收文件结束： [%1 : %2KB],%3Bytes],%4Received]").arg(recfileName).arg(recpartnum).arg(recfileSize).arg(recedSize);
                QMessageBox::information(this,"文件信息",str);
                QTextStream stream(&recfile);
                stream << "};"<< endl; //
                recedSize=0;
                recfile.close();//关闭文件
                recstate=0;

            }


        break;
    }




    //delaymsec(1);
    QByteArray backcala;
    backcala=QCryptographicHash::hash(msg, QCryptographicHash::Md5);
    obj->write(backcala);
    





}


void MainWindow::on_SendTcpData_clicked()
{
    
    //QString msg = ui->txtTcpData->toPlainText();
    //if(haveClient==1)
    //{
    //    if(mSocket->isWritable())
    //    {
    //        mSocket->write(msg.toUtf8());//转编码
    //    }
    //}
}

//端口号设定按钮
void MainWindow::on_SetTcpPort_clicked()
{
    
    if(SerPortOpenedFlag==0)
    {
        mServer->listen(QHostAddress::Any,port);//9999为端口号
        connect(mServer,SIGNAL(newConnection()),this,SLOT(new_client()));
        SerPortOpenedFlag=1;//已经正确监听
        ui->serPort->setEnabled(false);
        
    }else if(SerPortOpenedFlag==1)
    {
        mServer->disconnect();
        mServer->close();
        
        SerPortOpenedFlag=0;//没有被监听 需要下次重新创建
        ui->serPort->setEnabled(true);

    }


}

void MainWindow::udpprocessPendingDatagram() //处理等待的数据报
{
    while(udpreceiver->hasPendingDatagrams()) //拥有等待的数据报
    {
        QByteArray datagram; //拥于存放接收的数据报
        datagram.resize(udpreceiver->pendingDatagramSize());
        udpreceiver->readDatagram(datagram.data(),datagram.size());
        QString udpmessage=ByteArrayToHexString(datagram);
        ui->serEdit->append(udpmessage);
    }
}
void MainWindow::on_ListenButton_clicked()
{
    bool boolOK;
    QString setport=ui->serPort->text();//
    port=setport.toUShort(&boolOK, 10);
    ui->serIPNum->setText(ui->hostIPNum->text());
    on_SetTcpPort_clicked();


}

