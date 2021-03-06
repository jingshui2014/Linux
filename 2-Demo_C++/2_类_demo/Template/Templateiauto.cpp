#include "Templateiauto.h"

namespace nutshell {

NCSyncObj Student::sInstanceSync;
Student*  Student::sInstance = NULL;

Student::Student() {

}

Student::~Student() {

}

Student* Student::instance() {
    NCAutoSync autoSync(s_sync);
    if (NULL == sInstance) {
        sInstance = new Student();
    }
    return sInstance;
}

void Student::destory() {
    NCAutoSync autoSync(s_sync);
    if (NULL != sInstance) {
        sInstance = NULL;
        delete sInstance;
    }
}

void Student::setname(char *name){
    m_name = name;
}`

void Student::setage(int age){
    m_age = age;
}

void Student::setscore(float score){
    m_score = score;
}

void Student::show(){
    cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<endl;
}

int main(){
    //在栈上创建对象
    Student stu;
    stu.setname("小明");
    stu.setage(15);
    stu.setscore(92.5f);
    stu.show();

    //在堆上创建对象
    Student *pstu = new Student;
    pstu -> setname("李华");
    pstu -> setage(16);
    pstu -> setscore(96);
    pstu -> show();
    delete pstu;

    return 0;
}
} // namespace nutshell
