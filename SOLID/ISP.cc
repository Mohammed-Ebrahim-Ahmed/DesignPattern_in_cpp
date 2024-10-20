

// struct Document;
// struct IMachine
// {
//     virtual void print(Document& doc) = 0;
//     virtual void scan(Document& doc) = 0;
//     virtual void fax(Document& doc) = 0;
// };


// struct Scanner : IMachine
// {
//     void print(Document& doc) override {

//     }
//     void scan(Document& doc) override {
//         //ok
//     }

//     void fax(Document& doc) override {

//     }
// };


// struct  IPrinter{
//     virtual void print(Document& doc) = 0;
// };
// struct IFax
// {
//     virtual void fax(Document& doc) = 0;
// };
// struct IScanner{
//     virtual void scan(Document& doc) = 0;
// };

// struct IMachine : IPrinter, IScanner {};

// struct Machine :IMachine {

//     IPrinter& printer;
//     IScanner& scanner;

//     Machine(IPrinter printer, IScanner scanner) : printer{printer}, scanner{scaner}
// };
int main()
{

    return 0;
}