#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QThread>
#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
//#include <QtSerialPort/QSerialPort>
//#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>
#include <QTime>
#include <QNetworkInterface>
#include <QList>
#include <QTcpServer>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QFileDialog>
#include <QCryptographicHash>
namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:
    void udpprocessPendingDatagram();
    void RecTimeOut();
    void SendAPart();
    void Read_Data();

    void on_pushButton_clicked();

    void on_sendButton_2_clicked();

    void TimerTimeOut();//超时没有收到数据弹窗

    void on_PutMessage_clicked();

    void on_SendMessage_clicked();

    void new_client();//链接后的回调即槽函数
    void read_client_data();//作为服务器收到数据后的槽函数
    void client_dis();

    void on_textEdit_destroyed();

    void on_SendTcpData_clicked();

    void on_SetTcpPort_clicked();

    void Client_read_data();

    void on_ClientconnectServer_clicked();

    void on_ClientSendData_clicked();
    void ClientconnectServer_suc();
    void ClientconnectServe_dis();


    void on_disClientconnectServer_clicked();
    void myTimeout();

    void on_ChooseFile_clicked();

    void on_UpdateCode_clicked();
    void on_UpdateCode_2_clicked();

    void on_FilePack_clicked();

    void on_CannelUpdate_clicked();

    void on_ListenButton_clicked();

    void on_recChooseFile_clicked();


    void on_GetNewFile_clicked();

    void on_progressBar_destroyed();

public:
    QByteArray crc = "";
private:
    QString Traversal(QString path);
    QString getHostIP(void);
    QByteArray IapPack(QByteArray *origin, int part_num, int id, int size, QByteArray *crc);
    QByteArray HexStringToByteArray(QString HexString);
     QString ByteArrayToHexString(QByteArray data);
     QString ByteArrayTo0xHexString(QByteArray data);
    class QTimer *m_timer;
    class QTimer *timer;
   // QTimer *m_timer;
    void InitTimer();
    Ui::MainWindow *ui;
    //QSerialPort *serial;
    QUdpSocket *udpreceiver;
    QTcpServer *mServer;//tcpf服务器
    QTcpSocket *mSocket;//套接字
    QTcpSocket *ClientSocket;//做客户端时候的套接字
    QList<QByteArray> part_list;//升级所用分包
    QTimer count ;
    double progress_value = 0.0;//进度条
    double each_part_bar;//每包所占进度条比率大小
    int a_part_size = 1024;//一包所占字节数
    int part_num;//包数
    int allpartsize=0;
    int part_index;//包序号
    int currprogress;//当前进度条显示
    int statusCode;//0 开始第一包  1发的过程当中  2发完了
    QByteArray SendPack;//当前发送的内容
    void sendset (unsigned short regaddr,unsigned short value);
    int failedflag=0;
    int linkstate=0;
    QString fileName;
    int updateyn=0;
    void delaymsec(int msec);

    int SerPortOpenedFlag=0;
    QFile recfile;//文件对象
    QString recfileName;//文件名字
    int recpartnum;//文件包数
    int recfileSize;//文件大小
    int recedSize=0;//已经接收文件的大小
    int recstate=0;//文件接收状态

};
#pragma pack(1)
#define PACKHEAD "\xff\xf0"
#define PACKTAIL "\xf0\xff"
typedef struct uS0
{
    unsigned short Freq;
    unsigned short Dbuv;
    unsigned short Swon;
}unitPara;
typedef struct uS1
{
    unitPara nPara[8];
    unsigned short allsw;
}RDNAdata;


typedef struct {

  unsigned char dataLen;
  unsigned short totLen;
  unsigned char Cmd;
  unsigned char CmdAux;
  unsigned char TxDataBuf[500];

}ZHCCOMTX;
#endif // MAINWINDOW_H
