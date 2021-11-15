class MaClass{
    public:
    int a = 1333333;

    int foo();
    int foo(int a);
};

int MaClass::foo(){
    return 2;
}

int MaClass::foo(int a){
    return 2;
}