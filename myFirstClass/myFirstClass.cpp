using namespace std;

class myClass {
private:
    int privateValue;

public:
    int publicValue;

    void publicFunction() {

    }
};

int main() {
    myClass obj;

    obj.publicValue = 10;

    obj.publicFunction();

    return 0;
}