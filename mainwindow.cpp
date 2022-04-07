#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newdialog.h"
#include "qtimer.h"
#include <QMessageBox>



static const unsigned char aucCRCHi[] = {
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41,
    0x00, 0xC1, 0x81, 0x40
};

static const unsigned char aucCRCLo[] = {
    0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06, 0x07, 0xC7,
    0x05, 0xC5, 0xC4, 0x04, 0xCC, 0x0C, 0x0D, 0xCD, 0x0F, 0xCF, 0xCE, 0x0E,
    0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09, 0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9,
    0x1B, 0xDB, 0xDA, 0x1A, 0x1E, 0xDE, 0xDF, 0x1F, 0xDD, 0x1D, 0x1C, 0xDC,
    0x14, 0xD4, 0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3,
    0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3, 0xF2, 0x32,
    0x36, 0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4, 0x3C, 0xFC, 0xFD, 0x3D,
    0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A, 0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38,
    0x28, 0xE8, 0xE9, 0x29, 0xEB, 0x2B, 0x2A, 0xEA, 0xEE, 0x2E, 0x2F, 0xEF,
    0x2D, 0xED, 0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26,
    0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60, 0x61, 0xA1,
    0x63, 0xA3, 0xA2, 0x62, 0x66, 0xA6, 0xA7, 0x67, 0xA5, 0x65, 0x64, 0xA4,
    0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F, 0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB,
    0x69, 0xA9, 0xA8, 0x68, 0x78, 0xB8, 0xB9, 0x79, 0xBB, 0x7B, 0x7A, 0xBA,
    0xBE, 0x7E, 0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5,
    0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71, 0x70, 0xB0,
    0x50, 0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92, 0x96, 0x56, 0x57, 0x97,
    0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C, 0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E,
    0x5A, 0x9A, 0x9B, 0x5B, 0x99, 0x59, 0x58, 0x98, 0x88, 0x48, 0x49, 0x89,
    0x4B, 0x8B, 0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C,
    0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42, 0x43, 0x83,
    0x41, 0x81, 0x80, 0x40
};
unsigned short CRC16x( unsigned char * pucFrame, unsigned short usLen )
{
    unsigned char           ucCRCHi = 0xFF;
    unsigned char           ucCRCLo = 0xFF;
    int             iIndex;
    while( usLen-- )
    {
        iIndex = ucCRCLo ^ *( pucFrame++ );
        ucCRCLo = ( unsigned char )( ucCRCHi ^ aucCRCHi[iIndex] );
        ucCRCHi = aucCRCLo[iIndex];
    }
    return ( unsigned short )( ucCRCHi << 8 | ucCRCLo );
}
void appendCrcLH(unsigned char * ahead,unsigned short lens)
{
    unsigned short crc16tmpd=CRC16x(ahead,lens);
    *(ahead+lens+0)=(crc16tmpd&0x00ff)>>0;
    *(ahead+lens+1)=(crc16tmpd&0xff00)>>8;
}

RDNAdata AnaPara;
//读取数据到结构体
void ucToPara(unsigned char * pUc,RDNAdata *pTruc)
{
    unsigned int i;
    unsigned short tmp1,tmp2;
    for(i=0;i<8;i++)
    {
        tmp1=*pUc++;
        tmp1<<=8;
        tmp2=*pUc++;
        pTruc->nPara[i].Freq=tmp1|tmp2;
        tmp1=*pUc++;
        tmp1<<=8;
        tmp2=*pUc++;
        pTruc->nPara[i].Dbuv=tmp1|tmp2;
        tmp1=*pUc++;
        tmp1<<=8;
        tmp2=*pUc++;
        pTruc->nPara[i].Swon=tmp1|tmp2;
    }
    tmp1=*pUc++;
    tmp1<<=8;
    tmp2=*pUc++;
    pTruc->allsw=tmp1|tmp2;
}
#define timedef  0
extern bool OK;
extern int   addr;
char recdata[500];
unsigned int  exptreclen=0;
#define readalllen 65
#define readalen 8
QByteArray allbuf;//收到的内容
MainWindow::MainWindow(QWidget *parent) :// 构造函数 特点：以类名作为函数名，无返回类型
    QMainWindow(parent),//多重继承方式继承了QT中的QMainWindow类
    ui(new Ui::MainWindow)//初始化列表 ：初始化一个MainWindow界面指针，其变量名为ui。
{
    ui->setupUi(this);


    ui->serIPNum->setText("192.168.1.14");//
    //ui->txtTcpData->setText("7e e7 01 fe 11 ee 00 ff 01 fe 01 fe cc");
    ui->serPortNum->setText("5060");//
    ui->serPort->setText("5060");//
    mServer = new QTcpServer();




    QTimer *timer = new QTimer();
    timer->setSingleShot(true);
    timer->start(500);
    connect(timer, SIGNAL(timeout()), this, SLOT(myTimeout()));


    ClientSocket=new QTcpSocket();//创建客户端的套接字
    ClientSocket->setSocketOption(QAbstractSocket::LowDelayOption, 1);
    connect(ClientSocket,SIGNAL(readyRead()),this,SLOT(Client_read_data()));
    connect(ClientSocket,SIGNAL(connected()),this,SLOT(ClientconnectServer_suc()));
    connect(ClientSocket,SIGNAL(disconnected()),this,SLOT(ClientconnectServe_dis()));

    ui->hostIPNum->setText(getHostIP());


    udpreceiver = new QUdpSocket();
    udpreceiver->bind(QHostAddress::AnyIPv4, 69, QUdpSocket::ShareAddress);//接收69号端口上tftp数据
    connect(udpreceiver,SIGNAL(readyRead()),this,SLOT(udpprocessPendingDatagram()));
    qDebug() << tr("界面设定成功！");
#if 0
    ui->textEdit->hide();
    ui->label_21->hide();
    ui->label_19->hide();
    ui->label_20->hide();
    ui->label_24->hide();
    ui->serEdit->hide();
    ui->recChooseFile->hide();
    ui->recFilePath->hide();
    ui->hostIPNum->hide();
    ui->serPort->hide();
    ui->ClientconnectServer->hide();
    ui->pushButton->hide();
    ui->disClientconnectServer->hide();
    ui->CannelUpdate->hide();
    ui->ListenButton->hide();
#endif
}

MainWindow::~MainWindow()
{
    qDebug() << tr("界面关闭成功！");
    delete ui;
}

unsigned int timercnt=0;
void MainWindow::TimerTimeOut()
{
#if timedef ==0
    //判断定时器是否运行
    if(m_timer->isActive())
    {
        m_timer->stop();   //停止定时器
        QString qstr(allbuf.toHex());
        int len = qstr.length()/2;
        for(int i=1;i<len;i++)
        {
            qstr.insert(2*i+i-1," ");//每隔两个
        }


        memcpy(recdata,allbuf.data(),allbuf.length());
    }
#endif
}

void MainWindow::InitTimer()
{
#if timedef ==0
    //if(NULL == m_timer)
    m_timer = new QTimer;
    //设置定时器是否为单次触发。默认为 false 多次触发
    m_timer->setSingleShot(false);
    //启动或重启定时器, 并设置定时器时间：毫秒
    //定时器触发信号槽
    connect(m_timer, SIGNAL(timeout()), this, SLOT(TimerTimeOut()));
#endif
}

//读取数据
void MainWindow::on_sendButton_2_clicked()
{

    //unsigned char ReadCmd[10]={0x2D,0x3B,0x3E,0x6F,0x00,0x00,0x02,0x78,0x00,0x00};
    unsigned char ReadCmd[8]={0x01 ,0x03 ,0x00 ,0x00 ,0x00 ,0x1E ,0xC5 ,0xC2};
    //appendCrcLH(ReadCmd,6);
    ReadCmd[0]=addr;
    appendCrcLH(ReadCmd,6);//
    //unsigned short crc16tmp=CRC16x(ReadCmd,6);
    //ReadCmd[6]=(crc16tmp&0x00ff)>>0;
    //ReadCmd[7]=(crc16tmp&0xff00)>>8;

    QByteArray readcmdarray((char*)ReadCmd, 8);
    //serial->write(readcmdarray);//按照
    exptreclen=readalllen;
    //InitTimer();

    QByteArray CmdArray((const char *)ReadCmd,8);
    QString txstr(CmdArray.toHex());
    int len = txstr.length()/2;
    for(int i=1;i<len;i++)
    {
        txstr.insert(2*i+i-1," ");//每2个插入空格
    }

}

// 将16进制字符串转换为对应的字节序列
QByteArray MainWindow::HexStringToByteArray(QString HexString)
{
    bool ok;
    QByteArray ret;
    HexString = HexString.trimmed();
    HexString = HexString.simplified();

    QStringList sl = HexString.split(" ");

    foreach (QString s, sl) {
        if(!s.isEmpty())
        {
            char c = s.toInt(&ok,16)&0xFF;
            if(ok){
                ret.append(c);
            }else{

                QMessageBox::warning(0,tr("错误："),QString("非法的16进制字符: \"%1\"").arg(s));
            }
        }
    }
    return ret;
}




//读取接收到的数据
void MainWindow::Read_Data()
{
    QByteArray buf;//字符数组
    m_timer->start(10);
    timercnt=1;
    // buf = serial->readAll();
    if(!buf.isEmpty())
    {

        allbuf+=buf;


    }
    buf.clear();
}






void MainWindow::on_textEdit_destroyed()
{

}
void CodeDataPreSend(ZHCCOMTX *pZhcDataTx,char *pTotalData,unsigned char ComAddr,unsigned char ComDev)
{

    unsigned char nComAddr=(~ComAddr);
    unsigned char nComDev=(~ComDev);
    unsigned char Len=(pZhcDataTx->dataLen);
    unsigned char nLen=(~Len);
    unsigned char Cmd=(pZhcDataTx->Cmd);
    unsigned char nCmd=(~Cmd);
    unsigned char Cmdaux=(pZhcDataTx->CmdAux);
    unsigned char nCmdaux=(~Cmdaux);
    unsigned char tmp=0;
    unsigned char ntmp=0;
    unsigned short i=0;
    (*pTotalData++)=0x7e;
    (*pTotalData++)=0xe7;
    (*pTotalData++)=(ComAddr);
    (*pTotalData++)=(nComAddr);
    (*pTotalData++)=(ComDev);
    (*pTotalData++)=(nComDev);
    (*pTotalData++)=(Len);
    (*pTotalData++)=(nLen);
    (*pTotalData++)=(Cmd);
    (*pTotalData++)=(nCmd);
    (*pTotalData++)=(Cmdaux);
    (*pTotalData++)=(nCmdaux);
    for(i=0;i<pZhcDataTx->dataLen;i++)
    {
        tmp=pZhcDataTx->TxDataBuf[i];
        ntmp=(~tmp);
        (*pTotalData++)=tmp;
        (*pTotalData++)=ntmp;
    }
    (*pTotalData++)=0xcc;
}

QString MainWindow::ByteArrayToHexString(QByteArray data)
{
    QString ret(data.toHex().toUpper());

    int len = ret.length()/2;

    for(int i=1;i<len;i++)
    {

        ret.insert(2*i+i-1," ");
    }


    return ret;
}
QString MainWindow::ByteArrayTo0xHexString(QByteArray data)
{

    QString ret(data.toHex().toUpper());//转为16进制大写
        int len = ret.length()/2;
        ret.insert(0,"0x");
        for(int i=1;i<len;i++)
        {
            ret.insert(4*i+i-1,",0x");//编写格式
        }
        return ret;


}
//遍历文件夹
QString MainWindow::Traversal(QString path)                //遍历文件夹里面的 .h 文件的方法
{
    QDir dir(path);
    QString  retpath;
    int flag=0;
    QFileInfoList list = dir.entryInfoList();
    QDateTime dtcompare=QDateTime::fromString(QString("2020-01-01 23:59:59"), "yyyy-MM-dd hh:mm:ss");

    for (int i = 0; i < list.size(); i++) {

        QFileInfo info = list.at(i);
        if(info.suffix()=="bin")
        {
            QString file_size = tr("%1").arg(info.size());

            QDateTime dt = info.created();

            QString create_time = tr("%1").arg(dt.toString("yyyy-MM-dd hh:mm:ss"));

            dt = info.lastModified();
            if(dt>dtcompare)
            {
                dtcompare=dt;//取得最新的时间

                retpath=info.path()+"/"+info.fileName();;
                flag=1;

            }

            QString modify_time = tr("%1").arg(dt.toString("yyyy-MM-dd hh:mm:ss"));

            qDebug() << "文件名:" << info.fileName()  << " 大小(Byte) :" << file_size << " 创建时间 : " << create_time << " 创建时间 : "<<modify_time ;
        }


    }
    if(flag==1)
    {
        ui->textEdit->append(tr("获取文件成功%1").arg(retpath));
        return retpath;
    }else
    {
        retpath="Get xxxxxxxxxx.Bin File Failed";
        ui->textEdit->append(tr("获取文件失败%1").arg(path));
        return retpath;
    }
}



void MainWindow::on_ChooseFile_clicked()
{

    ui->progressBar->setValue(0);
    fileName = QFileDialog::getOpenFileName( this,tr("文件对话框！"),"D:",tr("烧录文件(*txt *bin *hex);;""所有文件(*)"));
    ui->FilePath->setText(fileName);



}



bool is_virtual_network_card_or_loopback(QString str_card_name)
{
    if (-1 != str_card_name.indexOf("VMware")
            || -1 != str_card_name.indexOf("Loopback")
            || -1 != str_card_name.indexOf("VirtualBox")
            )
        return true;

    return false;
}

void get_ip(QMap<QString, int> & map_ip)
{
    // 1. 获取所有网络接口
    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();

    QList<QNetworkAddressEntry> entry;
    foreach(QNetworkInterface inter, interfaces)
    {
        // 过滤掉vmware虚拟网卡和回环网卡
        if (is_virtual_network_card_or_loopback(inter.humanReadableName()))
            continue;

        if (inter.flags() & (QNetworkInterface::IsUp | QNetworkInterface::IsRunning))
        {
            entry = inter.addressEntries();
            int cnt = entry.size() - 1;
            for (int i = 1; i <= cnt; ++i)
            {
                if (entry.at(i).ip().protocol() == QAbstractSocket::IPv4Protocol)
                {
                    if (-1 != inter.name().indexOf("wireless"))
                    {
                        map_ip.insert(entry.at(i).ip().toString(), 0);
                    }
                    else if (-1 != inter.name().indexOf("ethernet"))
                    {
                        map_ip.insert(entry.at(i).ip().toString(), 1);
                    }
                }
            }
            entry.clear();
        }
    }
}
QString MainWindow::getHostIP()  //获取ip地址
{
    QMap<QString, int> ipv4;//键 值 变量

    get_ip(ipv4);

    QMapIterator<QString, int> it(ipv4);
    while(it.hasNext())
    {
        it.next();
        qDebug() << it.key() << " : " << it.value();
        return it.key();
    }

    return 0;
}




void MainWindow::on_recChooseFile_clicked()
{
    recfileName = QFileDialog::getOpenFileName( this,tr("文件对话框！"),"D:",tr("烧录文件(*txt *bin *hex);;""所有文件(*)"));
    ui->recFilePath->setText(recfileName);
}

void MainWindow::on_GetNewFile_clicked()
{

        QString curretFiepath = QDir::currentPath();
        ui->FilePath->setText(Traversal(curretFiepath));
}

void MainWindow::on_progressBar_destroyed()
{

}
