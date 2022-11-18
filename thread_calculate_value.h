class Thread_calculate_value : public QThread
{
Q_OBJECT
public:
    MyLibraryWrapper();
protected:
   void run();
signals:
   void done(const QString &results);
private slots:
   void doTheWork();
};
