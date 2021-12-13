#include "workerManager.h"


//����ʵ�ֹ��캯��
WorkerManager::WorkerManager()
{
    //�ļ�������
    ifstream ifs;
    ifs.open(FILENAME, ios::in);//���ļ�
    if (!ifs.is_open())
    {
        //cout << "�ļ�������" << endl;
        //��ʼ����¼����Ϊ0
        this->m_empnum = 0;
        //��ʼ������ָ��
        this->m_emparray = NULL;
        this->isEmpty = true;
        ifs.close();
        return;
    }
    //�ļ����ڣ�������Ϊ��
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        //�ļ�Ϊ��
        //cout << "�ļ�Ϊ��" << endl;
        //��ʼ����¼����Ϊ0
        this->m_empnum = 0;
        //��ʼ������ָ��
        this->m_emparray = NULL;
        this->isEmpty = true;
        ifs.close();
        return;
    }

    //�ļ����������ݲ�Ϊ��
    int num = this->get_EmpNum();
    //cout << "ְ������Ϊ��" << num << endl;
    this->m_empnum = num;

    //���ٿռ�
    this->m_emparray = new Worker * [this->m_empnum];
    //���ļ��е����ݣ��浽������
    this->init_Emp();
    ////���Դ��룬��ӡ�ļ��е�����
    //for (int i = 0;i < this->m_empnum;i++)
    //{
    //    cout << "ְ����ţ�" << this->m_emparray[i]->m_id << "  "
    //        << "ְ��������" << this->m_emparray[i]->m_name<< "  "
    //        << "���ű�ţ�" << this->m_emparray[i]->m_dept_id<< "  " << endl;

    //}

}



////չʾ�˵�
void WorkerManager::Show_Menu() {
    cout << "************************" << endl;
    cout << "** ��ӭʹ��ְ������ϵͳ! **" << endl;
    cout << "***** 0.�˳�������� *****" << endl;
    cout << "***** 1.����ְ����Ϣ *****" << endl;
    cout << "***** 2.��ʾְ����Ϣ *****" << endl;
    cout << "***** 3.ɾ����ְְ�� *****" << endl;
    cout << "***** 4.�޸�ְ����Ϣ *****" << endl;
    cout << "***** 5.����ְ����Ϣ *****" << endl;
    cout << "***** 6.���ձ������ *****" << endl;
    cout << "***** 7.��������ĵ� *****" << endl;
    cout << "************************" << endl;
}


//�˳�ϵͳ
void WorkerManager::ExitSystem()
{
    cout << "��ӭ�´�ʹ��" << endl;
    system("pause");
    exit(0);
}

//���ְ��
void WorkerManager::add_emp()
{
    cout << "������Ҫ��ӵ�ְ��������" << endl;
    int addnum = 0;
    cin >> addnum;

    if (addnum > 0)
    {
        //���
        //�����¿ռ�Ĵ�С
        int newsize = this->m_empnum + addnum;//�¿ռ�����=ԭ���ռ�����+���������

        //�����¿ռ�
        Worker **newspace=new Worker* [newsize];//����ָ��

        //��ԭ���ռ��µ����ݣ��������µĿռ���
        if (this->m_emparray != NULL)
        {
            for (int i = 0;i < this->m_empnum;i++)
            {
                newspace[i] = this->m_emparray[i];
            }
        }
        //���������
        for (int i = 0;i < addnum;i++)
        {
            int id;//ְ�����
            string name;//ְ������
            int dSelect;//����ѡ��

            cout << "�������" << i + 1 << "����ְ���ı�ţ�" << endl;
            cin >> id;
            cout << "�������" << i + 1 << "����ְ����������" << endl;
            cin >> name;
            cout << "��ѡ���ְ���ĸ�λ��" << endl;
            cout << "1.��ְͨ��"<<endl;
            cout << "2.����" << endl;
            cout << "3.�ϰ�" << endl;
            cin >> dSelect;

            Worker* worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 1);
                break;
            case 3:
                worker = new Boss(id, name, 1);
                break;
            default:
                break;
            }
            //������ְ��ְ�𣬱��浽������
            newspace[this->m_empnum + i] = worker;

        }
        //�ͷ�ԭ�пռ�
        delete[] this->m_emparray;

        //�����¿ռ��ָ��
        this->m_emparray = newspace;

        //�����µ�ְ������
        this->m_empnum = newsize;

        //����ְ����Ϊ�յı�־
        this->isEmpty = false;

        //��ʾ��ӳɹ�
        cout << "�ɹ����" << addnum << "���µ�ְ��" << endl;
        
        //�������ݵ��ļ���
        this->save();
    }
    else
    {
        cout << "��������" << endl;
    }

    //�����������������һĿ¼
    system("pause");
    system("cls");
}



//�����ļ�
void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ�--д�ļ�

    //��ÿ���˵�����д�뵽�ļ���
    for (int i = 0;i < this->m_empnum;i++)
    {
        ofs << this->m_emparray[i]->m_id << " "
            << this->m_emparray[i]->m_name << " "
            << this->m_emparray[i]->m_dept_id << endl;
    }

    //�ر��ļ�
    ofs.close();
}

//ͳ���ļ��е�����
int  WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int num = 0;//������
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        num++;
    }
    return num;
}

//��ʼ��Ա��
void WorkerManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int dId;

    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker* worker = NULL;
        if (dId == 1)//��ְͨ��
        {
            worker = new Employee(id, name, dId);
        }
        else if (dId == 2)//����
        {
            worker = new Manager(id, name, dId);

        }
        else//�ϰ�
        {
            worker = new Boss(id, name, dId);
        }

        this->m_emparray[index] = worker;
        index++;
    }
    //�ر��ļ�
    ifs.close();
}

//��ʾְ��
void WorkerManager::ShowEmp()
{
    //�ж��ļ��Ƿ�Ϊ��
    if (this->isEmpty)
    {
        cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
    }
    else
    {
        for (int i = 0;i < m_empnum;i++)
        {
            //���ö�̬���ýӿ�
            this->m_emparray[i]->showInfo();
        }
    }
    //�����������
    system("pause");
    system("cls");
}

//ɾ��ְ��
void WorkerManager::Del_Emp()
{
    if (this->isEmpty)
    {
        cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
    }
    else
    {
        //����ְ����Ž���ɾ��
        cout << "������Ҫɾ����Ա����ţ�" << endl;
        int id = 0;
        cin >> id;
        int index = this->IsExist(id);
        if (index != -1)
        {
            //�ҵ��ˣ���ʼɾ��
            for (int i = index;i < this->m_empnum - 1;i++)
            {
                this->m_emparray[i] = this->m_emparray[i + 1];
            }
            this->m_empnum--;

            //ͬ�����µ��ļ���
            this->save();

            cout << "ɾ���ɹ�" << endl;
        }
        else
        {
            cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
        }
    }

    //�����������
    system("pause");
    system("cls");
}

//�ж�ְ���Ƿ���ڣ�������ڣ����������±꣬���򷵻�-1
int WorkerManager::IsExist(int id)
{
    int index = -1;
    for (int i=0;i < this->m_empnum;i++)
    {
        if (this->m_emparray[i]->m_id == id)
        {
            index = i;//�ҵ���
            break;
        }
    }
    return index;
}

//�޸�ְ��
void WorkerManager::Modify_Emp()
{
    if (this->isEmpty)
    {
        cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
    }
    else
    {
        cout << "������Ҫ�޸ĵ�ְ���ı�ţ�" << endl;
        int id;
        cin >> id;
        int ret=this->IsExist(id);
        if (ret != -1)
        {
            //�ҵ��ˣ���ʼ�޸�
            delete this->m_emparray[ret];
            int newId = 0;//�µ�id
            string newName;//�µ�����
            int dSelect = 0;//�µĲ���

            cout << "�鵽" << id << "��ְ�����������µ�ְ���ţ�" << endl;
            cin >> newId;

            cout << "�������µ�������" << endl;
            cin >> newName;

            cout << "�������µĸ�λ��" << endl;
            cout << "1.��ͨ��λ\n2.����\n3.�ϰ�" <<endl;
            cin >> dSelect;

            Worker* worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(newId, newName, dSelect);
                break;
            case 2:
                worker = new Manager(newId, newName, dSelect);
                break;
            case 3:
                worker = new Boss(newId, newName, dSelect);
                break;
            }

            //�������ݵ�������
            this->m_emparray[ret] = worker;
            cout << "�޸ĳɹ���" << endl;

            //���浽�ļ���
            this->save();
        }
        else
        {
            cout << "�޸�ʧ�ܣ����޴���" << endl;
        }
    }

    //�����������
    system("pause");
    system("cls");
}

//����Ա��
void WorkerManager::FindEmp()
{
    if (this->isEmpty)
    {
        cout << "�ļ������ڻ��߼�¼Ϊ��" <<endl;
    }
    else
    {
        cout << "��������ҵķ�ʽ��" <<endl;
        cout << "1.����ְ����Ų���\n2.����ְ����������" << endl;

        int select = 0;
        cin >> select;
        if (select == 1)
        {
            //���ձ�Ų�
            int id;
            cout << "������Ҫ���ҵ�ְ����ţ�" << endl;
            cin >> id;

            int ret = this->IsExist(id);
            if (ret != -1)
            {
                cout << "���ҳɹ�!��ְ������Ϣ���£�" << endl;
                this->m_emparray[ret]->showInfo();
            }
            else
            {
                cout << "����ʧ�ܣ����޴���" << endl;
            }
        }
        else if (select == 2)
        {
            //��������
            string name;
            cout << "������Ҫ���ҵ�ְ��������" << endl;
            cin >> name;
            
            //�����ж��Ƿ�鵽�ı�־
            bool flag = false;//Ĭ��û�ҵ�

            for (int i = 0;i < m_empnum;i++)
            {
                if (this->m_emparray[i]->m_name == name)
                {
                    cout << "���ҳɹ�����ְ�����Ϊ��"
                        << this->m_emparray[i]->m_id
                        << "��ְ������Ϣ���£�" << endl;
                    flag = true;
                    //������ʾ��Ϣ�Ľӿ�
                    this->m_emparray[i]->showInfo();
                }
            }
            if (flag == false)
            {
                cout << "����ʧ�ܣ����޴���" << endl;
            }
        }
        else
        {
            cout << "��������" << endl;
        }
    }
    //�����������
    system("pause");
    system("cls");
}

//����ְ����Ž�������
void WorkerManager::SortEmp()
{
    if (this->isEmpty)
    {
        cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
        //�����������
        system("pause");
        system("cls");
    }
    else
    {
        cout << "��ѡ������ķ�ʽ��\n1. ����ְ��������\n2.����ְ���Ž���" << endl;

        int select = 0;
        cin >> select;

        //ѡ������
        for (int i = 0;i < this->m_empnum-1;i++)
        {
            int minOrMax = i;//������ǰ��Сֵ�����ֵ���±�
            for (int j = i + 1;j < this->m_empnum;j++)
            {
                if (select == 1)//����
                {
                    if (this->m_emparray[minOrMax]->m_id > this->m_emparray[j]->m_id)
                    {
                        minOrMax = j;
                    }
                }
                else//����
                {
                    if (this->m_emparray[minOrMax]->m_id < this->m_emparray[j]->m_id)
                    {
                        minOrMax = j;
                    }
                }

            }
            if (i != minOrMax)
            {
                Worker * temp = this->m_emparray[i];
                this->m_emparray[i] = this->m_emparray[minOrMax];
                this->m_emparray[minOrMax] = temp;
            }
        }
        cout << "����ɹ��������Ľ��Ϊ��" << endl;
        this->save();//���������浽�ļ���
        this->ShowEmp();//չʾ������ְ����Ϣ

    }
}

//����ļ�
void WorkerManager::CleanFile()
{
    cout << "ȷ�������\n1.�ǵ� 2.����" <<endl;
    int select=0;
    cin >> select;
    if (select == 1)//ȷ��
    {
        //����ļ�
        ofstream ofs(FILENAME, ios::trunc);//trunc:ɾ���ļ������´���
        ofs.close();

        if (this->m_emparray != NULL)
        {
            //ɾ��������ÿ��ְ������
            for (int i = 0;i < m_empnum;i++)
            {
                delete this->m_emparray[i];
                this->m_emparray[i] = NULL;
            }

            //ɾ������������ָ��
            delete[]this->m_emparray;
            this->m_emparray = NULL;
            this->m_empnum = 0;
            this->isEmpty = true;
            cout << "��ճɹ���" << endl;
        }
    }
    system("pause");
    system("cls");


}

//����ʵ����������
WorkerManager::~WorkerManager()
{
    if (this->m_emparray != NULL)
    {
        for (int i = 0;i < this->m_empnum;i++)
        {
            if (this->m_emparray[i] != NULL)
            {
                delete this->m_emparray[i];
            }
        }
        delete[] this->m_emparray;
        this->m_emparray = NULL;
    }
}