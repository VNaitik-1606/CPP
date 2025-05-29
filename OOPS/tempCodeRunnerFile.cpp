class Student{

    public:
        string name;
        double *cgpaPtr;

        Student(string name, double cgpa){
            this-> name = name;
            cgpaPtr = new double;
            *cgpaPtr = cgpa;
        }

        Student(Student &obj) {
            this->name = obj.name;
            this->cgpaPtr = obj.cgpaPtr; 
        }

        void getInfo(){
            cout << "name: " << name << endl;
            cout << "cgpa: " << *cgpaPtr << endl;
        }
};

int main(int argc, char const *argv[])
{
    Student s1("rahul kumar", 8.9);

    Student s2(s1);
    s2.getInfo();
    return 0;
}