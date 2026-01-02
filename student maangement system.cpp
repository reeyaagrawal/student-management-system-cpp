//Project on Student Management System
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class student{
    public:
    int rollNo;
    int age;
    string name;
    void stuDetail(){
        // cin.ignore();
        cout<<"enter name: ";
        getline(cin,name);
        cout<<"Enter Roll no: ";
        cin>>rollNo;
        cout<<"Enter Age:";
        cin>>age;
    }
    void display(){
        cout<<"\nName: "<<name;
        cout<<"\nRoll no: "<<rollNo;
        cout<<"\nAge: "<<age;
    }
};
class subject{
    public:
    int sub;
    vector<string> subj;

    void noOfSub(){
        cout<<"enter number of subjects: ";
        cin>>sub;
        cin.ignore();//to clear the buffer
        subj.resize(sub);

        for(int i=0;i<sub;i++){
            cout<<"Enter name of the subject "<<i+1<<": ";
            getline(cin,subj[i]);
        }

    }   
};
class operation{
    public:
    student s1;
    // s1.stuDetail();
    subject s;
    // s.noOfSub();
    vector <int> marks;

    void getMarks(){
        marks.resize(s.sub);//subj storing nmae of subject
        for(int i=0;i<s.sub;i++){//sub storing no of subject
        cout<<"enter marks of  "<<s.subj[i]<<" :";
        cin>>marks[i];
    }
    }
    void totalMarks(){
        int sum=0;
        for(int i=0;i<s.sub;i++){
            sum+=marks[i];
        }
        float avg=(float)sum/s.sub;
        float percent=(float)sum/(s.sub*100)*100;
        cout<<"Your total marks are: "<<sum;
        cout<<"\nYour average marks are: "<<avg;
        cout<<"\nYour percentage is : "<<percent<<"%";
        if(percent>=33){
            cout<<"\nPASS";
        }else{
            cout<<"\nFAIL";
        }
        cout<<endl;
    }
    
};
int main(){
    cout<<"---Student Managemant System---\n";
    int choice;
    vector<operation>record;
    do{
        cout<<"\n1.Add student ";
        cout<<"\n2.View records ";
        cout<<"\n3.Exit ";
        cout<<"\nEnter choice: ";
        cin>>choice;
        if(choice==1){
            operation o1;
            cin.ignore();
            o1.s1.stuDetail();//to print details of student
            o1.s.noOfSub();//to print subject details
            o1.getMarks();//to get marks of each subject
            record.push_back(o1);
        }
        else if(choice==2){
            for(int i=0;i<record.size();i++){
                cout<<"\nStudent"<<i+1<<endl;
                record[i].s1.display();
                record[i].totalMarks();
            }
        }else if(choice==3){
            cout<<"Exiting Student Management System";
        }
    }while (choice!=3);
    return 0;
}