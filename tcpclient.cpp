#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newdialog.h"
//作为客户端收到数据时的回调函数
quint16 sport=9999;
quint16 index=0;
unsigned txflag=0;
void MainWindow::Client_read_data()
{
    QByteArray bytes = ClientSocket->readAll();
    QByteArray calabytes;
    QString message=ByteArrayToHexString(bytes);
    //显示
    updateyn=0;//建立连接成功后不升级
    //ui->rxTcpData->append(message);
    calabytes=QCryptographicHash::hash(SendPack, QCryptographicHash::Md5);
    if(calabytes==bytes)//电脑计算的md5和板子计算的md5一致
    {
        ui->textEdit->append("[接收] "+QString::number(part_index-1)+" 长度"+QString::number(bytes.length())+"字节 MD5成功");

    }else
    {
        ui->textEdit->append("[接收] "+QString::number(part_index-1)+" 长度"+QString::number(bytes.length())+"字节 MD5失败");
        failedflag=1;

    }
    if(failedflag==0)
    {
        SendAPart();
    }

}
void MainWindow::myTimeout()
{
    QTimer *timer = new QTimer();
    timer->setSingleShot(true);
    timer->start(500);
    connect(timer, SIGNAL(timeout()), this, SLOT(myTimeout()));
    switch(txflag)
    {
    //case 0:txflag=1;on_ClientSendData_clicked();break;        //发送数据
    //case 1:txflag=2;on_disClientconnectServer_clicked();break;//断开服务器连接
    //case 2:txflag=0;on_ClientconnectServer_clicked();break;   //连接服务器
    }
}
void MainWindow::on_ClientconnectServer_clicked()
{
    bool boolOK;
    QString qport=ui->serPortNum->text();//
    QString ip=ui->serIPNum->text();
    sport=qport.toUShort(&boolOK, 10);

    ClientSocket->connectToHost(ip,sport);
    updateyn=0;

}

void MainWindow::on_CannelUpdate_clicked()
{
    on_disClientconnectServer_clicked();
    QThread::msleep(1500);
    on_ClientconnectServer_clicked();

    QMessageBox::StandardButton rb ;
    rb= QMessageBox::question(NULL, "Confirm ESC BOOTLOADER", "确认退出BOOTLOADER？", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if(rb == QMessageBox::Yes)
    {
        ui->textEdit->append("退出Bootloader指令已发送");
        QByteArray SendHeadCode;
        SendHeadCode[0]=0xA0;
        SendHeadCode[1]=0xA1;
        SendHeadCode[2]=0xA2;
        SendHeadCode[3]=0xA3;

        SendHeadCode[4]=0xA4;
        SendHeadCode[5]=0xA5;
        SendHeadCode[6]=0xA6;
        SendHeadCode[7]=0xA7;

        SendHeadCode[8]=0xA8;
        SendHeadCode[9]=0xA9;
        SendHeadCode[10]=0xAA;
        SendHeadCode[11]=0xAB;
        if(ClientSocket->ConnectedState)
        {
            ClientSocket->write(SendHeadCode);

        }else
        {
            on_ClientconnectServer_clicked();
            //ClientSocket->write(SendHeadCode);
        }
        //发完之后断开
        QThread::msleep(1000);
        on_disClientconnectServer_clicked();
    }
}

void MainWindow::on_disClientconnectServer_clicked()
{

    ClientSocket->disconnectFromHost();
    linkstate=0;
}

void MainWindow::on_pushButton_clicked()
{

    on_disClientconnectServer_clicked();
    QThread::msleep(1500);
    on_ClientconnectServer_clicked();

    //QMessageBox::StandardButton rb ;
    //rb= QMessageBox::question(NULL, "Confirm ENTER BOOTLOADER", "确认进入BOOTLOADER？", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    //if(rb == QMessageBox::Yes)
    {
        ui->textEdit->append("进入Bootloader指令已发送");

        //使得进入iap模式
        QUdpSocket qus;
        QByteArray msg;
        int i=0;
        msg[i++]=0x00;
        msg[i++]=0x02;
        msg[i++]=0x35;
        msg[i++]=0x47;
        msg[i++]=0x5F;
        msg[i++]=0x56;
        msg[i++]=0x45;
        msg[i++]=0x52;
        msg[i++]=0x5F;
        msg[i++]=0x44;
        msg[i++]=0x32;
        msg[i++]=0x41;
        msg[i++]=0x53;
        msg[i++]=0x32;
        msg[i++]=0x30;
        msg[i++]=0x30;
        msg[i++]=0x37;
        msg[i++]=0x41;
        msg[i++]=0x2E;
        msg[i++]=0x62;
        msg[i++]=0x69;
        msg[i++]=0x6E;
        msg[i++]=0x00;
        msg[i++]=0x6F;
        msg[i++]=0x63;
        msg[i++]=0x74;
        msg[i++]=0x65;
        msg[i++]=0x74;
        msg[i++]=0x00;
        msg[i++]=0x62;
        msg[i++]=0x6C;
        msg[i++]=0x6B;
        msg[i++]=0x73;
        msg[i++]=0x69;
        msg[i++]=0x7A;
        msg[i++]=0x65;
        msg[i++]=0x00;
        msg[i++]=0x35;
        msg[i++]=0x31;
        msg[i++]=0x32;
        msg[i++]=0x00;
        msg[i++]=0x74;
        msg[i++]=0x73;
        msg[i++]=0x69;
        msg[i++]=0x7A;
        msg[i++]=0x65;
        msg[i++]=0x00;
        msg[i++]=0x32;
        msg[i++]=0x30;
        msg[i++]=0x32;
        msg[i++]=0x34;
        msg[i++]=0x35;
        msg[i++]=0x33;
        msg[i++]=0x00;
        QString ip=ui->serIPNum->text();
        QHostAddress groupAddress = QHostAddress("255.255.255.255");

        qus.writeDatagram(msg, QHostAddress(ip), 69);
        //qus.writeDatagram(msg, groupAddress, 69);
    }

}

void MainWindow::on_ClientSendData_clicked()
{
    QString msg = ui->textEdit->toPlainText();//msg.toUtf8()
    QByteArray QBsendData=HexStringToByteArray(msg);
    ClientSocket->write(QBsendData);//转编码
    index++;
    QString str = QString::number(index);
    //ui->rxTcpData->append(str+":tx"+msg);
}

void MainWindow::ClientconnectServer_suc()
{
    ui->ClientconnectServer->setEnabled(false);//如果连接成功则连接按钮不能按下
    ui->disClientconnectServer->setEnabled(true);
    ui->textEdit->append("TCP连接已建立");
    if(updateyn==1)//成功建立连接后升级标志
    {
        updateyn=0;//成功建立连接后不升级
        ui->textEdit->append("升级TCP连接已建立，请确认是否升级");
        //QMessageBox::StandardButton rb ;
        //rb= QMessageBox::question(NULL, "Confirm upgrade?", "确认升级意味着设备将擦除应用程序段数据,请确保您烧入bin文件的正确性。", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        //if(rb == QMessageBox::Yes)
        {
            SendAPart();
            failedflag=0;
        }
    }
    linkstate=1;
}

void MainWindow::ClientconnectServe_dis()
{
    ui->ClientconnectServer->setEnabled(true);//如果连接没有成功则连接按钮还可以按下
    ui->disClientconnectServer->setEnabled(false);
    ui->textEdit->append("TCP连接已断开");
    linkstate=0;
}

QByteArray MainWindow::IapPack(QByteArray *origin, int part_num, int id, int size, QByteArray *crc)
{
    QByteArray packed_date;
    packed_date.insert(0, PACKHEAD);
    packed_date[5] = part_num >> 24;
    packed_date[4] = part_num >> 16;
    packed_date[3] = part_num >> 8;
    packed_date[2] = part_num;

    packed_date[9] = id >> 24;
    packed_date[8] = id >> 16;
    packed_date[7] = id >> 8;
    packed_date[6] = id;

    packed_date[13] = size >> 24;
    packed_date[12] = size >> 16;
    packed_date[11] = size >> 8;
    packed_date[10] = size;

    packed_date.append( *origin);

    packed_date.append(PACKTAIL);

    // qDebug() << "packed is :" <<packed_date;

    return packed_date;
}

void MainWindow::delaymsec(int msec) {
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

}



void MainWindow::on_UpdateCode_clicked()
{

    ui->textEdit->clear();
    QMessageBox::StandardButton rb ;

    fileName=ui->FilePath->text();


    if(fileName.contains(".bin",Qt::CaseSensitive))
    {

        ui->textEdit->append("文件正在分包...");
        on_FilePack_clicked();//分包
        delaymsec(200);
        on_pushButton_clicked();//进入升级模式
        ui->textEdit->append("已下发进入Bootloader的UDP指令");
        delaymsec(500);
        on_disClientconnectServer_clicked();
        delaymsec(500);
        rb= QMessageBox::question(NULL, "Connect", "确认升级?开始连接,连接成功后将开始升级", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        if(rb == QMessageBox::Yes)
        {
            on_ClientconnectServer_clicked();
            updateyn=1;
        }

    }else
    {
        ui->textEdit->append("文件无效请重新选择");
        rb= QMessageBox::question(NULL, "提示", "无效文件，请重新选择！", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

        if(rb == QMessageBox::Yes)
        {

            on_ChooseFile_clicked();//选择文件
        }


    }

}
void MainWindow::on_FilePack_clicked()//分包
{
    part_list.clear();//清除分包
    QFile bin_file(ui->FilePath->text());
    QByteArray file_array;
    if(bin_file.open(QIODevice::ReadOnly))
    {//成功读取文件
        ui->textEdit->append("文件打开成功! 确认设备处于升级模式，并连接后即可升级");
        file_array = bin_file.readAll();
    }
    else
    {//读取文件失败
        ui->textEdit->append("文件打开失败，请检查文件路径");
        return;
    }
    ui->textEdit->append("请等待......");
    /************文件分包******************/
    a_part_size=1024;//一包纯数据部分大小是1024字节
    allpartsize=file_array.length();
    part_num = file_array.length()/a_part_size + 1;//包的个数
    each_part_bar = 100.0/(double)part_num;//每个包占进度条的大小比率
    ui->textEdit->append("分包个数: "+QString::number(part_num));
    qDebug()<<"this data has :" << file_array.length() << "could divide:" << part_num << "each part" << each_part_bar;
    if(!part_list.isEmpty())
    {
        qDebug()<< "not empty," << part_list;
    }
    for(int part = 0; part < part_num; part++)//进行分包
    {
        part_list << file_array.mid( part*a_part_size, a_part_size);
        ui->textEdit->append("文件分包: "+QString::number(part_list[part].length())+"字节");

    }
    part_index=0;//从第0个开始发
    statusCode=0;

    file_array.clear();

}
void MainWindow::on_UpdateCode_2_clicked()
{

}
void MainWindow::RecTimeOut()
{

}
void MainWindow::SendAPart()
{
    count.stop();
    QByteArray SendHeadCode;
    int Len;

    currprogress=(int)(each_part_bar*((double)part_index+1.0));
    ui->progressBar->setValue(currprogress);


    switch(statusCode)
    {
    case 0://第一步先头 告诉单片机有几个包
        statusCode=1;
        Len=part_num;
        SendHeadCode[0]=0xF0;
        SendHeadCode[1]=0xF1;
        SendHeadCode[2]=0xF2;
        SendHeadCode[3]=0xF3;

        SendHeadCode[4]=0xF4;
        SendHeadCode[5]=0xF5;
        SendHeadCode[6]=0xF6;
        SendHeadCode[7]=0xF7;

        SendHeadCode[8]=Len>>0;
        SendHeadCode[9]=Len>>8;
        SendHeadCode[10]=Len>>16;
        SendHeadCode[11]=Len>>24;

        SendHeadCode[12]=allpartsize>>0;
        SendHeadCode[13]=allpartsize>>8;
        SendHeadCode[14]=allpartsize>>16;
        SendHeadCode[15]=allpartsize>>24;

        SendPack=SendHeadCode;
        ClientSocket->write(SendPack);
        ui->textEdit->append("[发送] "+QString::number(Len)+" 个包");
        break;
    case 1://正在发送
        if(part_num>part_index)//还有包需要发送
        {
            /*
            if(ui->PackData->checkState())//数据重新整理加头尾等
            {
                SendPack=IapPack(&part_list[part_index], part_num, part_index, part_list[part_index].length(), &crc);
                ClientSocket->write(SendPack);
                ui->textEdit->append("Packed Index :"+QString::number(part_index));
            }else//直接发不加头尾等
            */
            {
                SendPack=part_list[part_index];
                ClientSocket->write(SendPack);
                ui->textEdit->append("[发送]:"+QString::number(part_index)+" 长度"+QString::number(part_list[part_index].length())+"字节");
            }
            part_index++;
        }else
        {
            statusCode=2;//发完了

            SendHeadCode[0]=0xA0;
            SendHeadCode[1]=0xA1;
            SendHeadCode[2]=0xA2;
            SendHeadCode[3]=0xA3;

            SendHeadCode[4]=0xA4;
            SendHeadCode[5]=0xA5;
            SendHeadCode[6]=0xA6;
            SendHeadCode[7]=0xA7;

            SendHeadCode[8]=0xA8;
            SendHeadCode[9]=0xA9;
            SendHeadCode[10]=0xAA;
            SendHeadCode[11]=0xAB;

            SendPack=SendHeadCode;
            if(failedflag==0)
            {
                ui->textEdit->append("升级完成, 设备正在重启，设备重启成功");
                ClientSocket->write(SendPack);//校验没出错过 -_-

            }else
            {
                ui->textEdit->append("升级失败，请按照第①步 使设备进入升级模式，如设备已处于升级模式，请断电重启设备并重新尝试升级。");
            }
        }
        break;
    case 2:
        statusCode=0;//复位

        break;

    default :
        statusCode=0;//复位
        break;

    }



}
