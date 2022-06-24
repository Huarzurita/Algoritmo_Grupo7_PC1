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
    string code() {
        string res;
        vector<string> alfanumerico = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","Y","Z","1","2","3","4","5","6","7","8","9","0" };

        return res = { alfanumerico[rand() % 35] + alfanumerico[rand() % 35] + alfanumerico[rand() % 35] + alfanumerico[rand() % 35] + alfanumerico[rand() % 35] + alfanumerico[rand() % 35] + alfanumerico[rand() % 35] + alfanumerico[rand() % 35] + alfanumerico[rand() % 35] + alfanumerico[rand() % 35] + alfanumerico[rand() % 35] };

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
    string filename; fstream file;
    Data dat;
public:
    DataGenerator(string filename) : filename(filename) { file.open(filename); }
    ~DataGenerator() { file.close(); }
    void generate(size_t quantity) {
        Random r;
        for (size_t i = 0; i < quantity; ++i)
            file << Person(dat.code(),dat.number(r.Next(1000, 10000)), dat.name(r.Next(0, 100))) << "\n";
    }
    void showAll() {
        Random r;
        string linea;
        file.close();
        file.open("Generador.csv", ios::in);
        Console::ForegroundColor = ConsoleColor(r.Next(1, 16));
        while (!file.eof()) {
            getline(file, linea);
            cout << linea << "\n";
        }
        _getch();
    }
};

