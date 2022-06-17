#include "Capp.h"
class Data
{
private:
    Data(){}
    long number(long p) { long r; r = p; return r; }
    string name(size_t i) {
        vector<string>res;
        res.push_back("Isabela Soriano"); res.push_back("Claudia Palpán"); res.push_back("Miguel Huarcaya");
        res.push_back("Abel Cierto"); res.push_back("Jose Montoya"); res.push_back("Gabriel Rocha");
        res.push_back("Matias Ascasibe"); res.push_back("Eduardo Chero"); res.push_back("Alexander Justo");
        res.push_back("Steven Murillo"); res.push_back("Lizbeth Olivera"); res.push_back("Janover Saldaña");
        res.push_back("Brenda Pamo"); res.push_back("César Torres"); res.push_back("Villegas Peralta");
        res.push_back("Yamile Izaguirre"); res.push_back("Ricardo Tejada"); res.push_back("David Roca");
        res.push_back("Huaman Nilton"); res.push_back("Oscar Torres"); res.push_back("Sara Estrada");
        res.push_back("Jefferson Gutierrez"); res.push_back("Fabian Munives"); res.push_back("Juan Saravia");
        res.push_back("Jean Paul Galarza"); res.push_back("Marcos Olivos"); res.push_back("Alexander Motta");
        res.push_back("Piero Ricaldi"); res.push_back("Andrea Gonzalez"); res.push_back("Jesslinne Luján");
        res.push_back("Jessica Comettant"); res.push_back("Diego Torres");res.push_back("Juan Porras");
        res.push_back("Norel Vidaurre");res.push_back("Jorge Cavero"); res.push_back("Piero Velarde");
        res.push_back("Valeria Díaz");res.push_back("André Arroyo");res.push_back("Franciso Guarniz");
        res.push_back("Maryorith Vera");
        return res.at(i);
    }
    string code(size_t i) {
       vector<string>res;
        res.push_back("U20211C009"); res.push_back("U20198L002"); res.push_back("U20175K888");
        res.push_back("U20201B779"); res.push_back("U20203C995"); res.push_back("U20192B777");
        res.push_back("U20211A880"); res.push_back("U20185H779"); res.push_back("U20191B759");
        res.push_back("U20211N590"); res.push_back("U20200O999"); res.push_back("U20211V770");
        res.push_back("U20202F783"); res.push_back("U20213Q007"); res.push_back("U20192Z321");
        res.push_back("U20190X787"); res.push_back("U20228M019"); res.push_back("U20223D007");
        res.push_back("U20188N445"); res.push_back("U20187F330"); res.push_back("U20214M566");
        res.push_back("U20179C113"); res.push_back("U20227U580"); res.push_back("U20172N963");
        res.push_back("U20210V882"); res.push_back("U20171X442"); res.push_back("U20182W775");
        res.push_back("U202212FH0"); res.push_back("U20208Y920"); res.push_back("U20223O990");
        res.push_back("U2022CC993"); res.push_back("U20189B442"); res.push_back("U20210Y718");
        res.push_back("U20219G773"); res.push_back("U20190J662"); res.push_back("U20212S563");
        res.push_back("U20184J590"); res.push_back("U20185F369"); res.push_back("U20162E989");
        res.push_back("U20218B545");
        return res.at(i);
    }
    ~Data(){}
    friend class DataGenerator;
};

class Person {
private:
    long number;
    string name,code;
public:
    Person(string code, long number, string name) : code(code), number(number), name(name) {}
    friend ostream& operator<<(ostream& os, Person p) {
        os << p.number << "," << p.code << "," << p.name;
        return os;
    }
};

class DataGenerator {
    string filename; ofstream file;
    Data dat;
public:
    DataGenerator(string filename) : filename(filename) { file.open(filename); }
    ~DataGenerator() { file.close(); }
    void generate(size_t quantity) {
        Random r;
        for (size_t i = 0; i < quantity; ++i)
            file << Person(dat.code(r.Next(0, 40)),dat.number(r.Next(1000, 10000)), dat.name(r.Next(0, 40))) << "\n";
    }
};

