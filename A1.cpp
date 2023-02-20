#include<iostream>
#include<vector>
using namespace std;
struct Person
{
    string name;
    int age;
    string address;
    string education;
};
struct Students
{
    int roll_num;
    Person person;
    string department;
};
struct Course
{
//anything starting with c means course and t means teacher
string cname;
int ccode;
string tname;
int enroll_stud;
int drop_stud;
int graded_stud;
};
struct Teacher
{
    Person person;
    int sal;
    Course course; //note use it to access tname only
};
struct Admin
{
Person person;
int sal; //salary
};
enum Sgrade
{
    A,B,C,D,E,F
};
struct Grade
{
Sgrade sgrade;
int marks;
};
void Hello()
{
    cout<<"***************************\nWelcome to Giki's New LMS\n***************************\n";
}
void stud_count(vector<Students> s)
{
    cout<<"Number of students are "<<s.size()<<endl;
}
void stud_detail_Mod(vector<Students>& s,int i)
{
     cout<<"Student's name\n";
            cin>>s[i].person.name;
            cout<<"Student's age\n";
            cin>>s[i].person.age;
            cout<<"Student's address\n";
            cin>>s[i].person.address;
            cout<<"Student's Education\n";
            cin>>s[i].person.education;
            cout<<"Student's rollnum\n";
            cin>>s[i].roll_num;
            cout<<"Student's department\n";
            cin>>s[i].department;
}
void basic_teach_detail(vector<Teacher> t)
{
     for(int i=0;i<t.size();i++)
            {
            cout<<"S.no "<<i+1<<" "<<t[i].person.name<<endl;
            cout<<"Education level: "<<t[i].person.education<<endl;
            cout<<"\n\n";
            }
}
void admin_teach_detail(vector<Teacher> t)
{
for(int i=0;i<t.size();i++)
{    
cout<<"Name: "<<t[i].person.name<<endl;
cout<<"Age: "<<t[i].person.age<<endl;
cout<<"Address: "<<t[i].person.address<<endl;
cout<<"Education: "<<t[i].person.education<<endl;
cout<<"Salary: "<<t[i].sal<<endl;
}
}
void specific_teach_detail(vector<Teacher> t,int i)
{
cout<<"Name: "<<t[i-1].person.name<<endl;
cout<<"Age: "<<t[i-1].person.age<<endl;
cout<<"Address: "<<t[i-1].person.address<<endl;
cout<<"Education: "<<t[i-1].person.education<<endl;
cout<<"Salary: "<<t[i-1].sal<<endl;

}
void teach_detail_Mod(vector<Teacher>& t,int i)
{
     cout<<"Teacher's name\n";
    cin>>t[i].person.name;
    cout<<"Teacher's age\n";
    cin>>t[i].person.age;
    cout<<"Teacher's address";
    cin>>t[i].person.address;
    cout<<"Teacher's education";
    cin>>t[i].person.education;
    cout<<"Teachers salary\n";
    cin>>t[i].sal;
}
void course_detail_Mod(vector<Course>& c,int i)
{
    cout<<"Course name\n";
    cin>>c[i].cname;
    cout<<"Course code\n";
    cin>>c[i].ccode;
}
void viewcourse_detail(vector<Course> c)
{
    for(int i=0;i<c.size();i++)
        {
            cout<<"Course name: "<<c[i].cname;
            cout<<"Course code: "<<c[i].ccode;
        }
}
void rloop(int& loop)
{
    cout<<"To return press 1, otherwise press anything to repeat\n";
    cin>>loop;
}
int main()
{
Hello();
int opt,num,ssize=0,tsize=0,csize=0,yes=0,mainloop=0;
vector<Admin> a(1);
vector<Students> s(0);
vector<Teacher> t(0);
vector<Course> c(0);
do{
cout<<"If you are Admin press 1, if Teacher press 2 , if Student press 3\n";
cin>>opt;
switch(opt)
{
    do{
    case 1:
    Hello();
    //make sure to check the do while loop for reaccess to the menu
    cout<<"Admin what do you want to do?\n";
    cout<<"1)Add/Remove students\n";
    cout<<"2)View/Update student details\n";
    cout<<"3)Add/Remove teacher\n";
    cout<<"4)View/Update teacher details\n";
    cout<<"5)Add/Remove course\n";
    cout<<"6)View/Update course details\n";
    cout<<"7)Allocate/Deallocate a course to a teacher\nSelect a suitable number\n";
    cin>>num;
    if(num==1)
    {
        int Press,loop=0;
        do{
        cout<<"Press 1 to check the current number of student\n";
        cout<<"Press 2 to add a student\n";
        cout<<"Press 3 to remove a student\n";
        cin>>Press;
        if(Press==1)
        {
            stud_count(s);
        }
        if(Press==2)
        {
            s.resize(ssize+1);
           stud_detail_Mod(s,ssize);
            ssize++;
        }
        if(Press==3)
        {
            //build this functionality later
        }
        cout<<"Press 1 to repeat and press any button to return\n";
        cin>>loop; 
        }while(loop==1);
    }
    if(num==2)
    {
        int Press,loop=0;
        do{
        cout<<"Press 1 to check the current number of students\n";
        cout<<"Press 2 to view student details\n";
        cout<<"Press 3 to update student details\n";
        cin>>Press;
        if(Press==1)
        {
            stud_count(s);
        };
        if(Press==2)
        {
            for(int i=0;i<s.size();i++)
            {
            cout<<"Name: "<<s[i].person.name<<"\n"<<"Age: "<<s[i].person.age<<"\n"<<"Address: "<<s[i].person.address<<"\n"<<"Eduacation level: "<<s[i].person.education;
            cout<<"\n"<<"Roll num: "<<s[i].roll_num<<"\n"<<"Department: "<<s[i].department<<"\n";
            }
        }
        if(Press==3)
        {
            int det;
            cout<<"Which student details do you want to update\n";
            cin>>det;
            stud_detail_Mod(s,det-1);
        }
        cout<<"Press 1 to return or press anything else to repeat\n";
        cin>>loop;
        }while(loop!=1);
    }
    if(num==3)
    {
        int loop=0;
        do{
        int Press;
        cout<<"Press 1 to check the current number of teachers\n";
        cout<<"Press 2 to add a teacher\n";
        cout<<"Press 3 to remove a teacher\n";
        cin>>Press;
        if(Press==1)
        {
            cout<<t.size()<<endl;
        }
        if(Press==2)
        {
            t.resize(tsize+1);
            cout<<"Teacher's name\n";
            cin>>t[tsize].person.name;
            cout<<"Teacher's age\n";
            cin>>t[tsize].person.age;
            cout<<"Teacher's address\n";
            cin>>t[tsize].person.address;
            cout<<"Teacher's education\n";
            cin>>t[tsize].person.education;
            cout<<"Teachers salary\n";
            cin>>t[tsize].sal;
            tsize++;
        }
        if(Press==3)
        {
            t.resize(tsize-1);//visit this later
        }
        cout<<"To return press 1, otherwise press anything to repeat\n";
        cin>>loop;
        }while(loop!=1);
    }
    if(num==4)
    {
        int loop=0;
        do{
        int Press;
        cout<<"Press 1 to check current number of teacher's\n";
        cout<<"Press 2 to view all teacher's details\n";
        cout<<"Press 3 to update teacher's detail\n";
        cin>>Press;
        if(Press==1)
        {
            cout<<t.size()<<endl;
        }
        if(Press==2)
        {
            admin_teach_detail(t);
        }
        if(Press==3)
        {
            int det;
            cout<<"Which teacher's detail do you want to update\n";
            cin>>det;
            teach_detail_Mod(t,det-1);
        }
         cout<<"To return press 1, otherwise press anything to repeat\n";
        cin>>loop;
        }while(loop!=1);

    }
    if(num==5)
    {
        int loop=0;
        do{
        int Press;
        cout<<"Press 1 to view the number of courses\n";
        cout<<"Press 2 to add a course\n";
        cout<<"Press 3 to delete a course\n";
        cin>>Press;
        if(Press==1)
        {
            cout<<c.size()<<endl;
        }
        if(Press==2)
        {
            c.resize(csize+1);
            cout<<"Course name\n";
            cin>>c[csize].cname;
            cout<<"Course code\n";
            cin>>c[csize].ccode;
            csize++;
        }
        if(Press==3)
        {
            //come here later
            csize--;
        }
        rloop(loop);
        }while(loop!=1);
    }
    if(num==6)
    {
        int loop=0;
        do{
        int Press;
        cout<<"Press 1 to view all course details\n";
        cout<<"Press 2 to update course details\n";
        cin>>Press;
        if(Press==1)
        {
        for(int i=0;i<c.size();i++)
        {
            cout<<"S.NO "<<i+1<<endl;
            cout<<"Course name: "<<c[i].cname<<endl;
            cout<<"Course code: "<<c[i].ccode<<endl;
            cout<<"Allocated to: "<<t[i].course.tname<<endl;
        }
        }
        if(Press==2)
        {
            int det;
            cout<<"Which course do you want to update(enter its code)\n";
            cin>>det;
            course_detail_Mod(c,det-1);
        }
        rloop(loop);
        }while(loop!=1);
    }
    if(num==7)
    {
        int loop=0;
        do{
        int Press;
        cout<<"Press 1 to view all courses and the teachers available\n";
        cout<<"Press 2 to allocate a course\n";
        cout<<"Press 3 to deallocate a course\n";
        cin>>Press;
        if(Press==1)
        {
            viewcourse_detail(c);
            cout<<endl;
            for(int i=0;i<t.size();i++)
            {
            cout<<t[i].person.name<<"\n";
            }

        }
        if(Press==2)
        {
            int j,k;
            cout<<"Which course do you want to allocate, enter its serial number\n";
            cin>>j;
            cout<<"Which teacher do you want to allocate, enter in their serial order\n";
            cin>>k;
            t[k-1].course.tname=t[k-1].person.name;
            t[k-1].course.cname=c[j-1].cname;
            cout<<"You have allocated "<<t[k-1].course.cname<<" to "<<t[k-1].course.tname<<endl;
        }
        if(Press==3)
        {
            int j;
            cout<<"Which teacher do you want to deallocate from a course, enter its serial number\n";
            cin>>j;
            t[j-1].course.tname.erase();
            t[j-1].course.cname.erase();
            cout<<"Successfully dealloacted\n";
        }
        rloop(loop);
        }while(loop!=1);
    }
    cout<<"Press 1 to return to main menu,otherwise press anything else to repeat current menu";
    cin>>yes;
    }while(yes!=1);
    break;
    case 2:
    Hello();
    int tnum,tsnum,tpress;
    cout<<"Hello Sir/Madam can you please enter your S.no, to check your S.no and basic details press 1 and to enter your S.no press 2\n";
    cin>>tnum; //teachernumber
    if(tnum==1)
    {
        basic_teach_detail(t);
    }
    if(tnum==2)
    {
        cout<<"Your serial number:\n";
        cin>>tsnum;//teacherserialnumber
        cout<<"Hello Professor "<<t[tsnum-1].person.name<<endl;
        cout<<"1)Your details\n";
        cout<<"2)Courses allocated to you\n";
        cout<<"3)Students enrolled in your courses\n";
        cout<<"4)Assign marks and grades\n";
        cout<<"5)See the top students of your class\n";
        cout<<"6)Grade wise divison of students in your class\n";
        cout<<"Enter the number respective to your option\n";
        cin>>tpress; //teacher press
        if(tpress==1)
        {
            specific_teach_detail(t,tsnum);
        }
        if(tpress==2)
        {
            for(int i=0;i<t.size();i++)
            cout<<"You have been allocated: "<<t[tsnum-1].course.cname;
        }
    }
}
}while(true);
    return 0;
}