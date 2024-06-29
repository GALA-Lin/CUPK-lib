/*********************************************************************
����������ʾ���֤�Ľṹ��
��Ȩ�����GPL��ȨЭ�飬������ʹ�úʹ����������ϴ����շ��������Ŀ⣩
���ߣ�anbangli@foxmail.com
���ڣ�2019-07-24
˵����
8-3. �����ʾ���֤���������֤�š��������Ա𡢳��������պ�סַ����Ϣ����
�ṹ�壨ȡ��IDcard��ע�����֤����Ҫ���ַ������ʾ���������弸�����������֤
���бȽϵĺ�������ͬʱ����true������ͬʱ����false����
��1�����֤���Ƿ���ͬ������ȡ��eqID������2�������Ƿ���ͬ��eqName����
��3�������������Ƿ���ͬ��eqBirth������4�����֤������Ϣ�Ƿ���ͬ��eqIDcard����
����Ӧ��ʹ�ýṹ�����������ʹ�ýṹ��ָ����������дһ����������������Щ������
*********************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

typedef struct IDcard {
    char id[19];	//���֤���Ϊ18λ�����ҿ������ַ���ֻ�����ַ�����洢������Ҫ��long long!��
    char name[20];
    char sex;
    int year, month, day;
    char address[100];
} IDcard;

//���֤��Ϣ�Ƚ϶࣬ʹ�ýṹ��ָ�����Ϊ��

bool eqID(IDcard *a, IDcard *b) {
    int i, len = 18;
    for (int i = 0; i < len; i++)	//���ַ��Ƚ�
        if (a->id[i] != b->id[i])	//ֻҪ��һ���ַ�����ȼ����жϲ����
            return false;
    return true;	//�����ַ������
}

bool eqName(IDcard *a, IDcard *b) {
    //�������������ַ��Ƚ�
    int i;
    for (i = 0; a->name[i] != '\0' && a->name[i] != '\0'; i++)
        if (a->name[i] != b->name[i])	//�м����ַ�����ȣ�ֱ���ж�Ϊ����ͬ
            return false;
    if (a->name[i] != '\0' || b->name[i] != '\0' )	//��һ������û�е�ĩβ������ͬ��
        return false;
    else
        return true;

    //Ҳ����ʹ�ñ�׼�⺯�� strcmp������ע�������ַ�����ͬʱ��strcmp �ķ���ֵΪ 0��
    //return (strcmp(a->name, b->name) == 0);
}

bool eqBirth(IDcard *a, IDcard *b) {
    return (a->year == a->year && a->month == b->month && a->day == b->day);
}


bool eqIDcard(IDcard *a, IDcard *b) {
    return (eqID(a, b) && eqName(a, b) && a->sex == b->sex
            && eqBirth(a, b) && strcmp(a->address, b->address) == 0);
}

void printID(IDcard *a) {
    cout << "��ţ�" << a->id << endl;
    cout << "������" << a->name << "\t"
         << "�Ա�" << (a->sex == 'M' ? "��" : "Ů") << endl;
    cout << "�������ڣ�" << a->year << " �� " << a->month << " �� "
         << a->day << " �� " << endl;
    cout << "��ַ��" << a->address << endl;
}

int main() {
    //��ʾ�����ݽ��в���
    IDcard id1 = {"430224198905120057", "����", 'M', 1989, 5, 12,
                  "����ʡ�人�к�ɽ�����·152��"
                 };

    IDcard id2 = {"432522200110030269", "����", 'F', 2001, 10, 3,
                  "����ʡ��ɳ�г�ɳ��������ɼľ����·9��"
                 };//�� id1 ��ͬ

    IDcard id3 = {"430224198905120057", "����", 'M', 1989, 5, 12,
                  "����ʡ�人�к�ɽ�����·152��"
                 }; //�� id1 ��ͬ

    cout << "\nid1 ��Ϣ��\n";
    printID(&id1);

    cout << "\nid2 ��Ϣ��\n";
    printID(&id2);

    cout << "\nid3 ��Ϣ��\n";
    printID(&id3);

    cout << "\n���֤�Ƚ�\n";
    cout << "id1 �� id2 �Ƚϣ���š��������������ڡ��������֤����\n"
         << eqID(&id1, &id2) << "\t" << eqName(&id1, &id2) << "\t"
         << eqBirth(&id1, &id2) << "\t" << eqIDcard(&id1, &id2) << endl;

    cout << "id1 �� id3 �Ƚϣ�\n"
         << eqID(&id1, &id3) << "\t" << eqName(&id1, &id3) << "\t"
         << eqBirth(&id1, &id3) << "\t" << eqIDcard(&id1, &id3) << endl;

    return 0;
}


