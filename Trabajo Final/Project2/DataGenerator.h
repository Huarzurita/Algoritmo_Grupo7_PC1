#include "Capp.h"
class Data
{
private:
    Data(){}
    long number(long p) { long r; r = p; return r; }
    string name(size_t i) {
        vector<string>res;
        res = { 
          "Isabela Soriano","Claudia Palpán","Carlos Chávez","Sergio Tavara","Aldair Minchola", "Jhon Vereau", "Pedro Rodríguez",
         "Arthur Luan", "Luis Reyes", "Alexander Sechun", "Edson Mendiolaza","Renzo Ramos", "Diego Gonzalez",
        "Alonso García", "Lucas Cubillas", "Frezzia Espinoza", "Luis Sagastegui", "Alonso Robles","Salomon Zegarra",
         "Xiao Li", "Kurt Puican","Jak Campos","Paolo Checa", "Diego Lucana", "Alejandro Pachas",
         "Leonardo Patroccinio", "Leonardo Dueñas", "Jorge Gonzalez", "Leonel Ortega", "Pedro Perez", "Paolo Espejo", "Jhosaim Pocohuanca", 
         "Jorge Orrego","Miguel Huarcaya","Abel Cierto","Jose Montoya","Carmen Orbezo", "Deivis Condezo", "Diana Flores","Fabricio Huilca", 
         "Fabrizzio Castro", "Flavio Castro",  "George Mendez", "Hiro Cardenas", "Jean Carlos Funes", "JeanPool Varillas", "Jhakelin Frynee", "Jhordan Chambi",
         "Johana Jheslin", "John Sovero", "Juliana Flores","Julio Mamani", "Luis Poma", "Luis Espinoza","Marino Sanchez", "Natalia Robles", "Nayeli Vera",
         "Valeria Chavez", "Valeria Diaz", "Valentino Galindo","Valery Ayasta", "Ximena Casola", "Yasser Ladera","Gabriel Rocha","Matias Ascasibe","Eduardo Chero",
         "Alexander Justo","Steven Murillo","Lizbeth Olivera","Janover Saldaña","Brenda Pamo","César Torres","Villegas Peralta","Yamile Izaguirre","Ricardo Tejada",
         "David Roca","Huaman Nilton","Oscar Torres","Sara Estrada","Jefferson Gutierrez","Fabian Munives","Juan Saravia","Jean Paul Galarza","Marcos Olivos","Alexander Motta",
         "Piero Ricaldi","Andrea Gonzalez","Jesslinne Luján","Jessica Comettant","Diego Torres","Juan Porras","Norel Vidaurre","Jorge Cavero","Piero Velarde","Valeria Díaz",
         "André Arroyo","Franciso Guarniz","Maryorith Vera","Aldo Javier","Braulio Jarry","Bruno Javier","Bryan Paul","Camila Rojas","Carlos Fabricio" };
        return res.at(i);
    }
    string code(size_t i) {
       vector<string>res;
       res = { 
           "U20211C009","U20198L002","U20175K888","U20201B779","U20203C995","U20192B777","U20211A880","U20185H779","U20191B759","U20211N590","U20200O999","U20211V770",
           "U20223A457","U20199G339","U20202P001","U20210X574","U20226H322","U20182W700","U20207L614","U20172J854","U2019PP596","U2018QQ147","U20220F532","U20217V214",
           "U202113745","U201715499","U202110085","U202116207","U202014249","U202112662","U201917922","U202118784","U202016643","U20211A950","U20211A184","U202112749",
           "U20201C122","U201917598","U202017075","U202117475","U20211A475","U20211A620","U202118468","U202115733","U20211C231","U20211B786","U202110966","U202114714",
           "U202022237","U201921734","U202017075","U202117475","U202114246","U202110072","U20211C242","U201615124","U202118787","U202111944","U202117912","U202118468",
           "U202115595","U202116567","U20211C984","U20211C464","U202112749","U20181G830","U20211B506","U202118258","U202115382","U20211B786","U202115834","U20201E773"
          ,"U20202F783","U202116552","U202115007","U20190X787","U20228M019","U20223D007","U20188N445","U20187F330","U20214M566","U20179C113","U20227U580","U20172N963",
           "U20210V882","U20171X442","U20182W775","U202212FH0","U20208Y920","U20223O990","U2022CC993","U20189B442","U20210Y718","U20219G773","U20190J662","U20212S563",
           "U20184J590","U20185F369","U20162E989","U20218B545" };
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
            file << Person(dat.code(r.Next(0, 100)),dat.number(r.Next(1000, 10000)), dat.name(r.Next(0, 100))) << "\n";
    }
};

